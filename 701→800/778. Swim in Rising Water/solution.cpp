class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int N = grid.size(), l = grid[0][0], r = N * N - 1, m;
        while (l < r) {
            m = (l + r) / 2;
            if (reachable(m, grid, N))
                r = m;
            else
                l = m + 1;
        }
        return r;
    }

    int reachable(int T, vector<vector<int>>& grid, int N) {
        queue<pair<int, int>> bfs;
        vector<vector<int>> seen(N, vector<int>(N, 0));
        static int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        bfs.emplace(0, 0);
        seen[0][0] = 1;
        while (bfs.size()) {
            int x = bfs.front().first, y = bfs.front().second;
            bfs.pop();
            if (grid[x][y] <= T) {
                if (x == N - 1 && y == N - 1)
                    return true;
                for (auto& d : dir) {
                    int i = x + d[0], j = y + d[1];
                    if (i >= 0 && i < N && j >= 0 && j < N && !seen[i][j]) {
                        seen[i][j] = 1;
                        bfs.emplace(i, j);
                    }
                }
            }
        }
        return false;
    }
};