class Solution {
public:
    bool check(int n, vector<int>& v, long long mid) {
        int count = 0;
        long long sum = 0;
        for (int i = 0; i < v.size(); i++) {
            if (sum + v[i] >= mid) {
                sum += v[i] - mid;
                count++;
            } else
                sum += v[i];
        }
        return count >= n;
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(), batteries.end());

        long long l = 0;
        long long h = 1e18;
        long long ans = 0;

        while (l <= h) {
            long long mid = l + (h - l) / 2;
            if (check(n, batteries, mid)) {
                ans = mid;
                l = mid + 1;
            } else
                h = mid - 1;
        }
        return ans;
    }
};
