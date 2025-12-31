class DSU {
    vector<int> root;
    vector<int> size;

public:
    DSU(int n) : root(n), size(n, 1) { iota(root.begin(), root.end(), 0); }

    int find(int x) {
        if (root[x] != x)
            root[x] = find(root[x]);

        return root[x];
    }

    void unite(int x, int y) {
        int rx = find(x);
        int ry = find(y);

        if (rx == ry)
            return;

        if (size[rx] > size[ry]) {
            int t = rx;
            rx = ry;
            ry = t;
        }

        root[rx] = ry;
        size[ry] += size[rx];
    }
};

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        DSU dsu(row * col + 2);
        vector<vector<int>> grid(row, vector<int>(col, 0));
        int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (int i = (int)cells.size() - 1; i >= 0; i--) {
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            grid[r][c] = 1;

            int id1 = r * col + c + 1;

            for (int k = 0; k < 4; k++) {
                int nr = r + dirs[k][0];
                int nc = c + dirs[k][1];

                if (nr >= 0 && nr < row && nc >= 0 && nc < col &&
                    grid[nr][nc] == 1) {
                    int id2 = nr * col + nc + 1;
                    dsu.unite(id1, id2);
                }
            }

            if (r == 0)
                dsu.unite(0, id1);

            if (r == row - 1)
                dsu.unite(row * col + 1, id1);

            if (dsu.find(0) == dsu.find(row * col + 1))
                return i;
        }

        return -1;
    }
};
