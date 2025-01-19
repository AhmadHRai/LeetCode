class Solution {
public:
    // Function to calculate the volume of water that can be trapped after raining
    int trapRainWater(vector<vector<int>>& heights) {
        int vol = 0; // Variable to store the total volume of trapped water
        const int M = heights.size(); // Number of rows in the heights matrix
        const int N = heights[0].size(); // Number of columns in the heights matrix
        
        // 2D vector to keep track of visited cells
        vector<vector<bool>> visited(M, vector<bool>(N, false));
        
        // Directions for exploring neighboring cells (right, left, down, up)
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        // Comparator for the priority queue to create a min-heap based on height
        auto comp = [&](const array<int, 3>& a, const array<int, 3>& b) { return a[0] >= b[0]; };
        
        // Priority queue to store cells as <height, row, col>
        priority_queue<array<int, 3>, vector<array<int, 3>>, decltype(comp)> min_heap(comp);
        
        // Add all boundary cells to the min-heap
        // Top and bottom boundary cells
        for(int i = 0; i < N; i++) {
            min_heap.push({heights[0][i], 0, i}); // Top row
            min_heap.push({heights[M-1][i], M-1, i}); // Bottom row
            visited[0][i] = true; // Mark top row as visited
            visited[M-1][i] = true; // Mark bottom row as visited
        }
        
        // Left and right boundary cells
        for(int i = 0; i < M; i++) {
            min_heap.push({heights[i][0], i, 0}); // Left column
            min_heap.push({heights[i][N-1], i, N-1}); // Right column
            visited[i][0] = true; // Mark left column as visited
            visited[i][N-1] = true; // Mark right column as visited
        }
            
        while(!min_heap.empty()) {
            auto [height, row, col] = min_heap.top(); // Get cell with the smallest height
            min_heap.pop();
            
            // Explore neighboring cells
            for(auto dir: directions) {
                int r = row + dir[0], c = col + dir[1]; // Calculate neighbor coordinates
                
                // Process the inner cell if it's within bounds and not visited
                if(r >= 0 && r < M && c >= 0 && c < N && !visited[r][c]) {
                    // Mark current cell as visited
                    visited[r][c] = true;
                    
                    // If current height is less than the height from which we came,
                    // it can store water equal to the difference in height.
                    if(heights[r][c] < height)
                        vol += height - heights[r][c]; // Add trapped water volume
                    
                    // Push the maximum height between current cell and incoming height to the heap
                    min_heap.push({max(height, heights[r][c]), r, c});
                }
            }
        }
        
        return vol; // Return total volume of trapped water
    }
};

/*
Approach Summary:
The function calculates the amount of water that can be trapped after raining on a terrain represented by a matrix of heights. It uses a priority queue (min-heap) to process boundary cells first and explores their neighbors. If a neighboring cell is lower than the current cell's height, it can trap water. The algorithm keeps track of visited cells to avoid processing them multiple times. The total volume of trapped water is accumulated and returned.

Complexity Analysis:
- Time Complexity: O(M * N * log(M * N)), where M is the number of rows and N is the number of columns in the heights matrix. Each cell is processed once and inserted into the priority queue.
- Space Complexity: O(M * N), for storing visited status and for the priority queue holding all cells.
*/
