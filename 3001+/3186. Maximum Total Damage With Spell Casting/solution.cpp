class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int, int> count;
        for (int p : power) {
            count[p]++;
        }
        vector<pair<int, int>> vec = {{-1e9, 0}};
        for (auto& p : count) {
            vec.push_back(p);
        }
        int n = vec.size();
        vector<long long> f(n, 0);
        long long mx = 0;
        for (int i = 1, j = 1; i < n; i++) {
            while (j < i && vec[j].first < vec[i].first - 2) {
                mx = max(mx, f[j]);
                j++;
            }
            f[i] = mx + 1LL * vec[i].first * vec[i].second;
        }
        long long ans = 0;
        for (int i = 1; i < n; i++) {
            ans = max(ans, f[i]);
        }
        return ans;
    }
};