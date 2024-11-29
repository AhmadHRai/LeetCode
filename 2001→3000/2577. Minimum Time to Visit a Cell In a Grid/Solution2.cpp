using info = pair<int, int>; // Define a pair to hold (time, index)
const static int d[5] = {0, 1, 0, -1, 0}; // Direction vectors for moving in the grid

class Solution {
public:
    // Check if the given coordinates are outside the grid boundaries
    inline static bool isOutside(int i, int j, int n, int m) {
        return i < 0 || i >= n || j < 0 || j >= m;
    }

    // Convert 2D coordinates (i, j) to a single index for easier storage
    inline static int idx(int i, int j, int m) { 
        return i * m + j; 
    }

    // Function to find the minimum time to reach the bottom-right cell
    int minimumTime(vector<vector<int>>& grid) {
        // Check for immediate impossibility to move to (1, 0) or (0, 1)
        if (grid[1][0] > 1 && grid[0][1] > 1)
            return -1; // Return -1 if both paths are blocked

        const int n = grid.size(), m = grid[0].size(), N = 100000; // Dimensions and constant for max size
        int time[N]; // Array to store minimum time to reach each cell
        fill(time, time + n * m, INT_MAX); // Initialize all times to infinity

        uint64_t pq[N]; // Priority queue implemented as an array
        int back = 0; // Index for the back of the queue

        // Start at (0, 0) with time=0
        pq[back++] = 0; // Push initial state into the queue
        time[0] = 0; // Set time for starting cell

        while (back > 0) {
            pop_heap(pq, pq + back, greater<>{}); // Retrieve the cell with the minimum time
            auto tij = pq[--back]; // Get and remove this cell from the queue
            
            // Extract time and index from tij
            int t = tij >> 32; 
            int ij = tij & ((1 << 30) - 1); 
            int i = ij / m; // Row index
            int j = ij - i * m; // Column index

            // Check if we've reached the destination cell
            if (i == n - 1 && j == m - 1)
                return t; // Return the time taken to reach this cell

            // Explore all four possible directions from the current cell
            for (int a = 0; a < 4; a++) {
                int r = i + d[a], s = j + d[a + 1]; // Calculate new coordinates
                
                if (isOutside(r, s, n, m)) 
                    continue; // Skip if out of bounds

                // Determine whether we need to wait before moving to (r, s)
                int w = ((grid[r][s] - t) & 1) ? 0 : 1; 
                int nextTime = max(t + 1, grid[r][s] + w); // Calculate next visitable time

                // Update if this path offers a quicker time to reach (r, s)
                int rs = idx(r, s, m); 
                if (nextTime < time[rs]) {
                    time[rs] = nextTime; // Update the minimum time for this cell
                    pq[back++] = ((uint64_t)nextTime << 32) + rs; // Store new state in the queue
                    push_heap(pq, pq + back, greater<>{}); // Maintain heap property
                }
            }
        }

        return -1; // Return -1 if we cannot reach the bottom-right cell
    }
};

/*
Approach:
    We uses a **modified Dijkstra's algorithm** approach with a **priority queue** implemented as an array. The algorithm efficiently finds the minimum time required to traverse from the top-left corner of the grid to the bottom-right corner by exploring neighboring cells based on their visitable times. The key idea is to prioritize cells that can be visited sooner while considering both movement and waiting times dictated by each cell's value.

Complexity Analysis:
    Time Complexity: O(m * n * log(m * n)), where m is the number of rows and n is the number of columns. Each cell can be pushed into the priority queue once.
    Space Complexity: O(m * n) for storing the minimum times and managing the priority queue.

Notes: while both solution1 and this exhibit similar theoretical complexities, practical implementation choices regarding data structures, memory management, algorithmic optimizations, and compiler settings can lead to significant differences in runtime performance. This solution's design decisions enhance its efficiency in real-world scenarios, making it substantially faster than the first.
*/
