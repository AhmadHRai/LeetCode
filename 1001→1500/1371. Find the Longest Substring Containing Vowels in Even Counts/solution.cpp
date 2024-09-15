class Solution {
public:
    // Method to find the length of the longest substring with even counts of vowels
    int findTheLongestSubstring(string s) {
        // Vector to store the last seen index of each mask configuration
        vector<int> mapy(32, -2); // There are 32 possible configurations (2^5 for 5 vowels)
        mapy[0] = -1; // Base case for mask 0 (no vowels)

        // Variable to keep track of the maximum length of the substring found
        int maxLen = 0;
        // Variable to represent the current mask of vowel counts
        int mask = 0;

        // Iterate through each character in the string
        for (int i = 0; i < s.size(); ++i) {
            // Get the current character
            char ch = s[i];

            // Update the mask based on the current character
            switch (ch) {
                case 'a': // If the character is 'a', toggle the first bit of the mask
                    mask ^= 1; // Toggle bit for 'a'
                    break;
                case 'e': // If the character is 'e', toggle the second bit of the mask
                    mask ^= 2; // Toggle bit for 'e'
                    break;
                case 'i': // If the character is 'i', toggle the third bit of the mask
                    mask ^= 4; // Toggle bit for 'i'
                    break;
                case 'o': // If the character is 'o', toggle the fourth bit of the mask
                    mask ^= 8; // Toggle bit for 'o'
                    break;
                case 'u': // If the character is 'u', toggle the fifth bit of the mask
                    mask ^= 16; // Toggle bit for 'u'
                    break;
            }

            // Get the last seen index for the current mask configuration
            int prev = mapy[mask];
            // If this mask has not been seen before
            if (prev == -2) {
                // Store the current index for this mask
                mapy[mask] = i;
            } else {
                // Calculate the length of the substring between the current index and the last seen index
                maxLen = max(maxLen, i - prev);
            }
        }

        // Return the maximum length found
        return maxLen;
    }
};

/*
Approach:
1. Use a bitmask to track the parity of the counts of the vowels ('a', 'e', 'i', 'o', 'u').
   - Each bit in the mask represents the parity (even or odd) of the corresponding vowel.
2. As we iterate through the string, we toggle the respective bit for each vowel encountered.
3. We maintain a map (`mapy`) that stores the last seen index for each unique mask configuration.
4. If the same mask is encountered again, it means the substring between the two indices has even counts of all vowels.
5. We calculate the length of this substring and update the maximum length if it's longer than the previous maximum.

Time Complexity:
- O(n), where `n` is the length of the string. We traverse the string once, and each mask operation is O(1).

Space Complexity:
- O(1) since the size of the `mapy` array is constant (32 elements) and does not depend on the size of the input string.
*/
