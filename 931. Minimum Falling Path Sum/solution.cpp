// Solution from gballoccu : https://leetcode.com/problems/minimum-falling-path-sum/solutions/1191340/c-4-solutions-from-bruteforce-to-dp-with-explainations
/* 
[C++] 4 Solutions from bruteforce to dp with explainations
Let's start from the brute force, a good way is to think is a recursive fashion which helps to understand the base cases and how to implement the iterative one.

If we start from the row 1 in the matrix we need to pick for every position of the matrix the min value between:

    Matrix[r-1][c-1] + matrix[r][c] which means we have reach pos [r][c] from left
    Matrix[r-1][c+1] + matrix[r][c] which means we have reach pos [r][c] from right
    Matrix[r-1][c] + matrix[r][c] which means we have reach pos [r][c] from the middle

Between these we need to pick the minimum, paying attention to the matrix indexes (Don't get out of boundaries) which reppresent a base case for the recursive calls.
The other base case is when we reach the end so r = 0 in the case of the brute force.

After having calculate the minimum value that lead to all the positions matrix[rows-1][c] we can just iterate through those values and take the max.

Here is the brute force using recursion.
 */

 //Brute force TLE
class Solution {
public:
        int minFallingPathSumHelper(vector<vector<int>>& matrix, int r, int c){
        if(r == 0 and c < matrix[0].size() and c >= 0) return matrix[r][c]; 
        if(c >= matrix[0].size() or c < 0) return INT_MAX;
        
        return matrix[r][c] + min(min(minFallingPathSumHelper(matrix, r-1, c+1), minFallingPathSumHelper(matrix, r-1, c)), minFallingPathSumHelper(matrix, r-1, c-1));
        
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        int ans = INT_MAX;
        for(int c=0; c < cols; c++){
            ans = min(ans, minFallingPathSumHelper(matrix, rows-1, c));
        }
        return ans;
    }
};

/* 
Something you can note is that we are reapeting a bunch of calls, we can optimize using a memo that keeps the values for the position which are 
already calculated. We just need to initialize the memo with a value, INT_MAX since we can have also negative numbers. And if we haven't 
calculated the value yet we do recursion as in the bruteforce otherwise we hit the cache.
 */

//Top-down Recursive with memo
class Solution {
public:
    int minFallingPathSumHelper(vector<vector<int>>& matrix, int r, int c, vector<vector<int>>& dp){
        if(r == 0 and c < matrix[0].size() and c >= 0) return matrix[r][c]; 
        if(c >= matrix[0].size() or c < 0) return INT_MAX;
        
        if(dp[r][c] != INT_MAX) return dp[r][c];
        return dp[r][c] = matrix[r][c] + min(min(minFallingPathSumHelper(matrix, r-1, c+1, dp), minFallingPathSumHelper(matrix, r-1, c, dp)), minFallingPathSumHelper(matrix, r-1, c-1, dp));
        
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> dp(rows+1, vector<int>(cols+1, INT_MAX));
        int ans = INT_MAX;
        for(int c=0; c < cols; c++){
            ans = min(ans, minFallingPathSumHelper(matrix, rows-1, c, dp));
        }
        return ans;
    }
};

/* 
As I was saying before you can rethink the logic in the opposite way in a bottom-up fashion:
 */

  //Bottom-up Recursive with memo
class Solution {
public:
    int minFallingPathSumHelper(vector<vector<int>>& matrix, int r, int c, vector<vector<int>>& dp){
        if(r == matrix.size()-1 and c < matrix[0].size() and c >= 0) return matrix[r][c]; 
        if(c >= matrix[0].size() or c < 0) return INT_MAX;
        
        if(dp[r][c] != INT_MAX) return dp[r][c];
        return dp[r][c] = matrix[r][c] + min(min(minFallingPathSumHelper(matrix, r+1, c-1, dp), minFallingPathSumHelper(matrix, r+1, c, dp)), minFallingPathSumHelper(matrix, r+1, c+1, dp));
        
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> dp(rows+1, vector<int>(cols+1, INT_MAX));
        int ans = INT_MAX;
        for(int c=0; c < cols; c++){
            ans = min(ans, minFallingPathSumHelper(matrix, 0, c, dp));
        }
        return ans;
    }
};

/* 
The last two solutions make use of a memo called dp which store preview calculation + occupies space with the recursive calls. So we can say that it takes O(mn) time and O(mn) extra space.

Another approach could be (in the case you're allowed to modify the input to store directly the calculation of the minimum path until that position directly in the matrix. This would need O(mn) time and O(1) extra space.
The following solution can be adapted using a copy of the matrix to not modify the input using O(mn) space.
 */

//Iterative bottom-up solution
class Solution {
public:
    int customMin(int a, int b, int c){
        return min(a,min(b,c));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        int ans = INT_MAX;
        
        for(int r=1; r < rows; r++){
            for(int c=0; c < cols; c++){
                int leftD, middle, rightD;               
                if(c == 0){
                    rightD = matrix[r-1][c+1];
                    middle = matrix[r-1][c];
                    matrix[r][c] += min(rightD, middle);
                }else if(c == cols-1){
                    leftD = matrix[r-1][c-1];
                    middle = matrix[r-1][c];
                    matrix[r][c] += min(leftD, middle);
                }else{
                    leftD = matrix[r-1][c+1];
                    middle = matrix[r-1][c];
                    rightD = matrix[r-1][c-1];
                    matrix[r][c] += customMin(leftD, rightD, middle);
                } 
            }
        }
        for(int c=0; c < cols; c++){
            ans = min(ans, matrix[rows-1][c]);
        }
        return ans;
    }
};

// In general iterative is harder to think but it's almost always better.