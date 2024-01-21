class Solution {
public:
    // This function takes a vector of integers representing the amount of money in each house and returns the maximum amount of money that can be robbed without robbing two adjacent houses
    int rob(vector<int>& nums) {
        // If the vector is empty, return 0 as the base case
        if(nums.size()==0)return 0;
        // Get the size of the vector
        int n=nums.size();
        // Create a vector of size n+1 to store the maximum amount of money that can be robbed from the first i houses for each i from 0 to n
        vector<int> dp(n+1,0);
        // Initialize the first element of the vector as the amount of money in the first house
        dp[1]=nums[0];
        // Loop over the vector from the second element
        for(int i=2;i<=n;i++){
            // Calculate the maximum amount of money that can be robbed from the first i houses as the maximum of two options:
            // 1. Rob the i-th house and the maximum amount of money that can be robbed from the first i-2 houses
            // 2. Do not rob the i-th house and the maximum amount of money that can be robbed from the first i-1 houses
            dp[i]=max(dp[i-1],dp[i-2]+nums[i-1]);
        }
        // Return the last element of the vector as the answer
        return dp[n];
    }
};

/* 
The code uses a dynamic programming approach to solve the problem of house robber. Dynamic programming is a technique that breaks down a complex problem into smaller subproblems 
and stores the results of the subproblems to avoid recomputation. The code uses a vector to store the results of the subproblems, which are the maximum amount of money that can 
be robbed from the first i houses for each i from 0 to n. The vector is initialized with the base cases, which are 0 and the amount of money in the first house. The code uses a 
loop to fill the vector with the results of the subproblems, which are calculated by comparing two options: robbing or not robbing the current house. The code returns the last 
element of the vector as the final answer, which is the maximum amount of money that can be robbed from all the houses.

The time and space complexity of the code are as follows:

    The time complexity is O(n), where n is the size of the input vector. This is because the code uses a loop to iterate over the vector of size n, and performs constant-time 
    operations in each iteration.

    The space complexity is O(n), because the code uses a vector of size n to store the results of the subproblems.
*/

