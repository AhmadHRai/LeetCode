class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int> root(n + 1);
        iota(root.begin(), root.end(), 0);

        auto find = [&](this auto& self, int i) -> int {
            return root[i] == i ? i : root[i] = self(root[i]);
        };

        for (auto& r : roads)
            root[find(r[0])] = find(r[1]);

        int res = 10001;
        for (auto& r : roads)
            if (find(r[0]) == find(1))
                res = min(res, r[2]);

        return res;
    }
};
