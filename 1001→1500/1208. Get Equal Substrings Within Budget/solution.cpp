/**
 * Calculates the length of the longest substring where the total cost of transforming
 * string s to string t using abs(s[i] - t[i]) is less than or equal to k.
 *
 * @param s A string representing the original string.
 * @param t A string representing the target string.
 * @param k An integer representing the maximum allowed transformation cost.
 * @return The length of the longest substring with transformation cost ≤ k.
 */
class Solution {
public:
    int equalSubstring(string s, string t, int k) {
        int n = s.length();  // Length of the strings s and t
        int i = 0;  // Left pointer for the sliding window
        int j;      // Right pointer for the sliding window

        // Iterate through the strings with a sliding window approach
        for (j = 0; j < n; ++j) {
            // Update the remaining transformation cost
            k -= abs(s[j] - t[j]);

            // If remaining cost becomes negative, adjust the left pointer
            if (k < 0) {
                // Restore the transformation cost by adding back the cost of the leftmost character
                k += abs(s[i] - t[i++]);
            }
        }

        // Return the length of the longest valid substring found
        return j - i;
    }
};

/* 
    Purpose: 
        The function equalSubstring aims to find the length of the longest substring where the transformation cost (difference between characters in strings s and t) 
        does not exceed a given threshold k.

    Approach:
        Sliding Window Technique: Use two pointers (i and j) to represent the current substring. Move j to expand the window and adjust i to shrink it when the cost exceeds k.
        Cost Calculation: Calculate the transformation cost as abs(s[j] - t[j]) and adjust k accordingly.
        Tracking Length: Track the length of valid substrings (j - i) and return the maximum length found.

    Complexity:
        Time Complexity: O(n) - Linear time complexity, where n is the length of strings s and t.
        Space Complexity: O(1) - Constant space complexity, regardless of the input size.
 */