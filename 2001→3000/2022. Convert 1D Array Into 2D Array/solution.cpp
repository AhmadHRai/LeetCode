class Solution {
public:
    // Function to construct a 2D array from a 1D array
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        const int size = original.size(); // Size of the original 1D array

        // Check if the 1D array can be exactly divided into an m x n 2D array
        if (size != m * n) {
            return {}; // Return an empty vector if the dimensions do not match
        }

        vector<vector<int>> ans(m); // Initialize the 2D array with m rows

        for (int i = 0; i < m; i++) {
            // Assign each row of the 2D array from the original 1D array
            ans[i].assign(original.begin() + i * n, original.begin() + (i + 1) * n);
        }

        return ans; // Return the constructed 2D array
    }
};

/*
Approach Summary:
- Check if the size of the original 1D array matches the required size for an m x n 2D array.
- If the sizes match, create a 2D array with m rows and populate each row with n elements from the original array.
- Return the 2D array if the dimensions are valid, otherwise return an empty vector.

Time Complexity:
- O(m * n), where m is the number of rows and n is the number of columns. The function traverses the original array and assigns elements to the 2D array.

Space Complexity:
- O(m * n), where m is the number of rows and n is the number of columns. Space is used to store the 2D array.
*/
