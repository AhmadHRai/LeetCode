class Solution {
public:
    static vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        const int r = box.size(), c = box[0].size(); // Get the number of rows (r) and columns (c) of the box
        // Create a result matrix (rotate) of size c x r to store the rotated box, initialized with '.'
        vector<vector<char>> rotate(c, vector<char>(r, '.'));

        // Iterate through each row of the box
        for(int i = 0; i < r; i++){
            int bottom = c - 1; // Start from the last column of the rotated box (bottom is the current available position for rocks)
            
            // Iterate through each column in the current row from right to left
            for(int j = c - 1; j >= 0; j--){
                if (box[i][j] == '#'){ // If the current cell is a rock ('#')
                    rotate[bottom][r - 1 - i] = '#'; // Place the rock in the rotated box at the correct position
                    bottom--; // Move leftward to the next available space for a rock
                }
                else if (box[i][j] == '*'){ // If the current cell is an obstacle ('*')
                    rotate[j][r - 1 - i] = '*'; // Place the obstacle in the rotated box
                    bottom = j - 1; // Set the next available position to the left of the obstacle
                }
            }
        }
        return rotate; // Return the final rotated box
    }
};

// Initialization block to optimize input/output handling
auto init = []()
{ 
    ios::sync_with_stdio(0); // Disable synchronization with C-style I/O for faster input/output
    cin.tie(0); // Untie cin from cout to improve performance
    cout.tie(0); // Untie cout from cin to improve performance
    return 'c'; // Return a dummy value to execute the initialization
}();
