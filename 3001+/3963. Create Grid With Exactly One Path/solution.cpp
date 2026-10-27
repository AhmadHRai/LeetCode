class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> res(m, string(n, '#'));
        int r = 0, c = 0;

        res[r][c] = '.';

        while (r < m - 1 || c < n - 1) {
            if (r < m - 1 && (c == n - 1 || abs((r + 1) * (n - 1) - c * (m - 1)) <= abs(r * (n - 1) - (c + 1) * (m - 1))))
                r++;
            else
                c++;

            res[r][c] = '.';
        }

        return res;
    }
};
