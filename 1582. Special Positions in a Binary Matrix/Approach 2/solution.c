#include <stdio.h>

int numSpecial(int** mat, int matSize, int* matColSize) {
    int ans = 0;
    int m = matSize; // Number of rows in the matrix
    int n = *matColSize; // Number of columns in the matrix

    for (int row = 0; row < m; row++) {
        for (int col = 0; col < n; col++) {
            if (mat[row][col] == 0) {
                continue; // If the element is 0, continue to the next iteration
            }

            int good = 1; // Flag to determine if the element is "special"

            // Checking the entire column for other '1's except for the current row
            for (int r = 0; r < m; r++) {
                if (r != row && mat[r][col] == 1) {
                    good = 0; // If a '1' is found in the same column in another row, mark as not "special"
                    break;
                }
            }

            // Checking the entire row for other '1's except for the current column
            for (int c = 0; c < n; c++) {
                if (c != col && mat[row][c] == 1) {
                    good = 0; // If a '1' is found in the same row in another column, mark as not "special"
                    break;
                }
            }

            if (good) {
                ans++; // If the element is "special," increment the count
            }
        }
    }

    return ans; // Return the count of "special" elements
}



