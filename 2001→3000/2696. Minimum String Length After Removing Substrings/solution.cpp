class Solution {
public:
    // Function to find the minimum length of the string after removing "AB" and "CD"
    int minLength(string s) {
        int writeIdx = 0; // Acts like the stack pointer for the valid characters
        
        // Iterate over each character in the string
        for (char currentChar : s) {
            // Check if we can remove the last character based on the current character
            if (writeIdx > 0 && 
                ((s[writeIdx - 1] == 'A' && currentChar == 'B') || 
                 (s[writeIdx - 1] == 'C' && currentChar == 'D'))) {
                writeIdx--; // Remove the last character (pop) if we found "AB" or "CD"
            } else {
                s[writeIdx++] = currentChar; // Otherwise, keep the current character (push)
            }
        }
        return writeIdx; // Return the size of the remaining valid string
    }
};

/*
Approach:
1. We use a variable `writeIdx` to keep track of the position where we can write valid characters.
2. We iterate through each character in the input string `s`.
3. For each character, we check if the last character in the "stack" (the string up to `writeIdx`) can form the substrings "AB" or "CD" with the current character.
4. If it does, we decrease `writeIdx` to remove the last character (effectively popping it).
5. If not, we write the current character at the position indicated by `writeIdx` and increment it.
6. At the end, `writeIdx` gives the length of the resulting string after all possible removals.

Complexity Analysis:
- Time Complexity: O(n), where n is the length of the input string `s`. We make a single pass through the string.
- Space Complexity: O(1), since we are using a fixed amount of extra space (the `writeIdx` variable) and modifying the string in place.
*/
