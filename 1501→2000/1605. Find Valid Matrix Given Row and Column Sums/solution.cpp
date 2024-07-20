class Solution {
public:
    static vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        const int r = rowSum.size(); // Number of rows
        const int c = colSum.size(); // Number of columns
        vector<vector<int>> arr(r, vector<int>(c, 0)); // Initialize the result matrix with zeros
        
        // Iterate through each cell in the matrix to restore its value
        for (int i = 0, j = 0; i < r && j < c; ) {
            int x = min(rowSum[i], colSum[j]); // Determine the value to put in the current cell
            arr[i][j] = x; // Set the value in the matrix
            rowSum[i] -= x; // Decrease the remaining row sum
            colSum[j] -= x; // Decrease the remaining column sum
            
            // Move to the next row if the current row's sum is zero
            if (rowSum[i] == 0) {
                i++;
            }
            // Move to the next column if the current column's sum is zero
            if (colSum[j] == 0) {
                j++;
            }
        }
        
        return arr; // Return the restored matrix
    }
};

/* 
Approach

    The solution restores the original matrix given row and column sums.
    - Initialize a matrix with zeros.
    - Iterate over each cell, filling in values by taking the minimum of the remaining row sum and column sum.
    - Update the row and column sums by subtracting the value added to the matrix.
    - Move to the next row or column when the respective sum becomes zero.

Complexity

    Time complexity: O(r * c), where r is the number of rows and c is the number of columns. This is because we iterate through each cell of the matrix once.

    Space complexity: O(r * c), as we store the result in a matrix of size r x c.
 */

// stuff to boost judge's speed
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
