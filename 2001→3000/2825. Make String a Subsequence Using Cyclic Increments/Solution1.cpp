class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        // Initialize an index to track the current position in str2
        int str1Index = 0, str1Length = str1.size(), str2Length = str2.size();
        
        // Iterate through str1 to check if str2 can be formed as a subsequence
        for (int i = 0; i < str1Length && str1Index < str2Length; ++i) {
            // Check if the current character in str1 matches str2's character, or
            // if the current character in str1 can be incremented or decremented to match str2
            if (str1[i] == str2[str1Index] || 
                str1[i] + 1 == str2[str1Index] || 
                str1[i] - 25 == str2[str1Index]) {
                ++str1Index;  // Move to the next character in str2
            }
        }
        
        // Return true if all characters of str2 are matched in order in str1
        return str1Index == str2Length;
    }
};

/*
Approach:
1. Initialize an index to track the current character of str2.
2. Iterate through str1, checking if each character can either match the current character in str2 or be adjusted by one step in the alphabet.
3. If a valid match is found, move to the next character in str2.
4. If the entire str2 is matched as a subsequence, return true; otherwise, return false.

The solution uses a greedy approach. It attempts to match each character of str2 in order within str1, while allowing a character in str1 to increment or decrement by 1 to match the target character in str2.

Complexity Analysis:
- Time Complexity: O(n), where n is the length of str1. We iterate through str1 once, making constant-time comparisons.
- Space Complexity: O(1), as we only use a few integer variables for indices and lengths, with no additional data structures.
*/
