class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        // Map to store the index of each number in the arr
        unordered_map<int, int> numToIndex; // Maps numbers to their indices in arr
        for (int i = 0; i < arr.size(); i++) {
            numToIndex[arr[i]] = i; // Store the index for each number
        }

        int result = INT_MAX; // Variable to track the minimum index of completed rows/columns
        int numRows = mat.size(); // Number of rows in the matrix
        int numCols = mat[0].size(); // Number of columns in the matrix

        // Check for the earliest row to be completely painted
        for (int row = 0; row < numRows; row++) {
            // Tracks the greatest index in this row
            int lastElementIndex = INT_MIN; 
            for (int col = 0; col < numCols; col++) {
                // Get the index of the current element in arr
                int indexVal = numToIndex[mat[row][col]];
                lastElementIndex = max(lastElementIndex, indexVal); // Update to the maximum index found
            }
            // Update result with the minimum index where this row is fully painted
            result = min(result, lastElementIndex);
        }

        // Check for the earliest column to be completely painted
        for (int col = 0; col < numCols; col++) {
            // Tracks the greatest index in this column
            int lastElementIndex = INT_MIN;
            for (int row = 0; row < numRows; row++) {
                // Get the index of the current element in arr
                int indexVal = numToIndex[mat[row][col]];
                lastElementIndex = max(lastElementIndex, indexVal); // Update to the maximum index found
            }
            // Update result with the minimum index where this column is fully painted
            result = min(result, lastElementIndex);
        }

        return result == INT_MAX ? -1 : result; // Return -1 if no complete row or column is found
    }
};

/*
Approach Summary:
The function determines the first index in `arr` that completes a row or a column in a given matrix `mat`. It first maps each number from `arr` to its corresponding index. Then it checks each row and each column of `mat`, tracking the highest index of elements that need to be painted. The minimum of these indices across all rows and columns is returned. If no complete row or column is found, it returns -1.

Complexity Analysis:
- Time Complexity: O(m * n + k), where m is the number of rows, n is the number of columns in `mat`, and k is the length of `arr`. The first loop populates a map in O(k) time, while subsequent loops check rows and columns in O(m * n) time.
- Space Complexity: O(k), for storing indices of elements from `arr` in a hash map.
*/
