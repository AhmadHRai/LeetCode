class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        // `cityConnections` holds the roads between cities.
        vector<vector<int>> cityConnections(n);
        
        // `distances` will store the minimum distance to reach each city from city 0.
        vector<int> distances(n);
        
        // Initialize `distances` such that distances[i] = i.
        iota(distances.begin(), distances.end(), 0);
        
        // Result vector to store the shortest distance from city 0 to city n-1 after each query.
        vector<int> result;

        // Process each query one by one
        for (const auto& query : queries) {
            int fromCity = query[0];
            int toCity = query[1];
            
            // Add the new road to the cityConnections list.
            cityConnections[toCity].push_back(fromCity);
            
            // Update the distances from city 0 for each city.
            for (int city = toCity; city < n; ++city) {
                // First, try the previous distance plus 1 (moving from city-1 to city)
                distances[city] = min(distances[city], distances[city - 1] + 1);

                // Then, consider any new direct roads from cities leading to the current city.
                for (int prevCity : cityConnections[city]) {
                    distances[city] = min(distances[city], distances[prevCity] + 1);
                }
            }

            // After processing the query, add the shortest distance to the last city (city n-1) to the result.
            result.push_back(distances[n - 1]);
        }
        
        // Return the final result array after processing all queries.
        return result;
    }
};

/*
Approach:
The solution uses a dynamic programming approach to maintain the shortest distances from city 0 to all other cities in a graph represented by city connections. The algorithm processes each query, which adds a new road (directed edge) between two cities. For each query, it updates the distances for all cities from the newly connected city to the last city (city n-1). 

1. **Initialization**: The `distances` vector is initialized such that `distances[i] = i`, representing the maximum distance if traveling directly from city 0 to city i without any roads.
2. **Processing Queries**: For each query:
   - A new road is added to the `cityConnections` list.
   - The distances for all cities from `toCity` to `n-1` are updated:
     - First, it checks if moving from the previous city (city-1) offers a shorter path.
     - Then, it checks if any new direct roads from previously connected cities provide a shorter path to the current city.
3. **Result Compilation**: After updating distances for each query, the shortest distance to city n-1 is appended to the result vector.

Complexity Analysis:
- Time Complexity: O(m * n), where m is the number of queries and n is the number of cities. For each query, we potentially update distances for all cities from `toCity` to `n-1`.
- Space Complexity: O(n + e), where n is the number of cities and e is the total number of roads stored in `cityConnections`. The `distances` vector also requires O(n) space.


Runtime: 38 ms
Memory: 51.9 MB
*/
