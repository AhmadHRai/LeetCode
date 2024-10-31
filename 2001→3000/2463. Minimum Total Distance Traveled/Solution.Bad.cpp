class Solution {
private:
    long long maxi = 1e16; // A large value to represent an unreachable state in DP

    // Recursive function to calculate the minimum distance
    long long f(int i, int j, vector<int>& robot, vector<int>& v, vector<vector<long long>>& dp) {
        // Base case: if all robots have been assigned
        if (i == robot.size()) return 0;
        // Base case: if all factory positions have been exhausted
        if (j == v.size()) return maxi;
        // Return memoized result if already computed
        if (dp[i][j] != -1) return dp[i][j];

        // Option 1: Assign the current robot to the current factory
        long long take = abs(robot[i] - v[j]) + f(i + 1, j + 1, robot, v, dp);
        // Option 2: Skip the current factory
        long long not_take = f(i, j + 1, robot, v, dp);

        // Store and return the minimum distance
        return dp[i][j] = min(take, not_take);
    }

public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        // Sort the robot positions and factory positions
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int> v; // Vector to store the factory positions with their capacities
        // Fill the vector with factory positions according to their capacities
        for (auto i : factory) {
            int x = i[0], y = i[1]; // x: factory position, y: capacity
            for (int i = 0; i < y; i++) {
                v.push_back(x); // Add factory position y times
            }
        }

        // DP table initialized with -1 (uncomputed state)
        vector<vector<long long>> dp(robot.size() + 1, vector<long long>(v.size() + 1, -1));
        // Call the recursive function to compute the result
        return f(0, 0, robot, v, dp);
    }
};

/*
Approach:

    The solution employs a recursive dynamic programming approach to minimize the total distance between robots and factories. 
    Robots and factory positions are sorted, and the factories are expanded according to their capacity. The recursive function `f` calculates 
    the minimum distance for each robot starting from the given factory position. It considers two choices for each robot: 
    either assigning it to the current factory or skipping the factory. The results are memoized in a DP table to avoid redundant calculations.

Complexity:

    Time Complexity: O(R * F), where R is the number of robots and F is the number of factory positions after considering capacities. 
    The recursion explores every combination of robots and factories, resulting in a polynomial complexity due to the DP memoization.

    Space Complexity: O(R + F) for the DP table and additional space used for storing factory positions.
    
This approach efficiently computes the minimum total distance for robot assignments while ensuring that the solution scales well with input sizes.
*/
