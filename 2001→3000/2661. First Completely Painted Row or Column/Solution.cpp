class Solution {
public:
    // Function to find the first index in arr that completes a row or column in mat
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        // Maps to track the row and column of each number in the matrix
        unordered_map<int, int> mpr; // Maps numbers to their row indices
        unordered_map<int, int> mpc; // Maps numbers to their column indices
        
        // Maps to count how many numbers have been called in each row and column
        unordered_map<int, int> mprc; // Counts for completed rows
        unordered_map<int, int> mpcc; // Counts for completed columns

        // Populate the maps with positions of each number in the matrix
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); ++j) {
                mpr[mat[i][j]] = i; // Store the row index for each number
                mpc[mat[i][j]] = j; // Store the column index for each number
            }
        }

        // Iterate through the array to find the first complete row or column
        for (int i = 0; i < arr.size(); i++) {
            int n = arr[i]; // Current number being processed
            
            // Increment counts for the corresponding row and column of the number
            mprc[mpr[n]]++; 
            mpcc[mpc[n]]++;
            
            // Check if any row or column is completely filled
            if (mprc[mpr[n]] == mat[0].size() || mpcc[mpc[n]] == mat.size()) 
                return i; // Return the index if a complete row or column is found
        }
        
        return -1; // Return -1 if no complete row or column is found
    }
};

/*
Approach Summary:
The function determines the first index in `arr` that completes a row or a column in a given matrix `mat`. It uses hash maps to track the positions of each number in `mat` and counts how many numbers from `arr` have been called for each row and column. As it processes `arr`, it checks if any row or column has been completely filled, returning the index of the first such occurrence.

Complexity Analysis:
- Time Complexity: O(m * n + k), where m is the number of rows, n is the number of columns in `mat`, and k is the length of `arr`. The first loop populates maps in O(m * n) time, while the second loop processes `arr` in O(k) time.
- Space Complexity: O(m * n), for storing positions and counts in hash maps.
*/