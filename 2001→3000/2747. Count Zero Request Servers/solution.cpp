class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x,
                             vector<int>& queries) {
        ranges::sort(logs, {}, [](auto& log) { return log[1]; }); // by time
        logs.push_back({0, INT_MAX}); // sentinel: no window ever reaches it
        vector<int> order(queries.size());
        iota(order.begin(), order.end(), 0);
        ranges::sort(order, {}, [&](int i) {
            return queries[i];
        }); // query positions in time order

        vector<int> cnt(n + 1),
            ans(queries.size()); // cnt: requests per server inside the window
                                 // [q - x, q]
        int busy = 0, lo = 0,
            hi = 0; // busy: servers with at least one request in it
        for (int i : order) {
            int q = queries[i];
            for (; logs[hi][1] <= q; ++hi) // requests up to q come in
                busy += cnt[logs[hi][0]]++ == 0;
            for (; logs[lo][1] < q - x; ++lo) // requests before q - x go out
                busy -= --cnt[logs[lo][0]] == 0;
            ans[i] = n - busy;
        }
        return ans;
    }
};
