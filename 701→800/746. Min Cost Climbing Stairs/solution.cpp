class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // The idea is to use dynamic programming to find the minimum cost at each step
        // We can either start from the first or the second step, so we initialize the first two costs as cost[0] and cost[1]
        // For each subsequent step, we can either come from the previous step or the one before that
        // So we choose the minimum of those two options and add the current cost
        // We store the minimum costs in a vector called dp
        int n = cost.size(); // The number of steps
        vector<int> dp(n); // The vector to store the minimum costs
        dp[0] = cost[0]; // The minimum cost to reach the first step is cost[0]
        dp[1] = cost[1]; // The minimum cost to reach the second step is cost[1]
        for (int i = 2; i < n; i++) { // Loop from the third step to the last step
            dp[i] = min(dp[i-1], dp[i-2]) + cost[i]; // The minimum cost to reach the current step is the minimum of the previous two steps plus the current cost
        }
        // To reach the top of the floor, we can either come from the last step or the second last step
        // So we return the minimum of those two options as the final answer
        return min(dp[n-1], dp[n-2]);
    }
};

/* 
The time complexity of this solution is O(n), where n is the number of steps, since we loop through the cost vector once and do constant operations at each step.

The space complexity of this solution is O(n), where n is the number of steps, since we use a vector of size n to store the minimum costs.
 */