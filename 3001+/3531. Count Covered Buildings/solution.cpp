const int SZ = 100001;
int xMin[SZ], xMax[SZ], yMin[SZ], yMax[SZ];
class Solution {
public:
    static int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int M = 0, N = 0;
        for (auto& B : buildings) {
            const int x = B[0], y = B[1];
            M = max(x, M);
            N = max(y, N);
        }
        memset(xMax, 0, sizeof(int) * (N + 1));
        memset(yMax, 0, sizeof(int) * (M + 1));
        fill(xMin, xMin + (N + 1), INT_MAX);
        fill(yMin, yMin + (M + 1), INT_MAX);

        for (auto& B : buildings) {
            const int x = B[0], y = B[1];
            xMin[y] = min(xMin[y], x);
            xMax[y] = max(xMax[y], x);
            yMin[x] = min(yMin[x], y);
            yMax[x] = max(yMax[x], y);
        }
        int cnt = 0;
        for (auto& B : buildings) {
            const int x = B[0], y = B[1];
            const bool coverX = (xMin[y] < x & x < xMax[y]);
            const bool coverY = (yMin[x] < y & y < yMax[x]);
            cnt += (coverX & coverY);
        }
        return cnt;
    }
};
