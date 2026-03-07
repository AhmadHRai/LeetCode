class Solution {
public:
    int minFlips(string s) {
        int n = s.size();      // Length of the original string
        int ans1 = 0, ans2 = 0;  // Counters for flips needed for both alternating patterns
        int minFlips = INT_MAX;   // To store the minimum flips required

        // Iterate over the string, treating it as if it's doubled
        for (int i = 0; i < 2 * n; i++) {

            // Convert characters to integers ('0' -> 0, '1' -> 1) only for the first n elements
            if (i < n) s[i] -= '0';  // For the first half, make the string contain integers 0 or 1

            // Check if the character at position i matches the expected alternating pattern
            // Pattern 1: '010101...'
            if (i % 2 != s[i % n]) ++ans1;  // Increment ans1 if the current character doesn't match

            // Pattern 2: '101010...'
            if ((i + 1) % 2 != s[i % n]) ++ans2;  // Increment ans2 if the current character doesn't match

            // Remove the effect of characters outside the sliding window
            if (i >= n) {
                // Undo the changes made by characters that are no longer in the window
                if ((i - n) % 2 != s[i - n]) --ans1;
                if ((i - n + 1) % 2 != s[i - n]) --ans2;
            }

            // After processing the full window, update the minimum number of flips required
            if (i >= n - 1) {
                minFlips = min({ans1, ans2, minFlips});
            }
        }

        return minFlips;  // Return the minimum number of flips required
    }
};
