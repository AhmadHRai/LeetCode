class Solution {
public:
    int find(vector<int> &ds, int i) {
        return ds[i] < 0 ? i : ds[i] = find(ds, ds[i]);
    }
    int minCostConnectPoints(vector<vector<int>>& ps) {
        int n = ps.size(), res = 0;
        vector<int> ds(n, -1);
        vector<array<int, 3>> arr;
        for (auto i = 0; i < n; ++i)
            for (auto j = i + 1; j < n; ++j) {
                arr.push_back({abs(ps[i][0] - ps[j][0]) + abs(ps[i][1] - ps[j][1]), i, j});
            }
        make_heap(begin(arr), end(arr), greater<array<int, 3>>());
        while (!arr.empty()) {
            pop_heap(begin(arr), end(arr), greater<array<int, 3>>());
            auto [dist, i, j] = arr.back();
            arr.pop_back();
            i = find(ds, i), j = find(ds, j);
            if (i != j) {
                res += dist;
                ds[i] += ds[j];
                ds[j] = i;
                if (ds[i] == -n)
                    break;
            }
        }
        return res;
    }
};

/* Approach:
    Kruskal
    Kruskal involves min heap to pick the smallest edge, and union-find to check if the edge is redundant. We exit when all points are connected 
    For Kruskal, the complexity when using sort is O(n * n log (n * n)) - we have n * n edges. Using a min heap is O(k log (n * n)), where k is the number of edges we need to pull to complete the tree. It's much smaller than n * n in the average case.
    */