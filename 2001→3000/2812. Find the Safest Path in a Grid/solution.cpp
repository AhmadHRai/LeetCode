// this is not a medium problem
class Solution {
public:
    vector<int> rowDir = {-1, 1, 0, 0}; // Directions for moving up/down
    vector<int> colDir = {0, 0, -1, 1}; // Directions for moving left/right

    bool isValid(vector<vector<bool>>& visited, int i, int j) {
        // Check if the cell is valid (within bounds and not visited)
        if (i < 0 || j < 0 || i == visited.size() || j == visited[0].size() || visited[i][j])
            return false;
        return true;
    }
    //============================================================================================================
    bool isSafe(vector<vector<int>>&distToTheif, int safeDist) //check the validity of safenessFactor
    {
        int n = distToTheif.size();
        queue<pair<int, int>>q;
        if (distToTheif[0][0] < safeDist) return false;
        q.push({0, 0});
        vector<vector<bool>>visited(n, vector<bool>(n, false));
        visited[0][0] = true;
        while(!q.empty())
        {
            int currRow = q.front().first, currCol = q.front().second;
            q.pop();
            if (currRow == n - 1 && currCol == n - 1) return true;
            for (int dirIdx = 0; dirIdx < 4; dirIdx++)
            {
                int newRow = currRow + rowDir[dirIdx];
                int newCol = currCol + colDir[dirIdx];
                if (isValid(visited, newRow, newCol))
                {
                    if (distToTheif[newRow][newCol] < safeDist) continue;
                    visited[newRow][newCol] = true;
                    q.push({newRow, newCol});
                }
            }
        }
        return false;
    }
    //===========================================================================================================
    int maximumSafenessFactor(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        queue<pair<int, int>>q;
        vector<vector<bool>>visited(n, vector<bool>(n, false));
        vector<vector<int>>distToTheif(n, vector<int>(n, -1));
        //========================================================================
        //Add all the theives in current queue
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1) 
                {
                    visited[i][j] = true;
                    q.push({i, j});
                }
            }
        }
        //=============================================================================
        //BFS to fill the "DistToTheif" 2D array
        int dist = 0;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int currRow = q.front().first, currCol = q.front().second;
                q.pop();
                distToTheif[currRow][currCol] = dist;
                for (int dirIdx = 0; dirIdx < 4; dirIdx++)
                {
                    int newRow = currRow + rowDir[dirIdx], newCol = currCol + colDir[dirIdx];
                    if (!isValid(visited, newRow, newCol)) continue;
                    
                    visited[newRow][newCol] = true;
                    q.push({newRow, newCol});
                }
            }
            dist++;
        }
        //==================================================================================
        //BINARY SEARCH
        int low = 0, high = INT_MAX;
        int ans = 0;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if (isSafe(distToTheif, mid))
            {
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        //=========================================================================================
        return ans;
        
    }
};

/* 
Approach and Intuition:

    The goal is to find the maximum safeness factor in a grid where thieves are present. The safeness factor is defined as the minimum distance to any thief plus one. The 
    strategy involves finding the shortest paths from every point in the grid to the nearest thief and then determining the maximum safeness factor that ensures safety.

    Distance Calculation: First, perform a breadth-first search (BFS) from each cell marked as a thief to calculate the shortest distances to all other cells. This is done 
    by marking each reachable cell with the distance from the nearest thief.

    Binary Search: Use binary search to find the maximum safeness factor. For each potential safeness factor, check if it is safe by performing another BFS to ensure that no 
    cell is closer to a thief than the safeness factor minus one. If the current safeness factor is safe, update the answer and adjust the lower bound of the binary search 
    range.

Complexity:
    Time Complexity Analysis:
        The BFS for calculating distances takes O(n^2) time, where n is the side length of the grid.
        The binary search runs log(n) times, where n is the upper bound of the safeness factor. In the worst case, this could be O(log(maximum possible safeness factor)).
        Therefore, the overall time complexity is dominated by the BFS step, making it O(n^2).
    Space Complexity Analysis:
        The space required for the BFS queue and the visited array is proportional to the size of the grid, leading to a space complexity of O(n^2).

 */