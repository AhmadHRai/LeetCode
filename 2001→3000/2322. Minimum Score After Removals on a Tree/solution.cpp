class Solution {
public:
    int n;
    vector<vector<int>> graph;
    vector<int> subXor, in, out, parent;
    int time = 0;

    void dfs(int node, int par, const vector<int>& nums) {
        in[node] = ++time;
        subXor[node] = nums[node];
        parent[node] = par;
        for (int nei : graph[node]) {
            if (nei == par) continue;
            dfs(nei, node, nums);
            subXor[node] ^= subXor[nei];
        }
        out[node] = ++time;
    }

    bool isAncestor(int u, int v) {
        // Is u ancestor of v?
        return in[u] <= in[v] && out[v] <= out[u];
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        n = nums.size();
        graph.resize(n);
        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        subXor.resize(n);
        in.resize(n);
        out.resize(n);
        parent.resize(n, -1);

        dfs(0, -1, nums);
        int totalXor = subXor[0];
        int res = INT_MAX;

        // Try all pairs of removed edges
        for (auto& e1 : edges) {
            int a = e1[0], b = e1[1];
            int child1 = parent[a] == b ? a : b;

            for (auto& e2 : edges) {
                if (e1 == e2) continue;

                int c = e2[0], d = e2[1];
                int child2 = parent[c] == d ? c : d;

                int xor1 = subXor[child1];
                int xor2 = subXor[child2];

                if (isAncestor(child1, child2)) {
                    xor1 = subXor[child1] ^ subXor[child2];
                } else if (isAncestor(child2, child1)) {
                    xor2 = subXor[child2] ^ subXor[child1];
                }

                int xor3 = totalXor ^ xor1 ^ xor2;
                int maxVal = max({xor1, xor2, xor3});
                int minVal = min({xor1, xor2, xor3});
                res = min(res, maxVal - minVal);
            }
        }

        return res;
    }
};
