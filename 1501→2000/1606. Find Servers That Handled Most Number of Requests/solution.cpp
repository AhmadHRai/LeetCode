class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arr, vector<int>& lo) {
        set<int> free;
        int n = arr.size();
        for (int i = 0; i < 2*k - 1; i ++)
            free.insert(i);
        vector<int> cnt(k, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (int i = 0; i < n; i ++)
        {
            int at = arr[i];
            int load = lo[i];
            while (!pq.empty() and pq.top().first <= at)
            {
                auto tt = pq.top();
                int server = tt.second;
                pq.pop();
                free.insert(server);
                free.insert(server + k);
            }
            if (!free.empty()) {
                int server = (*free.lower_bound(i % k)) % k;
                free.erase(server % k);
                free.erase(server % k + k);

                cnt[server] ++;
                pq.push({at + load, server});
            }
        }
        int mv = -1;
        vector<int> res;
        for (int i = 0; i < k; i ++)
        {
            if (cnt[i] > mv)
            {
                mv = cnt[i];
                res = {i};
            }
            else if (cnt[i] == mv)
                res.push_back(i);
        }
        return res;
    }
};
