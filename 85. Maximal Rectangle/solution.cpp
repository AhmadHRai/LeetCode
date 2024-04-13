class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        // If the matrix is empty, return 0.
        if(matrix.size() == 0)
            return 0;

        int m = matrix.size(); // Number of rows in the matrix.
        int n = matrix[0].size(); // Number of columns in the matrix.
        vector<int> left(n), height(n); // Initialize vectors to store the leftmost boundary and height for each column.
        vector<int> right(n, n); // Initialize a vector to store the rightmost boundary for each column, initially set to the total number of columns.

        int maxArea = 0; // Initialize the maximum area to 0.
        for(int i = 0; i < m; i++) {
            int curr_left = 0, curr_right = n; // Initialize the current left and right boundaries for the current row.
            for(int j = 0; j < n; j++) {
                // If the current cell is '1', increment the height of the column.
                if(matrix[i][j] == '1')
                    height[j]++;
                else
                    // If the current cell is '0', reset the height of the column.
                    height[j] = 0;
            }
            for(int j = 0; j < n; j++) {
                // Update the leftmost boundary for the current column.
                if(matrix[i][j] == '1')
                    left[j] = max(left[j], curr_left);
                else {
                    // If the current cell is '0', reset the leftmost boundary and update the current left boundary.
                    left[j] = 0;
                    curr_left = j+1;
                }
            }
            for(int j = n-1; j >= 0; j--) {
                // Update the rightmost boundary for the current column.
                if(matrix[i][j] == '1')
                    right[j] = min(right[j], curr_right);
                else {
                    // If the current cell is '0', reset the rightmost boundary and update the current right boundary.
                    right[j] = n;
                    curr_right = j;
                }
            }
            // Calculate the area of the rectangle that can be formed with the current height and boundaries for each column.
            for(int j = 0; j < n; j++)
                maxArea = max(maxArea, (right[j] - left[j])*height[j]);
        }      
        // Return the maximum area found.
        return maxArea;
    }
};

/* 
Approach

    The solution uses a dynamic programming approach to find the maximum area of a rectangle formed by '1's in the given matrix. It iterates through each row of the matrix, updating 
    the height of each column based on the current row's '1's. It also calculates the leftmost and rightmost boundaries for each column that can be part of a rectangle. The maximum 
    area is then calculated by iterating through each column and calculating the area of the rectangle that can be formed with the current height and boundaries.

Complexity

    Time complexity: O(m*n), where m is the number of rows and n is the number of columns in the matrix. This is because each element in the matrix is processed exactly once.
    
    Space complexity: O(n), as the solution uses three vectors of size n to store the left, height, and right boundaries for each column.
*/
