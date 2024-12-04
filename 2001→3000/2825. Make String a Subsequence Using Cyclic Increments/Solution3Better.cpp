class Solution {
public:
    bool canMakeSubsequence(string& str1, string& str2) {
        // Initialize an index to track the current position in str2
        int str1Index = 0;

        // Iterate through str1 to check if str2 can be formed as a subsequence
        for (int i = 0; i < str1.size() && str1Index < str2.size(); ++i) {
            // Get the current character from str1 and the target character from str2
            char currentChar = str1[i];
            char targetChar = str2[str1Index];
            
            // Check if the current character in str1 matches the target character in str2,
            // or if it can wrap around cyclically in the alphabet (i.e., from 'z' to 'a')
            if (currentChar == targetChar || 
                (currentChar + 1 - 'a') % 26 == (targetChar - 'a') % 26) {
                ++str1Index;  // Move to the next character in str2
            }
        }
        
        // If all characters of str2 were matched in str1, return true; otherwise, return false
        return str1Index == str2.size();
    }
};

/*
Approach:
1. Use a single index (`str1Index`) to track the position of the current character in str2 that needs to be matched.
2. Iterate through str1 to find characters that either match the current target character in str2 or can be adjusted by one step cyclically.
3. If a match or valid shift is found, increment the `str1Index` to move to the next character in str2.
4. If all characters of str2 are matched in order, return true; otherwise, return false.

The solution uses a greedy approach combined with modulo arithmetic to allow cyclic character matching. The algorithm checks if each character in str1 can match or wrap around cyclically to form str2.

Key Improvement: The updated solution reduces the number of variables used compared to previous versions. Instead of storing the lengths of the strings (`str1Length` and `str2Length`), it directly uses `str1.size()` and `str2.size()` within the loop condition, simplifying the code. (LeetCode's judge's Memory reduced from 17 MB to 14.9 MB)

Complexity Analysis:
- Time Complexity: O(n), where n is the length of str1. We iterate through str1 once, making constant-time comparisons and simple arithmetic operations.
- Space Complexity: O(1), as only a few integer variables (such as `str1Index`) are used, with no additional data structures or significant space usage.
*/
