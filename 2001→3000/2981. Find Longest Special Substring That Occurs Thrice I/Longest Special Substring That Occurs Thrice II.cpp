class Solution {
public:
    // Helper function to return the minimum of three values
    int& min(int& a, int& b, int& c) {
        return a < (b < c ? b : c) ? a : b < c ? b : c;
    }

    // Main function to find the maximum length of a substring that appears at least 3 times
    int maximumLength(string s) {
        int substringLength = 0, ans = -1;
        char previousCharacter;
        
        // 2D vector to store the length of substrings for each character.
        // For each character, we store the top 3 lengths of consecutive substrings.
        vector<vector<int>> substringLengths(26, vector<int>(3, -1));
        
        // Iterate through the string to calculate consecutive substring lengths
        for (char character : s) {
            if (character == previousCharacter) {
                substringLength++;  // If the character is the same as the previous one, increment the substring length
            } else {
                substringLength = 1;  // Start a new substring of length 1
                previousCharacter = character;
            }

            // For the current character, update the minimum substring length if the current length is greater
            int& minLength = min(substringLengths[character - 'a'][0],
                                 substringLengths[character - 'a'][1],
                                 substringLengths[character - 'a'][2]);
            if (substringLength > minLength) minLength = substringLength;
        }

        // Iterate through the substringLengths array to find the character with the maximum "minimum" length of its substrings
        for (char character = 'a'; character <= 'z'; character++) {
            ans = max(ans, min(substringLengths[character - 'a'][0],
                               substringLengths[character - 'a'][1],
                               substringLengths[character - 'a'][2]));
        }
        
        // Return the result
        return ans;
    }
};

/*
Approach Summary:
- We use a 2D vector `substringLengths[26][3]` to track the top 3 longest consecutive substrings for each character.
- As we iterate through the string, we update the substring length for each character and keep track of the largest values.
- The helper function `min` is used to maintain the minimum of the top 3 lengths for each character.
- Finally, we determine the character with the longest valid substring that appears at least 3 times by checking the "minimum" lengths for each character.

Complexity Analysis:
- Time Complexity: O(n), where `n` is the length of the string `s`. We iterate through the string once and use constant-time operations for each character (updating the length and checking values).
- Space Complexity: O(1), since the space used by `substringLengths` is constant (fixed size of 26x3) and does not depend on the input size.

Note: This approach uses efficient tracking of the top 3 substring lengths for each character and ensures that we can solve the problem within the larger constraints (up to \(5 \times 10^5\)).
*/
