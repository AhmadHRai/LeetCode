class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int ROWS = box.size(); // Get the number of rows in the box
        int COLS = box[0].size(); // Get the number of columns in the box
        
        // Create a result matrix (res) of size COLS x ROWS to store the rotated box
        vector<vector<char>> res(COLS, vector<char>(ROWS, '.'));

        // Iterate over each row of the original box
        for (int r = 0; r < ROWS; r++) {
            int i = COLS - 1; // Start from the last column of the new result matrix
            
            // Iterate over each column in the current row, starting from the last column
            for (int c = COLS - 1; c >= 0; c--) {
                if (box[r][c] == '#') { // If the current element is a rock ('#')
                    res[i][ROWS - r - 1] = '#'; // Place the rock in the corresponding position in the rotated box
                    i--; // Move left in the result matrix
                }
                else if (box[r][c] == '*') { // If the current element is an obstacle ('*')
                    res[c][ROWS - r - 1] = '*'; // Place the obstacle in the rotated box
                    i = c - 1; // Set the next available position in the result row to be to the left of the obstacle
                }
            }
        }

        return res; // Return the rotated box
    }
};

/*
Approach Summary:
- The solution rotates the box 90 degrees clockwise by iterating over the rows of the input box.
- For each row, elements are processed from right to left. Rocks ('#') are placed in the appropriate columns in the result box, and obstacles ('*') reset the column index to ensure rocks don’t fall past obstacles.
- The result is a new box where the rows are transformed into columns.
- The solution directly manipulates the indices of the result matrix to simulate the effect of the 90-degree rotation.

Complexity Analysis:
- Time Complexity: O(m * n), where m is the number of rows and n is the number of columns in the box.
  - We process each element in the box exactly once, iterating through all the rows and columns.
- Space Complexity: O(m * n), where m is the number of rows and n is the number of columns in the box.
  - We use an auxiliary result matrix of size m x n to store the rotated box.
*/
