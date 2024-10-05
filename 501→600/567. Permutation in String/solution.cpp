#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // Step 1: Check if s1 is longer than s2; if so, return false
        if (s1.size() > s2.size()) return false;
        
        // Step 2: Create frequency vectors for s1 and s2
        vector<int> s1v(26, 0); // Frequency of characters in s1
        for (auto c : s1) s1v[c - 'a']++; // Count characters in s1
        
        vector<int> s2v(26, 0); // Frequency of characters in the current window of s2
        int l = 0, r = 0; // Initialize left and right pointers for the sliding window

        // Step 3: Slide over s2 with the right pointer
        while (r < s2.size()) {
            s2v[s2[r] - 'a']++; // Include current character in the window

            // Check if the current window size matches s1's size
            if (r - l + 1 == s1.size()) {
                // Step 4: Compare frequency vectors
                if (s1v == s2v) return true; // Found a valid permutation
            }

            // Step 5: Move the window
            if (r - l + 1 < s1.size()) {
                r++; // Expand the window to the right
            } else {
                s2v[s2[l] - 'a']--; // Remove the leftmost character from the window
                l++; // Move the left pointer to the right
                r++; // Move the right pointer to the right
            }
        }
        return false; // No permutation of s1 is found in s2
    }
};

/*
 * Approach:
 * The problem requires us to determine if any permutation of string s1 exists 
 * as a substring in string s2. The approach leverages a sliding window and 
 * frequency counting.
 * 
 * Steps:
 * 1. Check if s1 is longer than s2. If true, return false immediately.
 * 2. Create a frequency vector (s1v) for the characters in s1.
 * 3. Use a second frequency vector (s2v) to keep track of characters in the 
 *    current window of s2 as we slide through it.
 * 4. Expand the window by moving the right pointer. If the window size matches 
 *    s1's size, compare the frequency vectors. If they are equal, a permutation 
 *    exists, and we return true.
 * 5. If the window exceeds s1's size, shrink it by moving the left pointer.
 * 6. If no permutation is found after examining all of s2, return false.

 * Complexity Analysis:
 * - Time Complexity: O(N + M), where N is the length of s1 and M is the length 
 *   of s2. We process each character of s2 once, and character comparison 
 *   is O(1) due to fixed size of frequency vectors.
 * - Space Complexity: O(1), since the frequency vectors are of fixed size (26 
 *   for lowercase English letters), irrespective of input size.
 */
