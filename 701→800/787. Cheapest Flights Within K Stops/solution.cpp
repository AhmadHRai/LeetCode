class Solution
{
public:
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K)
    {        
        // Initialize a  2D DP array with dimensions (K+2)x(n) filled with INT_MAX
        // This is because we need to account for the possibility of not making any stops (K=0) and the possibility of exceeding the limit (K+1).
        vector<vector<int>> dp(K+2, vector<int>(n, INT_MAX));
        
        // dp[i][j] represents the minimum cost to reach node j using at most i edges from the source node.
        
        // Initialize the source node (src) to have a cost of  0 for all i (from  0 to K+1)
        for(int i =  0; i <= K+1; i++)
        {
            dp[i][src] =  0; // Dist to reach src always zero
        }
        
        // For each possible number of stops (from  1 to K+1)
        for(int i =  1; i <= K+1; i++)
        {
            // For each flight
            for(auto &f: flights)
            {
                // Extract the source (u), destination (v), and cost (w) of the flight
                int u = f[0];
                int v = f[1];
                int w = f[2];
                
                // If it's possible to reach u using i-1 stops (i.e., dp[i-1][u] is not INT_MAX)
                if(dp[i-1][u] != INT_MAX)
                    // Update the cost to reach v using i stops by taking the minimum of the current cost and the cost of reaching u plus the cost of the flight from u to v
                    dp[i][v] = min(dp[i][v], dp[i-1][u] + w);
            }
        }
        
        // Return the minimum cost to reach the destination (dst) using at most K stops, or -1 if it's not possible.
        return (dp[K+1][dst] == INT_MAX)? -1: dp[K+1][dst];
    }
};


/* 
Approach:

We use a dynamic programming approach to solve the problem. The idea is to use a 2D DP array dp where dp[i][j] represents the minimum cost to reach node j using at most i stops from 
the source node. The approach iterates over all possible numbers of stops (from 1 to K+1) and for each stop, it updates the DP array based on the flights available.

    Initialization: The DP array is initialized with INT_MAX for all nodes except the source node, which is set to 0. This is because reaching the source node itself requires 0 cost.

    Iteration: For each possible number of stops, the code iterates over all flights. If it's possible to reach the source of a flight (u) using i-1 stops, it updates the cost to reach the destination of the flight (v) using i stops by taking the minimum of the current cost and the cost of reaching u plus the cost of the flight.

    Final Answer: After all iterations, the code returns the minimum cost to reach the destination using at most K stops. If it's not possible to reach the destination within K stops, it returns -1.

Time and Space Complexity Analysis

    Time Complexity: The time complexity is primarily determined by the number of stops and the number of flights. Since the code iterates over all possible numbers of stops (from 1 to K+1) and for each stop, it iterates over all flights, the worst-case time complexity is O(K * F), where F is the number of flights.

    Space Complexity: The space complexity is determined by the size of the DP array. Since the DP array is a 2D array with dimensions (K+2)x(n), where n is the number of nodes, the space complexity is O(K * n).

This approach is efficient for solving the problem within the given constraints, as it systematically explores all possible paths with a maximum number of stops and keeps track of the minimum cost for each node and number of stops.
 */