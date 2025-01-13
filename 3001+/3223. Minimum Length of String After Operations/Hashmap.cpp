class Solution {
public:
    // Function to determine the minimum length of the string after deletions
    int minimumLength(string s) {
        // Step 1: Count the frequency of each character in the string
        unordered_map<char, int> charFrequencyMap; // Map to store character frequencies
        for (char currentChar : s) {
            charFrequencyMap[currentChar]++; // Increment frequency for the current character
        }

        // Step 2: Calculate the number of characters to delete
        int deleteCount = 0; // Counter for characters to delete
        for (auto& pair : charFrequencyMap) {
            int frequency = pair.second; // Get the frequency of the current character
            if (frequency % 2 == 1) {
                // If frequency is odd, delete all except one
                deleteCount += frequency - 1; // Keep one character
            } else {
                // If frequency is even, delete all except two
                deleteCount += frequency - 2; // Keep two characters
            }
        }

        // Step 3: Return the minimum length after deletions
        return s.length() - deleteCount; // Calculate and return the new length of the string
    }
};

/*
Approach Summary:
The function calculates the minimum length of a string after making deletions to ensure that all remaining characters can form pairs. It first counts the frequency of each character. For characters with odd frequencies, it retains one character and deletes the rest. For characters with even frequencies, it retains two characters and deletes the rest. Finally, it returns the length of the string after these deletions.

Complexity Analysis:
- Time Complexity: O(n), where n is the length of the string `s`. The function iterates through the string to count character frequencies and then iterates through the frequency map.
- Space Complexity: O(1), since we are using a fixed-size map for lowercase letters (at most 26 entries), which can be considered constant space for practical purposes.
*/
