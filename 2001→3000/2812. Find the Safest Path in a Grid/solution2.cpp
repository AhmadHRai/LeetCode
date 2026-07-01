class Solution {
public:
    static constexpr int dr[4] = {-1, 1, 0, 0};
    static constexpr int dc[4] = {0, 0, -1, 1};

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        // If start or destination contains a thief.
        if (grid[0][0] || grid[n - 1][n - 1])
            return 0;

        //=========================================================
        // Step 1: Multi-source BFS
        // distance[r][c] = distance to nearest thief
        //=========================================================

        vector<vector<int>> distance(n, vector<int>(n, 0));
        queue<pair<int,int>> q;

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1)
                    q.push({r, c});
            }
        }

        int level = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [r, c] = q.front();
                q.pop();

                distance[r][c] = level;

                for (int k = 0; k < 4; k++) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if (nr < 0 || nr >= n || nc < 0 || nc >= n)
                        continue;

                    // Unvisited empty cell
                    if (grid[nr][nc] == 0) {
                        grid[nr][nc] = -1;
                        q.push({nr, nc});
                    }
                }
            }

            level++;
        }

        //=========================================================
        // Step 2:
        // Maximum Bottleneck Path (Modified Dijkstra)
        //
        // State = maximum possible minimum safeness
        //=========================================================

        using State = pair<int, pair<int,int>>;
        priority_queue<State> pq;

        vector<vector<bool>> visited(n, vector<bool>(n, false));

        pq.push({distance[0][0], {0, 0}});
        visited[0][0] = true;

        while (!pq.empty()) {

            auto [currentSafe, position] = pq.top();
            pq.pop();

            auto [r, c] = position;

            if (r == n - 1 && c == n - 1)
                return currentSafe;

            for (int k = 0; k < 4; k++) {

                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr < 0 || nr >= n || nc < 0 || nc >= n)
                    continue;

                if (visited[nr][nc])
                    continue;

                visited[nr][nc] = true;

                int newSafe = min(currentSafe, distance[nr][nc]);

                pq.push({newSafe, {nr, nc}});
            }
        }

        return 0;
    }
};
