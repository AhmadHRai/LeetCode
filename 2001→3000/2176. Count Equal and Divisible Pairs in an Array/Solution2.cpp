class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int pairs = 0;
        unordered_map<int, vector<int>> mpp;
        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]].push_back(i);
        }
        vector<int> divisors;
        for (int d = 1; d * d <= k; d++) {
            if (k % d == 0) {
                divisors.push_back(d);
                if (d != k / d) {
                    divisors.push_back(k / d);
                }
            }
        }
        for (auto& [key, vec] : mpp) {
            unordered_map<int, int> mpp2;
            for (int i : vec) {
                int gcdd = gcd(i, k);
                int need = k / gcdd;
                pairs += mpp2[need];
                for (int d : divisors) {
                    if (i % d == 0)
                        mpp2[d]++;
                }
            }
        }
        return pairs;
    }
};