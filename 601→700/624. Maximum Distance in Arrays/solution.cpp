class Solution {
public:
    // Function to compute the maximum distance between elements from different arrays
    int maxDistance(vector<vector<int>>& arrays) {
        // Initialize the smallest element and the biggest element from the first array
        int smallest = arrays[0][0];
        int biggest = arrays[0].back();
        // Variable to keep track of the maximum distance found
        int max_distance = 0;

        // Iterate over the arrays starting from the second array
        for (int i = 1; i < arrays.size(); ++i) {
            // Compute distance between the current array's last element and the smallest element from previous arrays
            max_distance = max(max_distance, abs(arrays[i].back() - smallest));
            // Compute distance between the current array's first element and the biggest element from previous arrays
            max_distance = max(max_distance, abs(biggest - arrays[i][0]));
            // Update the smallest element with the minimum of the current smallest and the first element of the current array
            smallest = min(smallest, arrays[i][0]);
            // Update the biggest element with the maximum of the current biggest and the last element of the current array
            biggest = max(biggest, arrays[i].back());
        }

        // Return the maximum distance found
        return max_distance;
    }
};

/*
Approach Summary:
- Initialize `smallest` and `biggest` with the first array's first and last elements, respectively.
- Iterate through each subsequent array:
  - Calculate potential maximum distances using the current array's elements compared to the smallest and biggest values found so far.
  - Update `smallest` and `biggest` based on the current array's first and last elements.
- Return the largest distance found.

Time Complexity:
- O(n), where n is the total number of elements across all arrays, as each element is processed once.

Space Complexity:
- O(1), as only a few additional variables are used, regardless of the input size.
*/
