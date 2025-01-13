class Solution {
public:
    // Function to determine the minimum length of the string after deletions
    int minimumLength(string s) {
        // Step 1: Initialize a frequency array to count occurrences of each character
        vector<int> charFrequency(26, 0); // Array to store frequency of each lowercase letter
        int totalLength = 0; // Variable to accumulate the total length of remaining characters

        // Step 2: Count the frequency of each character in the string
        for (char currentChar : s) {
            charFrequency[currentChar - 'a']++; // Increment frequency for the current character
        }

        // Step 3: Calculate the total length after deletions count
        for (int frequency : charFrequency) {
            if (frequency == 0) continue;  // Skip characters that don't appear
            if (frequency % 2 == 0) {
                totalLength += 2;  // If frequency is even, add 2 (keep two characters)
            } else {
                totalLength += 1;  // If frequency is odd, add 1 (keep one character)
            }
        }

        // Step 4: Return the minimum length after deletions count
        return totalLength; // Return the calculated total length of remaining characters
    }
};

/*
Approach Summary:
The function calculates the minimum length of a string after making deletions to ensure that all remaining characters can form pairs. It initializes a frequency array to count occurrences of each character. After counting, it checks each character's frequency: if it's even, it retains two characters; if it's odd, it retains one. Finally, it returns the total length of characters that can remain after these deletions.

Complexity Analysis:
- Time Complexity: O(n), where n is the length of the string `s`. The function iterates through the string to count character frequencies and then through a fixed-size array to calculate the total length.
- Space Complexity: O(1), since we are using a fixed-size array of size 26 for character counts, which can be considered constant space for practical purposes.
*/
