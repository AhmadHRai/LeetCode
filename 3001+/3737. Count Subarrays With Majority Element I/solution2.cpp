class FenwickTree {
    vector<int> bit;
    int n;

public:
    FenwickTree(int n) : n(n) { bit.assign(n + 1, 0); }

    void update(int idx, int val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
};

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + (nums[i] == target ? 1 : -1);
        }

        vector<int> values = prefix;
        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());

        FenwickTree bit(values.size());

        long long ans = 0;

        for (int x : prefix) {
            int idx = lower_bound(values.begin(), values.end(), x) -
                      values.begin() + 1;

            ans += bit.query(idx - 1);

            bit.update(idx, 1);
        }

        return (int)ans;
    }
};
