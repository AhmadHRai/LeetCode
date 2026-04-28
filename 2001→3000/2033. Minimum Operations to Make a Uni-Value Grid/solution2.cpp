class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> numsArray;
        int result = 0;

        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                numsArray.push_back(grid[row][col]);
            }
        }

        int length = numsArray.size();

        nth_element(numsArray.begin(), numsArray.begin() + length / 2,
                    numsArray.end());

        int finalCommonNumber = numsArray[length / 2];

        for (int number : numsArray) {
            if (number % x != finalCommonNumber % x) return -1;
            result += abs(finalCommonNumber - number) / x;
        }

        return result;
    }
};
