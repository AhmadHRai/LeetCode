class Solution {
public:
    static constexpr int DIRECTIONS[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int queryCount = queries.size();
        vector<int> result(queryCount);
        int rowCount = grid.size();
        int colCount = grid[0].size();

        int totalCells = rowCount * colCount;
        vector<int> thresholdForMaxPoints(totalCells + 1);

        vector<vector<int>> minValueToReach(rowCount,
                                            vector<int>(colCount, INT_MAX));

        minValueToReach[0][0] = grid[0][0];

        // Min-heap for processing cells in increasing order of their maximum
        // encountered value.
        priority_queue<array<int, 3>, vector<array<int, 3>>,
                       greater<array<int, 3>>>
            minHeap;
        minHeap.push({grid[0][0], 0, 0});
        int visitedCells = 0;

        // Dijkstra's algorithm to compute minValueToReach for each cell
        while (!minHeap.empty()) {
            array<int, 3> current = minHeap.top();
            minHeap.pop();

            // Store the value required to reach `visitedCells` points.
            thresholdForMaxPoints[++visitedCells] = current[0];

            // Explore all possible directions.
            for (const auto& direction : DIRECTIONS) {
                int newRow = current[1] + direction[0];
                int newCol = current[2] + direction[1];

                // Check if the new position is within bounds and not visited
                // before.
                if (newRow >= 0 && newRow < rowCount && newCol >= 0 &&
                    newCol < colCount &&
                    minValueToReach[newRow][newCol] == INT_MAX) {
                    // The max value encountered on the path to this cell.
                    minValueToReach[newRow][newCol] =
                        max(current[0], grid[newRow][newCol]);

                    // Add the cell to the heap for further exploration.
                    minHeap.push(
                        {minValueToReach[newRow][newCol], newRow, newCol});
                }
            }
        }

        // Use binary search to determine the maximum number of points that can
        // be collected for each query.
        for (int i = 0; i < queryCount; i++) {
            int threshold = queries[i];
            int left = 0, right = totalCells;

            // Find the rightmost number of points we can collect before
            // exceeding the query threshold.
            while (left < right) {
                int mid = left + (right - left + 1) / 2;
                if (thresholdForMaxPoints[mid] < threshold) {
                    left = mid;
                } else {
                    right = mid - 1;
                }
            }

            // Return `left`.
            result[i] = left;
        }

        return result;
    }
};