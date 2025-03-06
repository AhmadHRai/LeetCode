class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int missing = -1, repeat = -1;

        unordered_map<int, int> map;
        for (auto& row : grid) {
            for (int num : row) {
                map[num]++;
            }
        }

        for (int num = 1; num <= n * n; num++) {
            if(!map.count(num)) missing = num;
            else if(map[num] == 2) repeat = num;
        }

        return {repeat, missing};
    }
};