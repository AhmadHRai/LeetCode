class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        // Initialize a 2D array to represent the glasses, all set to 0
        vector<vector<double>> glasses(101, vector<double>(101, 0));
        
        // Pour the initial amount of champagne into the top glass
        glasses[0][0] = double(poured);
        
        // Simulate the pouring process row by row
        for (int row = 0; row <= query_row; ++row) {
            for (int glass = 0; glass <= row; ++glass) {
                // Calculate the excess champagne for the current glass
                double excess = (glasses[row][glass] - 1.0) / 2.0;
                
                // If there's excess, distribute it to the glasses below
                if (excess > 0) {
                    glasses[row + 1][glass] += excess;
                    glasses[row + 1][glass + 1] += excess;
                }
            }
        }
        
        // Ensure the champagne in the target glass doesn't exceed 1.0
        return min(1.0, glasses[query_row][query_glass]);
    }
};

// Time Complexity: O(query_row^2)
// Space Complexity: O(1)
