/* 
Approach:
    For each row, calculate the prefix sum.
    For each pair of columns,
    calculate the accumulated sum of rows.
    Now this problem is same to, "Find the Subarray with Target Sum".
 */

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& A, int target) {
        int res = 0, m = A.size(), n = A[0].size();
        /* calculate prefix sum for each row
        For this double-for loop, we are calculating the prefix sum for each row in the matrix, which will be used later */
        for (int i = 0; i < m; i++)
            for (int j = 1; j < n; j++)
                A[i][j] += A[i][j - 1];

        unordered_map<int, int> counter;
        
        /* for every possible range between two columns, accumulate the prefix sum of submatrices that can be formed between these two columns by adding up the sum of values 
        between these two columns for every row */

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                counter = {{0,1}};
                int cur = 0;
                for (int k = 0; k < m; k++) {
                    cur += A[k][j] - (i > 0 ? A[k][i - 1] : 0);
                    res += counter.find(cur - target) != counter.end() ? counter[cur - target] : 0;
                    counter[cur]++;
                }
            }
        }
        return res;
    }
};

/* 
Complexity:

    Time complexity is:
         O(m^2 n), where m is the number of rows and n is the number of columns in the matrix A. The reason is that this code uses three nested loops to iterate 
        over the matrix A. The outermost loop runs from 0 to n-1, the middle loop runs from i to n-1, and the innermost loop runs from 0 to m-1. Therefore, the total number of iterations is:

            sum_{i=0}^{n-1} (n-i) * m = m * sum_{i=0}^{n-1} (n-i) = m * (n * (n+1) / 2 - sum_{i=0}^{n-1} i) = m * (n * (n+1) / 2 - n * (n-1) / 2) = m * n * (n+1 - n + 1) / 2 = m * n * 2 / 2 = m * n

        This is equivalent to O (m * n^2), which is the same as O (m^2 n) since m and n are interchangeable.


    The space complexity of the code is O(m), where m is the number of rows in the matrix A. This is because the code uses a list of sets to store the possible concatenations of 
    the strings, and the size of the list is bounded by the number of rows. The code also uses some auxiliary variables, but they do not affect the overall space complexity.
 */