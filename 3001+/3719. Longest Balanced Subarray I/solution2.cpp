class Solution {
public:
    struct SegTree {
        struct Node {
            int mn, mx, lazy;
        };

        int n;
        vector<Node> st;

        SegTree(int n) : n(n), st(4 * n) {}

        void build(int p, int l, int r) {
            st[p].lazy = 0;
            if (l == r) {
                st[p].mn = st[p].mx = 0;
                return;
            }
            int m = (l + r) >> 1;
            build(p << 1, l, m);
            build(p << 1 | 1, m + 1, r);
            pull(p);
        }

        void pull(int p) {
            st[p].mn = min(st[p << 1].mn, st[p << 1 | 1].mn);
            st[p].mx = max(st[p << 1].mx, st[p << 1 | 1].mx);
        }

        void apply(int p, int v) {
            st[p].mn += v;
            st[p].mx += v;
            st[p].lazy += v;
        }

        void push(int p) {
            if (st[p].lazy != 0) {
                apply(p << 1, st[p].lazy);
                apply(p << 1 | 1, st[p].lazy);
                st[p].lazy = 0;
            }
        }

        // range add
        void update(int p, int l, int r, int i, int j, int v) {
            if (r < i || j < l)
                return;
            if (i <= l && r <= j) {
                apply(p, v);
                return;
            }
            push(p);
            int m = (l + r) >> 1;
            update(p << 1, l, m, i, j, v);
            update(p << 1 | 1, m + 1, r, i, j, v);
            pull(p);
        }

        // find leftmost index with value == 0
        int firstZero(int p, int l, int r) {
            if (st[p].mn > 0 || st[p].mx < 0)
                return -1;
            if (l == r)
                return l;
            push(p);
            int m = (l + r) >> 1;
            int left = firstZero(p << 1, l, m);
            if (left != -1)
                return left;
            return firstZero(p << 1 | 1, m + 1, r);
        }
    };

    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        SegTree st(n);
        st.build(1, 0, n);
        unordered_map<int, int> prev;
        int val = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            val = (nums[i] % 2) ? -1 : 1;
            if (prev.count(nums[i])) {
                int p = prev[nums[i]];
                st.update(1, 0, n, 0, p, -val);
            }
            st.update(1, 0, n, 0, i, val);
            prev[nums[i]] = i;
            int pos = st.firstZero(1, 0, n);
            if (pos != -1) {
                ans = max(ans, i - pos + 1);
            }
        }
        return ans;
    }
};
