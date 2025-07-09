// greedy sliding window
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime,
                    vector<int>& endTime) {
        int res = 0;
        int n = startTime.size(), t = 0;

        for (int i = 0; i < n; i++) {
            t += endTime[i] - startTime[i];
            int l = i <= k - 1 ? 0 : endTime[i - k];
            int r = i == n - 1 ? eventTime : startTime[i + 1];

            res = max(res, r - l - t);
            if (i >= k - 1) {
                t -= endTime[i - k + 1] - startTime[i - k + 1];
            }
        }

        return res;
    }
};