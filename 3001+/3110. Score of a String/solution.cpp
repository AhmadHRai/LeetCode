/**
 * Calculates the score of a string based on the sum of absolute differences
 * between adjacent characters in their ASCII values.
 *
 * @param s A string for which the score is calculated.
 * @return The score of the string.
 */
class Solution {
public:
    int scoreOfString(string s) {
        int score = 0;

        // Iterate over all indices from 0 to the second-to-last index
        // Calculate and accumulate the absolute difference of ASCII values
        // between adjacent characters
        for (int i = 0; i < s.size() - 1; ++i) {
            score += abs(s[i] - s[i + 1]);
        }

        return score;
    }
};

/* 
Algorithm:
    - Initialize score to 0 to accumulate the total score.
    - Iterate over all indices from 0 to the second-to-last index of string s.
    - Calculate the absolute difference of ASCII values between each character and its adjacent character.
    - Accumulate these differences into the score.
    - Return the final score which represents the sum of absolute differences between adjacent characters.

Complexity Analysis:
    - Time complexity: O(n)
      The function iterates through the string s once, where n is the length of the string.
      Each iteration involves constant-time operations (computing ASCII values and taking absolute differences),
      resulting in a linear time complexity O(n).
      
    - Space complexity: O(1)
      The function uses a constant amount of extra space, primarily for the score variable.
      The space complexity is O(1) as it does not depend on the input size.
 */
