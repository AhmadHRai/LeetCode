class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        vector<vector<char>> result(n, vector<char>(m, '.'));

        for (int i = 0; i < m; i++) {
            int lowestRowWithEmptyCell = n - 1;
            for (int j = n - 1; j >= 0; j--) {
                if (box[i][j] == '#') {
                    result[lowestRowWithEmptyCell][m - i - 1] = '#';
                    lowestRowWithEmptyCell--;
                }
                if (box[i][j] == '*') {
                    result[j][m - i - 1] = '*';
                    lowestRowWithEmptyCell = j - 1;
                }
            }
        }
        return result;
    }
};
