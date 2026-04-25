class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> res;
        for (auto& p : points) {
            int x = p[0], y = p[1];
            if (x == 0) res.push_back(y);
            else if (y == side)
                res.push_back((long long)side + x);
            else if (x == side)
                res.push_back((long long)side * 3 - y);
            else res.push_back((long long)side * 4 - x);
        }
        sort(res.begin(), res.end());

        auto check = [&](int n) {
            int m = res.size();
            vector<int> idx(k);
            long long curr = res[0];
            idx[0] = 0;
            for (int i = 1; i < k; i++) {
                auto it = lower_bound(res.begin(), res.end(), curr + n);
                if (it == res.end())
                    return false;
                idx[i] = distance(res.begin(), it);
                curr = *it;
            }
            if (res[idx[k - 1]] - res[0] <= (long long)side * 4 - n)
                return true;

            for (idx[0] = 1; idx[0] < idx[1]; idx[0]++) {
                for (int j = 1; j < k; j++) {
                    while (idx[j] < m && res[idx[j]] < res[idx[j - 1]] + n) {
                        idx[j]++;
                    }
                    if (idx[j] == m)
                        return false;
                }
                if (res[idx[k - 1]] - res[idx[0]] <= (long long)side * 4 - n)
                    return true;
            }
            return false;
        };

        int left = 1;
        int right = (1LL * side * 4) / k + 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (check(mid))
                left = mid;
            else right = mid;
        }
        return left;
    }
};
