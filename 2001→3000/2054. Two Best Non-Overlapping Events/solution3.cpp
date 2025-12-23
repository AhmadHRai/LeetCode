class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        // min-heap stores ending time with value.
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        sort(events.begin(), events.end());

        int maxVal = 0, maxSum = 0;

        for (auto& event : events) {
            // Pop all valid events from queue and take their maximum.
            while (pq.size() && pq.top().first < event[0]) {
                maxVal = max(maxVal, pq.top().second);
                pq.pop();
            }

            maxSum = max(maxSum, maxVal + event[2]);
            pq.push({event[1], event[2]});
        }

        return maxSum;
    }
};
