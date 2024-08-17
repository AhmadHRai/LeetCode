class Solution {
public:
    // Function to compute the maximum points achievable with specific constraints
    long long maxPoints(vector<vector<int>>& points) {
        // Initialize a 2D dp vector to store maximum points up to each cell, with -1 as initial value
        vector<vector<long long>> dp(points.size(), vector<long long>(points[0].size(), -1));
        
        // Set the first row of dp to be equal to the first row of points
        for (int i = 0; i < points[0].size(); ++i) {
            dp[0][i] = points[0][i];
        }
        
        // Process each row starting from the second one
        for (int i = 1; i < points.size(); ++i) {
            // Initialize left_dp and right_dp vectors for current row, with -1 as initial value
            vector<long long> left_dp(points[i].size(), -1);
            vector<long long> right_dp(points[i].size(), -1);
            
            // Compute left_dp values for the current row
            left_dp[0] = dp[i - 1][0];
            for (int k = 1; k < points[i].size(); ++k) {
                left_dp[k] = max(left_dp[k - 1], dp[i - 1][k] + k);
            }
            
            // Compute right_dp values for the current row
            right_dp.back() = dp[i - 1].back() - points[i].size() + 1;
            for (int k = points[i].size() - 2; k >= 0; --k) {
                right_dp[k] = max(right_dp[k + 1], dp[i - 1][k] - k);
            }
            
            // Compute dp values for the current row using left_dp and right_dp
            for (int j = 0; j < points[i].size(); ++j) {
                dp[i][j] = max(left_dp[j] - j, right_dp[j] + j) + points[i][j];
            }
        }
        
        // Find the maximum value in the last row of dp
        long long max_ans = -1;
        for (const auto v : dp.back()) {
            max_ans = max(max_ans, v);
        }
        
        // Return the maximum points achievable
        return max_ans;
    }
};

/*
Approach Summary:
- Use dynamic programming to keep track of the maximum points achievable up to each cell.
- Initialize the dp table with values from the first row of the points matrix.
- For each subsequent row:
  - Compute maximum points for cells to the left and right, adjusting for column indices.
  - Update the dp table for the current row based on left and right maximum points.
- Finally, find the maximum value in the last row of the dp table.

Time Complexity:
- O(m * n), where m is the number of rows and n is the number of columns in the points matrix, as each cell is processed a constant number of times.

Space Complexity:
- O(m * n), due to the additional space used by the dp, left_dp, and right_dp vectors.
*/
