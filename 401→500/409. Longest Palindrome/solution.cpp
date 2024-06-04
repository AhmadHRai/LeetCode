class Solution {
public:
    int longestPalindrome(const std::string& s) {
        // Initialize a set to keep track of characters with odd frequencies
        std::unordered_set<char> charSet;
        // Initialize the length of the longest palindrome
        int length = 0;
        
        // Iterate over each character in the string
        for (char c : s) {
            // If the character is already in the set, remove it and increase the length by 2
            if (charSet.find(c) != charSet.end()) {
                charSet.erase(c);
                length += 2;
            } else {
                // If the character is not in the set, add it to the set
                charSet.insert(c);
            }
        }
        
        // If there are any characters left in the set, add 1 to the length for the middle character
        if (!charSet.empty()) {
            length += 1;
        }
        
        // Return the total length of the longest palindrome
        return length;
    }
};

/*
Approach:
    - Use a set (charSet) to keep track of characters with odd frequencies.
    - Initialize length to 0 to accumulate the length of the longest palindrome.
    - Iterate through each character in the input string (s):
        - If the character is already in charSet, remove it (since it forms a pair) and increase length by 2.
        - If the character is not in charSet, add it to charSet.
    - After iterating through the string, if charSet is not empty, add 1 to length (for the middle character of the palindrome).
    - Return the final length, which represents the longest palindrome that can be formed using the characters in s.

Complexity Analysis:
    - Time Complexity: O(n)
      where n is the length of the input string s. The function iterates through the string once to insert or erase characters from the set, which operates in average O(1) time complexity for each operation.
      
    - Space Complexity: O(1)
      The space used by the set (charSet) is at most 26 characters (since characters are from 'a' to 'z'), making it constant space O(1).

*/

