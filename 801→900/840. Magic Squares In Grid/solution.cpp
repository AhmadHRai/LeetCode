class Solution {
public:
    // Function to determine if a 3x3 grid with center at (i, j) is a magic square
    static bool isMagic(int i, int j, vector<vector<int>>& grid){
        // bitset to track if each digit from 1 to 9 appears exactly once
        bitset<10> once; // bitset of size 10 to track digits 1-9
        int rowSum[3] = {0}, colSum[3] = {0}; // Arrays to store the sum of each row and column

        // Iterate over the 3x3 sub-grid centered at (i, j)
        for(int a = i - 1; a <= i + 1; a++) {
            for(int b = j - 1; b <= j + 1; b++) {
                int x = grid[a][b]; // Get the value at position (a, b)
                if (x < 1 || x > 9) return 0; // Return false if value is not between 1 and 9
                rowSum[a - i + 1] += x; // Update the row sum
                colSum[b - j + 1] += x; // Update the column sum
                once.flip(x); // Mark the digit as seen
            }
        }
        
        // Check if all digits from 1 to 9 appear exactly once
        if (once.count() != 9) return 0;

        // Check if the sums of all rows and columns are equal to 15
        if (!all_of(rowSum, rowSum + 3, [](int sum){ return sum == 15; })) return 0;
        if (!all_of(colSum, colSum + 3, [](int sum){ return sum == 15; })) return 0;

        // Check if the sums of the two diagonals are equal to 15
        return (grid[i - 1][j - 1] + grid[i + 1][j + 1] == 10 &&
                grid[i + 1][j - 1] + grid[i - 1][j + 1] == 10);
    }

    // Function to count the number of 3x3 magic squares within the grid
    static int numMagicSquaresInside(vector<vector<int>>& grid) {
        const int r = grid.size(), c = grid[0].size(); // Get the number of rows and columns
        if (r < 3 || c < 3) return 0; // If the grid is too small to contain a 3x3 magic square, return 0

        int cnt = 0; // Counter for the number of magic squares
        // Iterate over each possible center of a 3x3 sub-grid
        for(int i = 1; i < r - 1; i++) {
            for(int j = 1; j < c - 1; j++) {
                // If the center of the 3x3 grid is 5, check if it's a magic square
                if (grid[i][j] == 5) 
                    cnt += isMagic(i, j, grid); // Increment the counter if it's a magic square
            }
        }
        return cnt; // Return the total count of magic squares found
    }
};

// Fast input/output optimization
auto init = []() {
    ios::sync_with_stdio(false); // Disable synchronization with C standard streams for faster input/output
    cin.tie(nullptr); // Untie cin from cout
    cout.tie(nullptr); // Untie cout from cin
    return 'c'; // Return 'c' to satisfy the lambda's return type
}();

/*
Approach:
1. The `isMagic` function checks if a 3x3 sub-grid of the input grid, centered at (i, j), forms a magic square.
   - It uses a bitset to track if all digits from 1 to 9 appear exactly once in the 3x3 grid.
   - It calculates the sums of all rows and columns, and ensures each sum is 15.
   - It also checks if the two diagonals sum to 15, which is a requirement for a 3x3 magic square.

2. The `numMagicSquaresInside` function iterates through each possible center of a 3x3 sub-grid within the grid.
   - It checks if the center of the grid is 5 (a necessary condition for a 3x3 magic square to be centered at this position).
   - If true, it calls `isMagic` to verify if the 3x3 grid is indeed a magic square.
   - It counts the number of such valid magic squares and returns this count.

Complexity Analysis:
- Time Complexity:
  - The `numMagicSquaresInside` function iterates over all potential centers of 3x3 grids in the input grid. If the grid has `r` rows and `c` columns, there are approximately `(r-2) x (c-2)` centers to check.
  - For each center, the `isMagic` function performs constant time checks, which involve iterating over a fixed-size 3x3 sub-grid.
  - Therefore, the overall time complexity is O((r-2) * (c-2)) ≈ O(r * c), where each grid verification is O(1) due to the constant size of the 3x3 grid.

- Space Complexity:
  - The space used by the `isMagic` function includes the `bitset` and arrays for row and column sums, which are all constant in size.
  - Thus, the space complexity is O(1), as the auxiliary space used does not depend on the size of the input grid.
*/
