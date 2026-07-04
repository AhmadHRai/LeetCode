class DSU {
private:
    vector<int> parent;
    vector<int> size;

public:
    DSU(int n) : parent(n + 1), size(n + 1, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = find(parent[node]);   // Path compression
    }

    void unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU == rootV)
            return;

        // Always attach the smaller tree under the larger tree.
        if (size[rootU] < size[rootV])
            swap(rootU, rootV);

        parent[rootV] = rootU;
        size[rootU] += size[rootV];
    }
};

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        DSU dsu(n);

        // Build connected components.
        for (const auto& road : roads)
            dsu.unite(road[0], road[1]);

        int rootOfOne = dsu.find(1);
        int answer = INT_MAX;

        // The answer is the smallest edge inside city 1's component.
        for (const auto& road : roads) {
            if (dsu.find(road[0]) == rootOfOne)
                answer = min(answer, road[2]);
        }

        return answer;
    }
};
