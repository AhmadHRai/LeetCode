class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();

        vector<int> dp(n,1);
        vector<int> prev_idx(n,-1);

        int last_chosen_idx = 0;
        int maxlen = 1;

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j] == 0){
                    if(dp[i] < 1 +dp[j]){
                        dp[i] = 1 + dp[j];
                        prev_idx[i] = j;
                    }

                    if(maxlen < dp[i]){
                        maxlen = dp[i];
                        last_chosen_idx = i;
                    }
                }
            }
        }


        vector<int> ans;
        while(last_chosen_idx != -1){
            ans.push_back(nums[last_chosen_idx]);
            last_chosen_idx = prev_idx[last_chosen_idx];
        }
        return ans;
    }
};