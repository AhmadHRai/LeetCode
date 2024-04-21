class Solution {
public:
    // This function takes an image as a 2D vector of integers and returns a smoothed image
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        // Get the dimensions of the image
        int n = img.size(), m = img[0].size();
        // Create a new 2D vector to store the smoothed image
        vector<vector<int> > ans(n, vector<int> (m, 0));    
        // Loop over each pixel in the original image
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // Initialize the sum and count of the neighboring pixels
                int sum = 0, cnt = 0;
                // Loop over the 3x3 grid centered at the current pixel
                for (int dx = -1; dx <= 1; ++dx) {
                    for (int dy = -1; dy <= 1; ++dy) {
                        // Calculate the coordinates of the neighboring pixel
                        int nx = dx + i, ny = dy + j;
                        // Check if the neighboring pixel is valid and within the image boundaries
                        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                        // Increment the count of the valid neighbors
                        ++cnt;
                        // Add the value of the neighboring pixel to the sum
                        sum += img[nx][ny];
                    }
                }
                // Calculate the average value of the neighboring pixels and assign it to the smoothed image
                ans[i][j] = sum / cnt;
            }
        }
        // Return the smoothed image
        return ans;
    }
};

/* 
The time complexity of the code is O(n . m), where n and m are the 
dimensions of the input image. This is because we iterate over each 
pixel in the image once, and perform constant-time operations in 
each iteration.

The space complexity of the code is O(n . m), because we create a 
new 2D vector of the same size as the input image to store the 
smoothed image. We do not use any other data structures or allocate 
any dynamic memory.
*/