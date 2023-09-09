class Solution {
public:
int combinationSum4(vector<int>& nums, int target) {
        
        vector<int> dp (target+1, 0); //STORE THE NO OF WAYS IN WHICH WE GET ith INDEX SUM;
        dp[0] = 1;
        long long mod = 1e18 + 7;
        for(int i = 1; i <= target; i++)
        {
            for(int j = 0; j < nums.size(); j++)
            {
                if(i - nums[j] >= 0) //IF INDEX IS PRESENT i.e. INDEX SHOULD BE GREATER THAN OR EQUAL TO 0.
                    dp[i] = (1ll*dp[i] + dp[i - nums[j]])%mod;
            }
        }
        return dp[target];
    }
};

/* 
    Time Complexity: O(target * nums.length)
    Space Complexity: O(target)
 */