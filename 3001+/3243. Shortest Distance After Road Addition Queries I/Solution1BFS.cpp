class Solution {
public:
    // Function to find the shortest distance after processing each query
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        // Create an adjacency list to represent the graph
        vector<vector<int>> adj(n);
        // Initialize the adjacency list so that each node points to its next node
        for (int i = 0; i < n; i++) {
            adj[i].push_back(i + 1);
        }
        
        // Lambda function to perform BFS and find the shortest path from node 0 to node n-1
        auto shortest_path = [&]() {
            queue<pair<int, int>> q; // Queue to hold pairs of (node, length)
            q.push({0, 0}); // Start from node 0 with length 0
            unordered_set<int> visit; // Set to track visited nodes
            visit.insert(0); // Mark the starting node as visited
            
            // Perform BFS until the queue is empty
            while (!q.empty()) {
                auto [cur, length] = q.front(); // Get the current node and its path length
                q.pop(); // Remove the current node from the queue
                
                // If we reach the last node, return the length of the path
                if (cur == n - 1) return length;
                
                // Explore all neighbors of the current node
                for (int neighbor : adj[cur]) {
                    // If the neighbor hasn't been visited yet
                    if (visit.find(neighbor) == visit.end()) {
                        q.push({neighbor, length + 1}); // Add it to the queue with incremented length
                        visit.insert(neighbor); // Mark it as visited
                    }
                }
            }
            return -1; // Return -1 if there is no path to the last node
        };
        
        vector<int> res; // Vector to store results for each query
        // Process each query
        for (const auto& query : queries) {
            adj[query[0]].push_back(query[1]); // Add a new edge based on the query
            res.push_back(shortest_path()); // Calculate shortest path after adding edge and store result
        }
        return res; // Return all results after processing all queries
    }
};

/*
Approach:
The solution utilizes a Breadth-First Search (BFS) algorithm to find the shortest distance from node 0 to node n-1 in a dynamically updated graph. Each query adds a new directed edge between two nodes, and after each addition, BFS is employed to compute the shortest distance.

Complexity Analysis:
- Time Complexity: O(m * (n + e)), where m is the number of queries, n is the number of nodes, and e is the average number of edges per node. In the worst case, we may need to traverse all nodes and edges for each query.
- Space Complexity: O(n + e), where n is the number of nodes and e is the number of edges in the adjacency list representation.

Runtime: 807 ms
Memory: 330.4 MB
*/
