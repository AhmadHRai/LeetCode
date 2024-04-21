#include <stdio.h>
#include <stdlib.h>

int numSpecial(int** mat, int matSize, int* matColSize) {
    int m = matSize; // Number of rows in the matrix
    int n = *matColSize; // Number of columns in the matrix

    // Array to store counts of '1's in each row and column
    int* rowCount = (int*)calloc(m, sizeof(int)); // Initialize row count array with 0s
    int* colCount = (int*)calloc(n, sizeof(int)); // Initialize column count array with 0s

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

    free(rowCount);
    free(colCount);
    return ans; // Return the count of "special" elements
}



