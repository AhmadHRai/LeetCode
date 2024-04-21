# Define a class named Solution
class Solution:
    # Define a method named onesMinusZeros that takes a grid of binary numbers as input and returns a grid of differences as output
    def onesMinusZeros(self, grid: List[List[int]]) -> List[List[int]]:
        # Get the number of rows in the grid
        m = len(grid)
        # Get the number of columns in the grid
        n = len(grid[0])
        # Initialize a result grid with the same size as the input grid and fill it with zeros
        res = [[0] * n for _ in range(m)]
        # Count the number of ones in each row of the input grid and store it in a list
        ones_row = [row.count(1) for row in grid]
        # Count the number of ones in each column of the input grid and store it in a list
        ones_col = [col.count(1) for col in zip(*grid)]

        # Loop through each cell of the input grid
        for i in range(m):
            for j in range(n):
                # Calculate the difference between the number of ones and zeros in the current cell
                # The formula is: ones in the same row + ones in the same column - zeros in the same row - zeros in the same column
                # Zeros in the same row = m - ones in the same row
                # Zeros in the same column = n - ones in the same column
                res[i][j] = ones_row[i] + ones_col[j] - (m - ones_row[i]) - (n - ones_col[j])

        # Return the result grid
        return res



""" 
Approach

    1. Initialize arrays rowOnes and colOnes to store the count of ones in each row and each column, respectively.
    2. Traverse the grid matrix to populate the rowOnes and colOnes arrays.
    3. Iterate through the grid matrix again and calculate each element of the diff matrix using the provided formula.
    4. Update each element of the grid matrix with the calculated difference.
    5. Return the modified grid matrix as the resulting diff.
    

Complexity

    Time complexity: O(m x n), where (m) is the number of rows and (n) is the number of columns in the grid matrix.
    Space complexity: (O(m + n) for the rowOnes and colOnes arrays.
"""