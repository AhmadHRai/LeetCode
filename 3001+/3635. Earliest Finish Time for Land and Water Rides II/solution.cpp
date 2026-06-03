class Solution {
    static inline int MAX = 300005;

public:
    int earliestFinishTime(vector<int>& la, vector<int>& lb, vector<int>& wa,
                           vector<int>& wb) {
        int l = MAX, w = MAX, minL = MAX, minW = MAX;
        int n = la.size(), m = wa.size();

        for (int i = 0; i < n; i++)
            l = min(l, la[i] + lb[i]);

        for (int i = 0; i < m; i++) {
            w = min(w, wa[i] + wb[i]);
            minL = min(minL, max(wa[i], l) + wb[i]);
        }

        for (int i = 0; i < n; i++)
            minW = min(minW, max(la[i], w) + lb[i]);

        return min(minW, minL);
    }
};
