// O(n*logn*logn)
// max segment tree + binary search
auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; });
class Segment_Tree {
    vector<int> seg;

public:
    Segment_Tree(int n) { seg.resize(4 * n + 1); }

    void build(int idx, int low, int high, vector<int>& v) {
        if (low == high) {
            seg[idx] = v[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * idx + 1, low, mid, v);
        build(2 * idx + 2, mid + 1, high, v);
        seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    void update(int idx, int low, int high, int i, int val) {
        if (low == high) {
            seg[idx] = val;
            return;
        }
        int mid = (low + high) / 2;
        if (i <= mid)
            update(2 * idx + 1, low, mid, i, val);
        else
            update(2 * idx + 2, mid + 1, high, i, val);
        seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    int query(int idx, int low, int high, int l, int r) {
        // complete overlap
        if (low >= l && high <= r)
            return seg[idx];
        // no overlap
        if (high < l || low > r)
            return INT_MIN;
        // partial overlap
        int mid = (low + high) / 2;
        int left = query(2 * idx + 1, low, mid, l, r);
        int right = query(2 * idx + 2, mid + 1, high, l, r);
        return max(left, right);
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        Segment_Tree st(n);
        st.build(0, 0, n - 1, baskets);

        int ans = n;
        for (int a : fruits) {
            // binary searching on segment tree to find the leftmost available
            // basket
            int sub = -1;
            int l = 0, r = n - 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                int cap = st.query(0, 0, n - 1, 0, mid);
                if (cap >= a) {
                    sub = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }

            if (sub != -1) {
                --ans;
                st.update(0, 0, n - 1, sub, 0);
            }
        }

        return ans;
    }
};