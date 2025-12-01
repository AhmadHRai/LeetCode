class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(), batteries.end());

        long long extra = 0;
        for (int i = 0; i < batteries.size() - n; i++) {
            extra += batteries[i];
        }

        vector<int> live(batteries.end() - n, batteries.end());

        for (int i = 0; i < n - 1; i++) {
            if (extra < (long long)(i + 1) * (live[i + 1] - live[i])) {
                return live[i] + extra / (long long)(i + 1);
            }

            extra -= (long long)(i + 1) * (live[i + 1] - live[i]);
        }

        return live[n - 1] + extra / n;
    }
};
