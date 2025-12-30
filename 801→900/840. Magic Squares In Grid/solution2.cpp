class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int row = 0; row + 2 < m; row++) {
            for (int col = 0; col + 2 < n; col++) {
                if (isMagicSquare(grid, row, col)) {
                    ans++;
                }
            }
        }
        return ans;
    }

private:
    bool isMagicSquare(vector<vector<int>>& grid, int row, int col) {
        // The sequences are each repeated twice to account for
        // the different possible starting points of the sequence
        // in the magic square
        string sequence = "2943816729438167";
        string sequenceReversed = "7618349276183492";

        string border = "";
        // Flattened indices for bordering elements of 3x3 grid
        vector<int> borderIndices = {0, 1, 2, 5, 8, 7, 6, 3};
        for (int i : borderIndices) {
            int num = grid[row + i / 3][col + (i % 3)];
            border += to_string(num);
        }

        // Make sure the sequence starts at one of the corners
        return (grid[row][col] % 2 == 0 && grid[row + 1][col + 1] == 5 &&
                (sequence.find(border) != string::npos ||
                 sequenceReversed.find(border) != string::npos));
    }
};
