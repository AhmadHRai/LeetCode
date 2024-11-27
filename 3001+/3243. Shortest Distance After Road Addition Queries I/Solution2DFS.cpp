class Solution {
    // Helper function to update distances using DFS
    void updateDistances(vector<vector<int>>& graph, int current, vector<int>& distances) {
        // Calculate the new distance for the current node
        int newDist = distances[current] + 1;
        // Iterate over all neighbors of the current node
        for (int neighbor : graph[current]) {
            // If the neighbor's distance is already less than or equal to the new distance, skip it
            if (distances[neighbor] <= newDist) continue;
            // Update the neighbor's distance with the new calculated distance
            distances[neighbor] = newDist;
            // Recursively update distances for the neighbor
            updateDistances(graph, neighbor, distances);
        }
    }

public:
    // Main function to compute shortest distances after each query
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        // Initialize distances array where distances[i] is set to n - 1 - i (maximum possible distance)
        vector<int> distances(n);
        for (int i = 0; i < n; ++i) {
            distances[i] = n - 1 - i; // Maximum distance from city 0 to city i if no roads exist
        }
        
        // Initialize adjacency list for the graph representation
        vector<vector<int>> graph(n);
        // Create initial edges from each city to its previous city
        for (int i = 0; i + 1 < n; ++i) {
            graph[i + 1].push_back(i); // Connect city i+1 to city i
        }
        
        // Vector to store the result of shortest distances after each query
        vector<int> answer(queries.size());
        int queryIdx = 0; // Index to track position in answer array
        
        // Process each query one by one
        for (const auto& query : queries) {
            int source = query[0]; // Starting city of the new road
            int target = query[1]; // Target city of the new road
            
            // Add a directed edge from target to source in the graph
            graph[target].push_back(source);
            // Update the distance for the source city based on its connection to target
            distances[source] = min(distances[source], distances[target] + 1);
            // Update distances using DFS starting from the source city
            updateDistances(graph, source, distances);
            
            // Store the shortest distance from city 0 after processing this query
            answer[queryIdx++] = distances[0];
        }
        
        // Return the final results after processing all queries
        return answer;
    }
};

/*
Approach:
The solution utilizes a depth-first search (DFS) strategy to dynamically update shortest distances from city 0 to all other cities in a directed graph. Each query introduces a new road (directed edge) between two cities, and the algorithm updates the shortest paths accordingly.

1. **Initialization**: 
   - The `distances` vector is initialized such that `distances[i] = n - 1 - i`, representing maximum possible distances from city 0.
   - The `graph` is initialized with edges connecting each city to its previous city.

2. **Processing Queries**: 
   - For each query:
     - A new road is added from `target` to `source`.
     - The distance for `source` is updated based on its connection to `target`.
     - The `updateDistances` function is called recursively to propagate any necessary updates through connected cities.

3. **Result Compilation**: 
   - After processing each query, the current shortest distance from city 0 is stored in the `answer` vector.

Complexity Analysis:
- Time Complexity: O(m * (n + e)), where m is the number of queries, n is the number of cities, and e is the average number of edges. Each query may require traversing a portion of the graph, leading to potentially deep recursive calls.
- Space Complexity: O(n + e), where n is the number of cities and e is the total number of edges in the graph representation. The `distances` vector also requires O(n) space.

Runtime: 19 ms
Memory: 51.9 MB
*/
