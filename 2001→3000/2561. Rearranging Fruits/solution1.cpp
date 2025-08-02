class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int n = basket1.size();
        auto& u = basket1;
        auto& w = basket2;

        sort(u.begin(), u.end());
        sort(w.begin(), w.end());

        int a = min(u[0], w[0]);
        a <<= 1;

        int i, j, k, l;
        i = j = k = l = 0;

        while (i < n && j < n) {
            if (u[i] == w[j]) {
                i++;
                j++;
            } else if (u[i] < w[j]) {
                if (i == n - 1 || u[i] != u[i + 1])
                    return -1;
                u[k++] = u[i];
                i += 2;
            } else {
                if (j == n - 1 || w[j] != w[j + 1])
                    return -1;
                w[l++] = w[j];
                j += 2;
            }
        }

        while (i < n) {
            if (u[i] != u[i + 1])
                return -1;
            u[k++] = u[i];
            i += 2;
        }

        while (j < n) {
            if (w[j] != w[j + 1])
                return -1;
            w[l++] = w[j];
            j += 2;
        }

        long long rt = 0;

        for (i = 0; i < k; i++) {
            rt += min(min(u[i], w[k - 1 - i]), a);
        }

        return rt;
    }
};