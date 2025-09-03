class Solution {
public:
    // Comparison function to sort by (x, descending order of y)
    static bool cmp(const vector<int>& p, const vector<int>& q) {
        return (p[0] == q[0]) ? p[1] < q[1] : p[0] > q[0];
    }

    // Main function to count the number of valid pairs
    static int numberOfPairs(vector<vector<int>>& P) {
        // Sort points based on the custom comparison function
        sort(P.begin(), P.end(), cmp);

        int n = P.size();
        int ans = 0;

        // Iterate over each point, looking for pairs
        for (int i = 0; i < n - 1; ++i) {
            int y = INT_MAX; // Initialize y to a very large number
            int yi = P[i][1]; // Get the y-coordinate of the current point

            // Find valid pairs for the current point
            for (int j = i + 1; j < n; ++j) {
                int yj = P[j][1]; // Get the y-coordinate of the next point

                // If point j is valid (yj should be less than the current y)
                if (yj >= yi && y > yj) {
                    ++ans; // We found a valid pair
                    y = yj; // Update y for the next iteration
                }
            }
        }

        return ans; // Return the total number of valid pairs
    }
};

// Fast I/O initialization
auto init = []() { 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
