class Solution {
public:
    // Function to find the first index in arr that completes a row or column in mat
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(); // Number of rows in the matrix
        int n = mat[0].size(); // Number of columns in the matrix

        // Vector to map each number to its coordinates (row, column) in the matrix
        vector<pair<int, int>> num_to_coordinates(m * n);
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                // Store the coordinates of each number in the matrix
                num_to_coordinates[mat[r][c] - 1] = make_pair(r, c);
            }
        }

        // Vectors to tally how many numbers have been called for each row and column
        vector<int> row_tally(m, 0); // Tally for rows
        vector<int> col_tally(n, 0); // Tally for columns

        // Iterate through the arr to check for completed rows or columns
        for (int i = 0; i < arr.size(); i++) {
            auto& [r, c] = num_to_coordinates[arr[i] - 1]; // Get coordinates for the current number
            
            // Increment the tally for the corresponding row and column
            if (++row_tally[r] == n || ++col_tally[c] == m) 
                return i; // Return index if a row or column is completed
        }

        return arr.size(); // Return size of arr if no complete row or column is found
    }
};

/*
Approach Summary:
The function determines the first index in `arr` that completes a row or a column in a given matrix `mat`. It first maps each number from `mat` to its corresponding coordinates. Then it checks each number in `arr`, updating tallies for completed rows and columns. If any row or column reaches its full count of elements, it returns the index of that number. If no complete row or column is found by the end of `arr`, it returns the size of `arr`.

Complexity Analysis:
- Time Complexity: O(m * n + k), where m is the number of rows, n is the number of columns in `mat`, and k is the length of `arr`. The first loop populates coordinates in O(m * n) time, while the second loop processes `arr` in O(k) time.
- Space Complexity: O(m * n), for storing coordinates of numbers from `mat` in a vector.
*/
