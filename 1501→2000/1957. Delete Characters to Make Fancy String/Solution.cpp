class Solution {
public:
    string makeFancyString(string s) {
        string result; // Stores the resulting "fancy" string
        int count = 1; // Count of consecutive identical characters
        int length = s.length(); // Length of the input string
        
        // Iterate through each character in the input string
        for (int i = 0; i < length; i++) {
            result += s[i]; // Add the current character to the result
            
            // Check if the current character is the same as the previous one
            if (i > 0 && s[i] == s[i - 1]) {
                count++; // Increment count if it's the same as the previous character
            } else {
                count = 1; // Reset count if it's a different character
            }

            // If three consecutive identical characters are reached, remove the last added character
            if (count == 3) {
                result.pop_back(); // Remove the third duplicate
                count = 2; // Reset count to allow only two consecutive characters
            }
        }

        return result; // Return the modified "fancy" string
    }
};

/*
Approach:

    This solution builds the "fancy" string by iterating over each character of the input string `s`.
    The variable `count` keeps track of consecutive identical characters.
    When a character is added to the result string `result`, we check if it is the same as the previous one.
    If three consecutive identical characters are detected, the last character is removed from `result` 
    to ensure only two consecutive identical characters appear in the final string.
    
Complexity:

    Time Complexity: O(n), where `n` is the length of the input string `s`, as we go through each character once.
    Space Complexity: O(n), where `n` is the length of the input string, due to storing the result string.
*/
