class SegTree {
    vector<int> maxv, minv;
    int n;

public:
    SegTree(vector<int>& nums) {
        n = nums.size();
        maxv.resize(n * 4);
        minv.resize(n * 4);
        build(1, 0, n - 1, nums);
    }

    void build(int node, int l, int r, vector<int>& nums) {
        if (l == r) {
            maxv[node] = minv[node] = nums[l];
            return;
        }
        int m = (l + r) / 2;
        build(node * 2, l, m, nums);
        build(node * 2 + 1, m + 1, r, nums);
        maxv[node] = max(maxv[node * 2], maxv[node * 2 + 1]);
        minv[node] = min(minv[node * 2], minv[node * 2 + 1]);
    }

    int queryMax(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return maxv[node];
        }
        int m = (l + r) / 2, res = INT_MIN;
        if (ql <= m) {
            res = max(res, queryMax(node * 2, l, m, ql, qr));
        }
        if (qr > m) {
            res = max(res, queryMax(node * 2 + 1, m + 1, r, ql, qr));
        }
        return res;
    }

    int queryMin(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return minv[node];
        }
        int m = (l + r) / 2, res = INT_MAX;
        if (ql <= m) {
            res = min(res, queryMin(node * 2, l, m, ql, qr));
        }
        if (qr > m) {
            res = min(res, queryMin(node * 2 + 1, m + 1, r, ql, qr));
        }
        return res;
    }
};

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        SegTree seg(nums);
        priority_queue<tuple<int, int, int>> pq;
        for (int l = 0; l < n; l++) {
            pq.emplace(seg.queryMax(1, 0, n - 1, l, n - 1) -
                           seg.queryMin(1, 0, n - 1, l, n - 1),
                       l, n - 1);
        }
        long long ans = 0;
        while (k--) {
            auto [val, l, r] = pq.top();
            pq.pop();
            ans += val;
            if (r > l) {
                pq.emplace(seg.queryMax(1, 0, n - 1, l, r - 1) -
                               seg.queryMin(1, 0, n - 1, l, r - 1),
                           l, r - 1);
            }
        }
        return ans;
    }
};
