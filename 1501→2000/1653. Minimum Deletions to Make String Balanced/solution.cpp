class Solution {
public:
    // Function to calculate the minimum number of deletions required
    int minimumDeletions(string s) {
        int n = s.size(); // Get the size of the string
        int f[n + 1]; // Array to store the minimum deletions at each position
        memset(f, 0, sizeof(f)); // Initialize the array with zeros
        int b = 0; // Counter for the number of 'b' characters encountered
        // Iterate over each character in the string
        for (int i = 1; i <= n; ++i) {
            // If the current character is 'b'
            if (s[i - 1] == 'b') {
                f[i] = f[i - 1]; // No need to delete if it's 'b'
                ++b; // Increment the count of 'b's
            } else {
                // Calculate the minimum deletions required
                f[i] = min(f[i - 1] + 1, b);
            }
        }
        return f[n]; // Return the minimum deletions required for the entire string
    }
};

/*
Approach:
- Use dynamic programming to keep track of the minimum deletions required up to each position in the string.
- Maintain an array `f` where `f[i]` represents the minimum deletions needed for the substring `s[0...i-1]`.
- Track the number of 'b' characters encountered as `b`.
- For each character in the string:
  - If it is 'b', the minimum deletions required up to that position remains the same as the previous position (`f[i] = f[i - 1]`).
  - If it is not 'b', update `f[i]` to be the minimum of either deleting this character (i.e., `f[i - 1] + 1`) or the number of 'b' characters encountered so far (`b`).

Complexity Analysis:
- Time Complexity: O(n), where n is the length of the string. We iterate through the string once.
- Space Complexity: O(n), due to the array `f` used to store the minimum deletions up to each position.
*/
