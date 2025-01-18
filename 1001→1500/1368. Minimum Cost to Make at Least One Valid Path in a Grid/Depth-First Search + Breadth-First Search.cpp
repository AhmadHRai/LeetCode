class Solution {
private:
    // Direction vectors: right, left, down, up (matching grid values 1,2,3,4)
    const vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    int minCost(vector<vector<int>>& grid) {
        int numRows = grid.size(), numCols = grid[0].size(), cost = 0;

        // Track minimum cost to reach each cell
        vector<vector<int>> minCost(numRows, vector<int>(numCols, INT_MAX));

        // Queue for BFS part - stores cells that need cost increment
        queue<pair<int, int>> queue;

        // Start DFS from origin with cost 0
        dfs(grid, 0, 0, minCost, cost, queue);

        // BFS part - process cells level by level with increasing cost
        while (!queue.empty()) {
            cost++;
            int levelSize = queue.size();

            while (levelSize-- > 0) {
                auto [row, col] = queue.front();
                queue.pop();

                // Try all 4 directions for next level
                for (int dir = 0; dir < 4; dir++) {
                    dfs(grid, row + dirs[dir][0], col + dirs[dir][1], minCost,
                        cost, queue);
                }
            }
        }

        return minCost[numRows - 1][numCols - 1];
    }

private:
    // DFS to explore all reachable cells with current cost
    void dfs(vector<vector<int>>& grid, int row, int col,
             vector<vector<int>>& minCost, int cost,
             queue<pair<int, int>>& queue) {
        if (!isUnvisited(minCost, row, col)) return;

        minCost[row][col] = cost;
        queue.push({row, col});

        // Follow the arrow direction without cost increase
        int nextDir = grid[row][col] - 1;
        dfs(grid, row + dirs[nextDir][0], col + dirs[nextDir][1], minCost, cost,
            queue);
    }

    // Check if cell is within bounds and unvisited
    bool isUnvisited(vector<vector<int>>& minCost, int row, int col) {
        return row >= 0 && col >= 0 && row < minCost.size() &&
               col < minCost[0].size() && minCost[row][col] == INT_MAX;
    }
};

/*  
Complexity Analysis

Let n be the number of rows and m be the number of columns in the grid.

    Time Complexity: O(n⋅m)

    The algorithm uses a hybrid DFS-BFS approach. In the DFS part, each cell is visited at most once when following zero-cost paths (following arrows). In the BFS part, each cell might be added to the queue once for exploration in different directions, but again, each cell is processed at most once since we only visit unvisited cells. Since each cell can only be visited once in both phases, and for each cell, we perform constant time operations, the total time complexity is O(n⋅m).

    Space Complexity: O(n⋅m)

    The algorithm uses multiple data structures that each can grow up to O(n⋅m): the minCost array to track visited cells, the queue for BFS that in the worst case might contain all cells, and the recursive call stack for DFS that in worst case might go through all cells in a snake-like pattern. Thus, the total space complexity is O(n⋅m).

*/