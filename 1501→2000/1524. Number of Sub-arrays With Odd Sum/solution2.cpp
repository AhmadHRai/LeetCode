const long long M = 1e9 + 7;
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size(), sm = 0, os = 0, es = 0;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            sm += arr[i];
            if (sm % 2) {
                ans += es + 1;
                os++;
            } else {
                ans += os;
                es++;
            }
            ans %= M;
        }
        return ans;
    }
};
