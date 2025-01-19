#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Function to calculate the amount of rainwater that can be trapped
    int trapRainWater(vector<vector<int>>& heightMap) {
        // Check if the heightMap is empty or has no columns
        if (heightMap.empty() || heightMap[0].empty()) {
            return 0; // No water can be trapped
        }

        int m = heightMap.size(); // Number of rows
        int n = heightMap[0].size(); // Number of columns
        
        // If the grid is too small to trap water
        if (m < 3 || n < 3) {
            return 0; // Cannot trap water in a grid smaller than 3x3
        }

        // Min-heap to store the boundary cells (height, (row, column))
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;
        
        // Mark visited cells with a boolean matrix
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Add all boundary cells to the heap and mark them as visited
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) { // Check for boundary cells
                    minHeap.push({heightMap[i][j], {i, j}}); // Push cell height and coordinates into the heap
                    visited[i][j] = true; // Mark as visited
                }
            }
        }

        int res = 0; // Variable to store the total trapped water volume
        int level = 0; // Variable to track the current water level

        // Directions for exploring adjacent cells (up, down, left, right)
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Process the cells in the min-heap
        while (!minHeap.empty()) {
            auto [height, cell] = minHeap.top(); // Get the cell with the smallest height
            minHeap.pop(); // Remove it from the heap
            int x = cell.first, y = cell.second; // Extract row and column indices

            // Update the current water level based on the cell's height
            level = max(level, height);

            // Explore neighboring cells
            for (auto& dir : directions) {
                int i = x + dir.first, j = y + dir.second; // Calculate neighbor coordinates
                if (i >= 0 && i < m && j >= 0 && j < n && !visited[i][j]) { // Check bounds and visited status
                    // If the neighbor's height is lower than the current water level, calculate trapped water
                    if (heightMap[i][j] < level) {
                        res += level - heightMap[i][j]; // Add trapped water volume to result
                    }
                    // Push the neighboring cell into the heap with its height
                    minHeap.push({heightMap[i][j], {i, j}});
                    visited[i][j] = true; // Mark neighbor as visited
                }
            }
        }

        return res; // Return total trapped water volume
    }
};

/*
Approach Summary:
The function calculates how much rainwater can be trapped in a terrain represented by a matrix of heights. It uses a priority queue (min-heap) to process boundary cells first. As it explores neighboring cells from the lowest boundary upwards, it calculates potential trapped water based on the difference between the current water level and neighboring heights. The total trapped water volume is accumulated and returned.

Complexity Analysis:
- Time Complexity: O(M * N * log(M * N)), where M is the number of rows and N is the number of columns in `heightMap`. Each cell is processed once and inserted into the priority queue.
- Space Complexity: O(M * N), for storing visited status and for the priority queue holding all cells.
*/
