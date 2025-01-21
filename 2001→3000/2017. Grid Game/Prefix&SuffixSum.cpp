class Solution {
    public:
        long long gridGame(vector<vector<int>>& grid) {
            long long firstRowSum = accumulate(begin(grid[0]), end(grid[0]), 0LL),
                      secondRowSum = 0;
            long long minimumSum = LONG_LONG_MAX;
            for (int turnIndex = 0; turnIndex < grid[0].size(); ++turnIndex) {
                firstRowSum -= grid[0][turnIndex];
                // Find the minimum maximum value out of firstRowSum and
                // secondRowSum.
                minimumSum = min(minimumSum, max(firstRowSum, secondRowSum));
                secondRowSum += grid[1][turnIndex];
            }
            return minimumSum;
        }
    };

/* 
Algorithm

    Initialize firstRowSum with the sum of all elements in the first row of grid. Initialize secondRowSum as 0.

    Set minimumSum to a very large value (LONG_LONG_MAX).

    Iterate through the indices of the first row:
        Subtract the current element of the first row from firstRowSum.
        Calculate the maximum value between firstRowSum and secondRowSum; This would be the highest number of points the second robot can get if the first robot turns down at the current index.
        Update minimumSum with the smaller value between minimumSum and the calculated maximum.
        Add the current element of the second row to secondRowSum.

    Return minimumSum.

Complexity Analysis
    Let n be the number of columns in the grid.

    Time Complexity: O(n)
        The algorithm iterates through each column of the grid exactly once. For each column, it updates the sums of the first and second rows and computes the minimum of the 
        maximum values. These operations take constant time for each column. Therefore, the overall time complexity is O(n).

    Space Complexity: O(1)
        The algorithm uses a constant amount of extra space, including variables for firstRowSum, secondRowSum, and minimumSum. No additional data structures proportional to 
        the size of the input are used. Thus, the overall space complexity is O(1).
*/