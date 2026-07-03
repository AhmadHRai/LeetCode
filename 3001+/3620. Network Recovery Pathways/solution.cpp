typedef long long ll;
class Solution {
public:
    ll solve(int src,int target ,vector<vector<pair<int,int>>>& adj,int n ){
        ll maxi = LLONG_MAX/4;
        vector<ll>dist(n,maxi);
        dist[src]=0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>>pq;
        pq.emplace(0,src);
        while(!pq.empty()){
            auto [d,u] = pq.top(); pq.pop();
            if(d>dist[u]) continue;
            if(u==target) return d;
            for(auto [v,w]: adj[u]){
                if(dist[v]>d+w){
                    dist[v] = d+w;
                    pq.emplace(dist[v],v);
                }
            }
        }
        return maxi;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        ll l = 0, h = 1e9, best = -1;
        while (l <= h) {
            ll mid = l + (h - l) / 2;
            vector<vector<pair<int,int>>> adj(n);
            for (auto& e : edges) {
                int u = e[0], v = e[1], c = e[2];
                if (c >= mid && online[u] && online[v]) {
                    adj[u].emplace_back(v,c);
                }
            }
            ll dist = solve(0, n - 1, adj, n);
            if (dist <= k) {
                best = mid;
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return best;
    }
};
