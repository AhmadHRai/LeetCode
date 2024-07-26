class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Initialize the distance matrix with large values (10001, assuming this is larger than any possible path length)
        vector<vector<int>> dis(n, vector<int>(n, 10001));
        
        // Set the distance from each city to itself to 0
        for (int i = 0; i < n; ++i)
            dis[i][i] = 0;
        
        // Populate the distance matrix with given edge weights
        for (auto& e : edges)
            dis[e[0]][e[1]] = dis[e[1]][e[0]] = e[2];
        
        // Apply the Floyd-Warshall algorithm to compute the shortest paths between all pairs of cities
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        
        // Find the city with the smallest number of reachable cities within the distanceThreshold
        int res = 0, smallest = n;  // Initialize with the first city and maximum number of cities
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; ++j)
                if (dis[i][j] <= distanceThreshold)
                    ++count;
            // Update the result if the current city has the smallest number of reachable cities
            if (count <= smallest) {
                res = i;
                smallest = count;
            }
        }
        
        return res;
    }
};

/*
Approach

    1. **Initialize Distance Matrix**:
       - Create a 2D matrix `dis` to store distances between cities. Initialize with a large value (10001) for all pairs except the diagonal (self-distances).

    2. **Populate Distance Matrix**:
       - Set the distances between directly connected cities based on the given edges.

    3. **Compute Shortest Paths**:
       - Use the Floyd-Warshall algorithm to compute shortest paths between all pairs of cities. This involves three nested loops to update distances iteratively.

    4. **Find the City with Fewest Reachable Cities**:
       - Iterate through each city and count how many cities are reachable within the `distanceThreshold`. Track the city with the smallest count. If there are ties, the city with the largest index is preferred.

Complexity

    Time complexity: O(n^3), where n is the number of cities. This is due to the three nested loops required for the Floyd-Warshall algorithm.
    
    Space complexity: O(n^2), for storing the distance matrix.

This solution efficiently finds the city with the fewest number of cities reachable within a given distance threshold by leveraging the Floyd-Warshall algorithm to compute shortest paths.
*/
