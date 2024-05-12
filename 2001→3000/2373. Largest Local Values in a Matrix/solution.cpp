class Solution 
{
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) 
    {
        // The grid size is determined by the size of the input grid.
        int n = grid.size();
        
        // Initialize the result matrix with dimensions (n-2) x (n-2) to store the largest local values.
        vector<vector<int>> res(n-2, vector<int> (n-2));
        
        // Iterate through the grid, starting from the second row and second column to avoid out-of-bounds errors.
        // This is because we are looking for the largest local values in a 3x3 matrix centered around each cell.
        for(int i = 1; i <= n - 2; i++)
        {
            for(int j = 1; j <= n - 2; j++)
            {
                // Initialize maxi to store the largest value found in the 3x3 matrix centered around the current cell.
                int maxi = 0;
                
                // Find the maximum value in the 3x3 matrix centered around the current cell.
                // This is done by comparing the values of the cells in the current row, column, and the cells diagonally adjacent to the current cell.
                maxi = max({maxi, grid[i-1][j-1], grid[i-1][j], grid[i-1][j+1]});
                maxi = max({maxi, grid[i][j-1], grid[i][j], grid[i][j+1]});
                maxi = max({maxi, grid[i+1][j-1], grid[i+1][j], grid[i+1][j+1]});
                
                // Store the largest value found in the 3x3 matrix centered around the current cell in the result matrix.
                res[i-1][j-1] = maxi;
            }
        }
        
        // Return the result matrix containing the largest local values in the input grid.
        return res;
    }
};

/* 
Approach:
    Initialization: The function starts by initializing the result matrix res with dimensions (n-2) x (n-2), where n is the size of the input grid. This is because we are 
    interested in the largest local values within a 3x3 matrix centered around each cell, and we start from the second row and second column to avoid out-of-bounds errors.
    
    Finding Largest Local Values: For each cell in the grid (excluding the first and last rows and columns), the function calculates the largest value within a 3x3 matrix 
    centered around that cell. This is done by comparing the values of the cells in the current row, column, and the cells diagonally adjacent to the current cell.
    
    Storing Results: The largest value found in each 3x3 matrix is stored in the corresponding cell in the result matrix.

Complexity Analysis:
    Time Complexity: The time complexity of the solution is O(n^2). This is because the function iterates through each cell in the grid exactly once, performing constant 
    time operations (max comparisons) for each cell. The number of cells in the grid is proportional to the square of the size of the grid, hence the quadratic time 
    complexity.
    
    Space Complexity: The space complexity of the solution is also O(n^2). This is because the solution creates a new matrix res of the same size as the input grid, 
    excluding the first and last rows and columns, to store the largest local values. The space required for this matrix is proportional to the size of the input grid, hence 
    the quadratic space complexity.


 */