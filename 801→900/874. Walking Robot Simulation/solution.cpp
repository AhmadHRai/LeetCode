#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // Function to simulate robot movements and return the maximum squared distance from the origin
    static int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        const long long M = 60001, lb = -30000; // Constants for coordinate transformation
        unordered_set<long long> obSet; // Set to store obstacles
        obSet.reserve(obstacles.size()); // Reserve space in the set for obstacles

        // Transform and store obstacles in the set
        for (auto& ob : obstacles) {
            long long x = ob[0] - lb, y = ob[1] - lb;
            obSet.insert(x * M + y); // Unique identifier for obstacle
        }

        // Directions: 0 = North, 1 = West, 2 = South, 3 = East
        const int dir[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
        int x = 0, y = 0, dx = 0, dy = 1, face = 0, maxD2 = 0; // Initialize robot position and direction

        // Process each command
        for (int c : commands) {
            switch (c) {
                case -2: // Turn left
                    face = (face + 1) % 4;
                    dx = dir[face][0];
                    dy = dir[face][1];
                    break;
                case -1: // Turn right
                    face = (face + 3) % 4;
                    dx = dir[face][0];
                    dy = dir[face][1];
                    break;
                default: // Move forward
                    for (int i = 0; i < c; i++) {
                        x += dx;
                        y += dy;
                        if (obSet.count((x - lb) * M + (y - lb))) {
                            x -= dx; // Undo move
                            y -= dy;
                            break;
                        }
                        maxD2 = max(maxD2, x * x + y * y); // Update maximum distance squared
                    }
            }
        }

        return maxD2; // Return the maximum squared distance from the origin
    }
};

/*
Approach Summary:
- Convert obstacle coordinates to a transformed coordinate system to handle negative values and large coordinates.
- Use a hash set to store obstacles for O(1) lookup time.
- Simulate robot movements based on commands and update its position while checking for obstacles.
- Track the maximum squared distance from the origin.

Time Complexity:
- O(N + M), where N is the number of commands and M is the number of obstacles. The function processes each command and obstacle in linear time.

Space Complexity:
- O(M), where M is the number of obstacles. Space is used to store obstacle coordinates in the set.
*/
