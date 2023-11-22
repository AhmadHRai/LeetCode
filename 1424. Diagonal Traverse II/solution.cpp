// The class definition for the solution
class Solution {
public:
    // The function that takes a vector of vectors of integers as input and returns a vector of integers that represents the diagonal order traversal of the input
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        // The number of rows in the input vector
        int m = nums.size();
        // A vector that stores the result, initialized to empty
		vector<int> ans;
        // A queue that stores the pairs of row and column indices of the elements to be visited
        queue<pair<int, int>> q;
        // Pushing the first row and first column pair to the queue
        q.push({0,0}); // first row, first cell
		
		// BFS
        // A loop that runs until the queue is empty
        while (!q.empty()) {
            // Popping the front pair from the queue and storing it in a variable
            pair<int, int> p = q.front();
            q.pop();
            // Pushing the value of the element at the popped pair to the result vector
            ans.push_back(nums[p.first][p.second]);
			
			// insert the element below, if in first column
            // Checking if the popped pair is in the first column and the row below it exists
            if (p.second == 0 && p.first+1 < m) 
                // Pushing the pair of row below and same column to the queue
                q.push({p.first+1, p.second});
			
			// insert the right neighbour, if exists
            // Checking if the column to the right of the popped pair exists
            if (p.second+1 < nums[p.first].size())
                // Pushing the pair of same row and column to the right to the queue
                q.push({p.first, p.second+1});
        }
        // Returning the result vector
        return ans;
    }
};
