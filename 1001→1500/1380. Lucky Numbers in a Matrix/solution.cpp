class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m = matrix.size();    // Number of rows in the matrix
        int n = matrix[0].size(); // Number of columns in the matrix

        int maxMin = INT_MIN; // Variable to keep track of the maximum of the row minimums
        for (int i = 0; i < m; i++) {
            int min = INT_MAX; // Variable to find the minimum value in the current row
            for (int j = 0; j < n; j++) {
                min = std::min(min, matrix[i][j]); // Update the minimum value in the row
            }
            maxMin = std::max(maxMin, min); // Update the maximum of row minimums
        }

        int minMax = INT_MAX; // Variable to keep track of the minimum of the column maximums
        for (int j = 0; j < n; j++) {
            int max = INT_MIN; // Variable to find the maximum value in the current column
            for (int i = 0; i < m; i++) {
                max = std::max(max, matrix[i][j]); // Update the maximum value in the column
            }
            minMax = std::min(minMax, max); // Update the minimum of column maximums
        }

        // If the maximum of row minimums is equal to the minimum of column maximums,
        // then it is the lucky number; otherwise, there is no lucky number
        if (maxMin != minMax) return vector<int>{};
        return vector<int>{maxMin};
    }
};

/* 
Approach

    A lucky number in a matrix is defined as a number that is the smallest in its row and the largest in its column.
    - First, find the maximum value among the minimum values of each row.
    - Then, find the minimum value among the maximum values of each column.
    - If these two values are equal, then this value is the lucky number; otherwise, no such number exists.

Complexity

    Time complexity: O(m * n), where m is the number of rows and n is the number of columns. This is because each element in the matrix is visited twice (once for row minima and once for column maxima).
    
    Space complexity: O(1), as no additional space is used except for a few variables.
 */
