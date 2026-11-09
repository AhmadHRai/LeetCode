#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    int size;
    vector<int> tree;

    // Update server 'idx' with its new finish time
    void update(int idx, int val) {
        idx += size;
        tree[idx] = val;
        for (idx >>= 1; idx > 0; idx >>= 1) {
            tree[idx] = min(tree[idx << 1], tree[idx << 1 | 1]);
        }
    }

    // Find the first server in [ql, qr] with finish time <= target_time
    int query(int node, int l, int r, int ql, int qr, int target_time) {
        if (ql > r || qr < l || tree[node] > target_time) {
            return -1; // No available server in this range
        }
        if (l == r) {
            return l; // Found the exact server index
        }
        int mid = l + ((r - l) >> 1);
        int res = -1;
        if (ql <= mid) {
            res = query(node << 1, l, mid, ql, qr, target_time);
        }
        if (res == -1 && qr > mid) {
            res = query(node << 1 | 1, mid + 1, r, ql, qr, target_time);
        }
        return res;
    }

public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();
        k = min(k, n); // We never use more than n servers

        // Round size up to the next power of 2 for a clean binary tree
        size = 1;
        while (size < k) size <<= 1;

        // Initialize all servers as available at time 0
        tree.assign(2 * size, 0);
        vector<int> count(k, 0);

        for (int i = 0; i < n; ++i) {
            int start = arrival[i];

            // Quick check: if the global minimum finish time > start, all servers are busy
            if (tree[1] > start) continue;

            int preferred = i % k;

            // 1. Search in [preferred, k - 1]
            int server = query(1, 0, size - 1, preferred, k - 1, start);

            // 2. Wrap around and search in [0, preferred - 1] if needed
            if (server == -1 && preferred > 0) {
                server = query(1, 0, size - 1, 0, preferred - 1, start);
            }

            if (server != -1) {
                count[server]++;
                update(server, start + load[i]);
            }
        }

        int max_reqs = *max_element(count.begin(), count.end());
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            if (count[i] == max_reqs) {
                res.push_back(i);
            }
        }
        return res;
    }
};
