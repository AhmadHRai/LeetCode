class Solution {
    public:
        int countServers(vector<vector<int>>& grid) 
        {
            // Get the number of rows and columns in the grid
            int R = grid.size(), C = grid[0].size();
            
            // Initialize vectors to store row and column counts of servers
            vector<int> rowCount(R, 0), colCount(C, 0);
            
            // Initialize the answer variable to count connected servers
            int ans = 0;
            
            // First pass: Count servers in each row and column and initialize the total count
            for(int i=0 ; i<R ; i++)
                for(int j=0 ; j<C ; j++)
                    // If a server is found, increment the row and column counts and the total count
                    if(grid[i][j])
                        rowCount[i]++, colCount[j]++, ans++;
            
            // Second pass: Subtract isolated servers from the total count
            for(int i=0 ; i<R ; i++)
                for(int j=0 ; j<C ; j++)
                    // If a server is isolated (only one in its row and column), decrement the total count
                    if(grid[i][j] and rowCount[i] == 1 and colCount[j] == 1)
                        ans--;
            
            // Return the final count of connected servers
            return ans;
        }
    } 
    /*
    Approach Summary:
    This solution involves two passes over the grid. The first pass counts the number of servers in each row and column and initializes the total count of servers. The second pass identifies isolated servers (those that are the only server in their row and column) and subtracts them from the total count, as they are not connected to any other server.
    
    Complexity Analysis:
    - Time Complexity: O(R*C), where R is the number of rows and C is the number of columns in the grid. This is because we perform two passes over the grid.
    - Space Complexity: O(R+C), for storing the row and column counts.
    */
    