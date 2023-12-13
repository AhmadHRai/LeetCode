
class Solution {
public:
    // Function to count the number of "special" elements in the given matrix 'mat'
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(); // Number of rows in the matrix
        int n = mat[0].size(); // Number of columns in the matrix

        // Vector to store counts of '1's in each row and column
        vector<int> rowCount(m, 0); // Initialize row count vector with 0s
        vector<int> colCount(n, 0); // Initialize column count vector with 0s

        // Counting '1's in each row and column
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (mat[row][col] == 1) {
                    rowCount[row]++; // Increment row count when '1' is encountered in the row
                    colCount[col]++; // Increment column count when '1' is encountered in the column
                }
            }
        }

        int ans = 0; // Variable to store the count of "special" elements

        // Checking for "special" elements
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (mat[row][col] == 1) { // If the element is '1'
                    if (rowCount[row] == 1 && colCount[col] == 1) {
                        // If the row and column containing this '1' have exactly one '1' (i.e., the element is "special")
                        ans++; // Increment the count of "special" elements
                    }
                }
            }
        }

        return ans; // Return the count of "special" elements
    }
};

