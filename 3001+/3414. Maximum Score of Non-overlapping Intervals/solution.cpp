class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(),
             [&](int a, int b) { return intervals[a][1] < intervals[b][1]; });
        vector<int> rights(n);
        for (int p = 0; p < n; ++p)
            rights[p] = intervals[order[p]][1];

        using State = pair<long long, vector<int>>;
        vector<State> prev(n + 1, {0, {}}); // k = 0: nothing picked
        for (int k = 0; k < 4; ++k) {
            vector<State> cur(n + 1, {0, {}});
            for (int p = 1; p <= n; ++p) {
                int i = order[p - 1]; // take next interval
                int l = intervals[i][0], w = intervals[i][2];
                int j = lower_bound(rights.begin(), rights.end(), l) -
                        rights.begin(); // intervals ending before l
                State take = prev[j];
                take.first -= w; // scores kept negative
                take.second.insert(
                    upper_bound(take.second.begin(), take.second.end(), i), i);
                cur[p] = min(take,
                             cur[p - 1]); // min = best score, then lex smallest
            }
            prev = move(cur);
        }
        return prev[n].second;
    }
};
