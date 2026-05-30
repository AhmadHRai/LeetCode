class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& qs) {
        vector<bool> res;
        set<int> blocks{0};

        for (const auto& q : qs) {
            if (q[0] == 1) {
                blocks.insert(q[1]);
            }
        }

        for (auto it = next(blocks.begin()); it != blocks.end(); ++it) {
            update(*it, *it - *prev(it));
        }

        for (int i = static_cast<int>(qs.size()) - 1; i >= 0; --i) {
            int t = qs[i][0];
            int x = qs[i][1];
            int sz = (t == 1 ? 0 : qs[i][2]);

            auto it = blocks.lower_bound(x);

            if (t == 1) {
                if (next(it) != blocks.end()) {
                    update(*next(it), *next(it) - *prev(it));
                }
                blocks.erase(it);
            } else {
                res.push_back(
                    x - *prev(it) >= sz ||
                    getmax(x) >= sz
                );
            }
        }

        return vector<bool>(res.rbegin(), res.rend());
    }

    int bit[50001] = {};

    int getmax(int r) {
        int ret = 0;

        for (; r >= 0; r = (r & (r + 1)) - 1) {
            ret = max(ret, bit[r]);
        }

        return ret;
    }

    void update(int idx, int val) {
        for (; idx < 50001; idx = idx | (idx + 1)) {
            bit[idx] = max(bit[idx], val);
        }
    }
};
