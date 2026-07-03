constexpr int N = 5e4, M = 1e5;
struct Edge {
    int v, w, nxt = -1;
};
Edge E[M];
int eIdx = 0;
int deg[N], adj[N]; // heads for linked lists

inline void addEdge(int u, int v, int w) {
    E[eIdx] = {v, w, adj[u]};
    adj[u] = eIdx++;
}

using ll = long long;
ll dist[N];
int q[N], front, back;

class Solution {
public:
    static bool check(int minW, int n, long long k) {
        fill_n(dist, n, LLONG_MAX);
        dist[0] = 0;
        ll k0 = k - minW;
        for (int i = 0; i < back; i++) {
            int u = q[i];
            if (u == n - 1)
                return dist[u] <= k;
            ll d = dist[u];
            if (d > k0)
                continue;

            for (int idx = adj[u]; idx != -1; idx = E[idx].nxt) {
                const int v = E[idx].v, w = E[idx].w;
                if (w < minW)
                    continue;
                dist[v] = min(dist[v], d + w);
            }
        }
        return dist[n - 1] <= k;
    }

    static int findMaxPathScore(vector<vector<int>>& edges,
                                vector<bool>& online, long long k) {
        const int n = online.size();
        fill_n(adj, n, -1);
        eIdx = 0;
        memset(deg, 0, n * sizeof(int));

        int mnC = INT_MAX, mxC = -1;
        for (const auto& e : edges) {
            const int u = e[0], v = e[1], w = e[2];
            if (online[u] && online[v]) {
                if (u == n - 1 || v == 0)
                    continue;
                mnC = min(mnC, w);
                mxC = max(mxC, w);
                deg[v]++;
                addEdge(u, v, w);
            }
        }

        front = back = 0;
        for (int i = 0; i < n; i++) {
            if (deg[i] == 0)
                q[back++] = i;
        }
        while (front < back) {
            int u = q[front++];
            for (int idx = adj[u]; idx != -1; idx = E[idx].nxt) {
                const int v = E[idx].v;
                if (--deg[v] == 0)
                    q[back++] = v;
            }
        }

        int l = mnC, r = mxC, ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(mid, n, k)) {
                ans = mid;
                l = mid + 1;
            } else
                r = mid - 1;
        }
        return ans;
    }
};
