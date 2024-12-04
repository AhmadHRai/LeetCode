class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        // Initialize an index to track the current position in str2
        int str1Index = 0, str1Length = str1.size(), str2Length = str2.size();
        
        // Iterate through str1 to check if str2 can be formed as a subsequence
        for (int i = 0; i < str1Length && str1Index < str2Length; ++i) {
            // Get the current character from str1 and the target character from str2
            char currentChar = str1[i];
            char targetChar = str2[str1Index];
            
            // Check if the current character in str1 matches the target character in str2,
            // or if it can wrap around cyclically in the alphabet
            if (currentChar == targetChar || 
                (currentChar + 1 - 'a') % 26 == (targetChar - 'a') % 26) {
                ++str1Index;  // Move to the next character in str2
            }
        }
        
        // If all characters of str2 were matched in str1, return true; otherwise, return false
        return str1Index == str2Length;
    }
};

/*
Approach:
1. Initialize an index to track the current character in str2 and pointers for the lengths of str1 and str2.
2. Loop through the string str1, attempting to match each character with the corresponding character in str2.
3. For each character in str1, check if it matches the target character in str2 or if it can be incremented or decremented to match it cyclically (i.e., from 'z' to 'a').
4. If a match is found, increment the str1Index to proceed to the next character of str2.
5. After iterating through str1, check if all characters in str2 have been matched in order. If so, return true; otherwise, return false.

The solution uses a greedy approach to attempt to form `str2` from `str1` while allowing cyclic character wrapping. Modulo arithmetic is used to handle the wrapping between 'a' to 'z', ensuring a match even when characters are separated by a cyclic shift.
The core logic and approach are the same in all three solution versions, but the current version improves on the previous one by using modulo arithmetic for cyclic character matching, which is cleaner and more efficient.

Complexity Analysis:
- Time Complexity: O(n), where n is the length of str1. We iterate through str1 once, making constant-time comparisons and simple arithmetic operations.
- Space Complexity: O(1), as no additional space is used other than the few integer variables used for indexing and the lengths of the strings.
*/
