class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<pair<int,int>> cnt(m, {0,0});
        int res = 0;

        for(int i = 0; i < n; i++) {
            int cnt_x = 0, cnt_y = 0;

            for(int j = 0; j < m; j++) {
                cnt_x += grid[i][j] == 'X';
                cnt_y += grid[i][j] == 'Y';

                cnt[j].first += cnt_x;
                cnt[j].second += cnt_y;

                if(cnt[j].first > 0 && cnt[j].first == cnt[j].second) res++;
            }
        }

        return res;
    }
};
