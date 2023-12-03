// Define a class named Solution that contains a public method named minTimeToVisitAllPoints
class Solution {
public:
    // Define the minTimeToVisitAllPoints method that takes a vector of vectors of integers as a parameter and returns an integer
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        // Initialize a variable named ans to store the answer and set it to zero
        int ans = 0;
        // Use a for loop to iterate over the vector of points from the index 1 to the index n-1, where n is the size of the vector
        for(int i = 1; i < points.size(); i++) {
            // Calculate the maximum of the absolute differences between the x-coordinates and the y-coordinates of the current point and the previous point, and add it to the ans variable
            // This is equivalent to finding the Chebyshev distance between the two points, which is the minimum number of steps needed to move from one point to another in a diagonal or orthogonal direction
            ans += max(abs(points[i][1] - points[i - 1][1]), abs(points[i][0] - points[i - 1][0]));
        }
        // Return the ans variable as the final answer
        return ans;
    }
};

/* 
The time complexity of the code is O(n), where n is the number of points, because the for loop takes O(n) time and the calculation of the 
distance takes O(1) time. The space complexity of the code is O(1), because no extra space is used apart from the input vector and some 
variables.
 */