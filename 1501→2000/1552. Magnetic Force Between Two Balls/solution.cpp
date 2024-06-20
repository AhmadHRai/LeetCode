class Solution {
public:
    int n;  // Number of positions in the input array

    // Function to check if we can place 'm' balls with at least 'force' distance apart
    inline bool f(int force, vector<int>& position, int m) {
        int x = position[0];  // Starting position of the first ball
        int balls = 1;  // Number of balls placed, starting with the first ball

        // Iterate through positions to check if we can place all 'm' balls
        for (int i = 1; i < n && balls <= m; i++) {
            if (position[i] - x >= force) {
                x = position[i];  // Place a new ball at position[i]
                balls++;  // Increment the count of placed balls
            }
        }
        return balls >= m;  // Return true if we can place 'm' or more balls
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());  // Sort the positions

        const int I = position.back() - position[0];  // Maximum possible distance
        n = position.size();  // Update the number of positions

        // Special cases
        if (n == 2) return I;  // If there are only two positions, return the maximum distance
        int minf = INT_MAX;  // Minimum distance between any two positions

        // Calculate the minimum distance between consecutive positions
        for (int i = 1; i < n; i++)
            minf = min(minf, position[i] - position[i - 1]);

        if (n == m) return minf;  // If number of positions equals 'm', return the minimum distance

        // Binary search for the maximum possible minimum distance
        int l = minf, r = (I + m - 2) / (m - 1), mid, best = l;

        while (l <= r) {
            mid = l + (r - l) / 2;  // Calculate the middle value
            if (f(mid, position, m)) {
                best = mid;  // Update the best distance found so far
                l = mid + 1;  // Try for a larger distance
            } else {
                r = mid - 1;  // Try for a smaller distance
            }
        }
        return best;  // Return the best distance found
    }
};

/*
Approach:
- Sort the array of positions.
- Determine the maximum possible distance (I) and the minimum distance (minf) between consecutive positions.
- If there are only two positions, return the maximum distance between them.
- If the number of positions equals 'm', return the minimum distance between any two positions.
- Perform a binary search to find the maximum possible minimum distance such that we can place 'm' balls with at least 'force' distance apart.
- Use a helper function 'f' to check if we can place all 'm' balls with the given 'force'.
- Update 'best' with the mid value and adjust 'l' and 'r' based on whether placing 'm' balls is possible.
- Return the best distance found.

Complexity Analysis:
- Time Complexity: O(n log I), where n is the number of positions and I is the maximum possible distance between any two positions.
  - Sorting takes O(n log n) time.
  - Binary search takes O(log I) time, where I can be up to (position[n-1] - position[0]).
  - Checking feasibility with 'f' takes O(n) time.
- Space Complexity: O(1) extra space, excluding input space.
  - Only a few extra variables are used, independent of the input size.
*/
