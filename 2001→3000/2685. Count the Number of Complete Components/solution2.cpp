class Solution {
public:
    vector<int> par;

    int find(int x) {
        if (par[x] == x)
            return x;
        return par[x] = find(par[x]);
    }

    void uunion(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv)
            return;
        else {
            par[pv] = pu;
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        par.resize(n);
        for (int i = 0; i < n; i++)
            par[i] = i;

        vector<int> count(n);
        vector<int> size(n);

        int ans = 0;

        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            int pu = find(u);
            int pv = find(v);

            uunion(pu, pv);
        }

        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];

            int pu = find(u);

            count[pu]++;
        }

        for (int i = 0; i < n; i++) {
            int found = find(i);
            size[found]++;
        }

        for (int i = 0; i < n; i++) {
            if (size[i] == 0)
                continue;
            int k = size[i];
            if (count[i] == (k * (k - 1)) / 2)
                ans++;
        }

        return ans;
    }
};
