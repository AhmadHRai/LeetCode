// Define the Solution class containing our method to solve the problem
class Solution {
public:
    // Method to count the number of consistent strings in the 'words' list
    int countConsistentStrings(string allowed, vector<string>& words) {
        // Create a bitset of size 26 to represent each letter of the alphabet
        // Initialize all bits to 0
        bitset<26> ASet = 0;
        
        // Iterate over each character in the 'allowed' string
        // Set the corresponding bit in ASet to 1
        for (char c : allowed) {
            // Set the bit corresponding to the character `c` in ASet
            ASet[c - 'a'] = 1;
        }
        
        // Initialize a counter to keep track of the number of consistent strings
        int cnt = 0;

        // Iterate over each string in the 'words' vector
        for (string& w : words) {
            // Assume the current string is consistent
            bool consistent = 1;
            // Check each character in the current string
            for (char c : w) {
                // If the character is not in ASet, mark the string as inconsistent and break out of the loop
                if (ASet[c - 'a'] == 0) {
                    consistent = 0;
                    break;
                }
            }
            // If the string is consistent, increment the counter
            cnt += consistent;
        }
        
        // Return the final count of consistent strings
        return cnt;
    }
};

/*
Approach:
1. Use a bitset of size 26 to represent the alphabet. Each bit in the bitset corresponds to a letter from 'a' to 'z'.
2. Populate the bitset based on the characters present in the 'allowed' string. For each character in 'allowed', set the corresponding bit in the bitset.
3. Iterate through each string in the 'words' vector and check if all characters of the string are present in the bitset.
4. If a character in the string is not in the bitset, mark the string as inconsistent and stop further checking for that string.
5. Keep a count of consistent strings and return this count at the end.

Time Complexity:
- The time complexity is O(m * n), where `m` is the number of strings in `words` and `n` is the maximum length of a string in `words`. This is because, for each string, we may need to check all of its characters.

Space Complexity:
- The space complexity is O(1) as the bitset has a fixed size of 26, and no additional space grows with input size.
*/
