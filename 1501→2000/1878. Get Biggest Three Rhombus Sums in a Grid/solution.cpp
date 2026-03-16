// https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/?envType=daily-question&envId=2026-03-16
class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        set<int> st;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                st.insert(grid[i][j]);

                for (int k = 1;; k++) {

                    int r = i + 2 * k;
                    int left = j - k;
                    int right = j + k;

                    if (r >= m || left < 0 || right >= n)
                        break;

                    int sum = 0;

                    int x = i, y = j;

                    // top -> right
                    for (int t = 0; t < k; t++) {
                        sum += grid[x + t][y + t];
                    }

                    // right -> bottom
                    for (int t = 0; t < k; t++) {
                        sum += grid[x + k + t][y + k - t];
                    }

                    // bottom -> left
                    for (int t = 0; t < k; t++) {
                        sum += grid[x + 2 * k - t][y - t];
                    }

                    // left -> top
                    for (int t = 0; t < k; t++) {
                        sum += grid[x + k - t][y - k + t];
                    }

                    st.insert(sum);
                }
            }
        }

        vector<int> ans;
        for (auto it = st.rbegin(); it != st.rend() && ans.size() < 3; ++it) {
            ans.push_back(*it);
        }

        return ans;
    }
};
