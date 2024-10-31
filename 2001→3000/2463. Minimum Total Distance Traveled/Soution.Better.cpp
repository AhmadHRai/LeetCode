class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int n = robot.size(); // Number of robots
        int m = factory.size(); // Number of factories
        vector<long long> dp(n + 1, 10e12); // DP array to store minimum distances, initialized to a large number
        dp[0] = 0; // Base case: no robots assigned means zero distance

        // Sort robots and factory positions
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        // Iterate over each factory
        for (int i = 0; i < m; i++) {
            int position = factory[i][0]; // Get factory position
            int limit = factory[i][1]; // Get factory capacity

            // For each factory, allow assignment of its capacity
            while (limit--) {
                // Update the DP array in reverse to avoid overwriting values in the same iteration
                for (int j = n - 1; j >= 0; j--) {
                    // Update the minimum distance if assigning the current robot to this factory
                    dp[j + 1] = min(dp[j + 1], abs(robot[j] - position) + dp[j]);
                }
            }
        }

        // Return the minimum total distance for all robots
        return dp[n];
    }
};

/*
Approach:

    This solution utilizes a dynamic programming approach to compute the minimum total distance for assigning robots to factories. 
    The `dp` array is used to store the minimum distance for assigning the first `j` robots. The robots and factories are sorted 
    to facilitate the calculation. For each factory, the algorithm iterates based on its capacity and updates the `dp` array, 
    taking into account the distance of each robot to the factory position. The final answer is stored in `dp[n]`, representing 
    the minimum distance for all robots.

Complexity:

    Time Complexity: O(n * m), where `n` is the number of robots and `m` is the number of factories. The nested loop structure results in a polynomial time complexity.

    Space Complexity: O(n), as only a single array `dp` of size `n + 1` is maintained to keep track of the minimum distances.
    
This approach ensures efficient computation of the minimum distance required for robot assignments while adhering to the constraints of the problem.
*/
