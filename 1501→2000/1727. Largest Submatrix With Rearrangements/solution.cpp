// The class definition for the solution
class Solution {
public:
    // The function that takes a vector of vectors of integers as input and returns the area of the largest submatrix that can be rearranged to have all rows equal
    int largestSubmatrix(vector<vector<int>>& matrix) {
        // The number of rows in the input matrix
        int m = matrix.size();
        // The number of columns in the input matrix
        int n = matrix[0].size();
        // A variable that stores the answer, initialized to zero
        int ans = 0;
        // A vector that stores the height of each column, initialized to zero
        vector<int> height(n, 0);
		
		// view each row and its above as pillars 
        // A loop that iterates over the rows of the matrix
        for(int i = 0; i < m; ++i){
			// calculate heights
            // A loop that iterates over the columns of the matrix
            for(int j = 0; j < n; ++j){
                // If the current element is zero, reset the height of the column to zero
                if(matrix[i][j] == 0) height[j] = 0;
                // Else, increment the height of the column by one
                else height[j] += 1;
            }
			
			// sort pillars
            // A vector that stores the sorted heights of the columns
            vector<int> order_height = height;
            // Sorting the vector in ascending order
            sort(order_height.begin(), order_height.end());
			
			// iterate to get the maxium rectangle
            // A loop that iterates over the sorted heights
            for(int j = 0; j < n; ++j){
                // Updating the answer with the maximum of the current answer and the product of the current height and the number of columns from the current index to the end
                ans = max(ans, order_height[j] * (n - j));
            }
        }
        // Returning the answer
        return ans;
    }
};

/* 
Complexity Analysis:
    Time complexity of this solution is O(m * n log n), where m is the number of rows and n is the number of columns in the input matrix.
        This is because we need to sort the heights of the pillars for each row, which takes O(n log n) time, and iterate over the heights of the pillars for each row, which takes O
        (n) time.
    The space complexity is O(m + n), where m is the number of rows and n is the number of columns in the input matrix.
        This is because we need to store the height vector, which 
        takes O(n) space, and the sorted height vector, which takes O(n) space.
 */