class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26, 0);  // Frequency array to store counts of each character (26 letters)
        
        // Count the frequency of each character in the input string
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        string result;  // String to store the resulting string
        int currentCharIndex = 25;  // Start from the largest character ('z')
        
        // Continue adding characters to the result
        while (currentCharIndex >= 0) {
            // Skip characters that have no remaining occurrences
            if (freq[currentCharIndex] == 0) {
                currentCharIndex--;
                continue;
            }

            // Add up to repeatLimit occurrences of the current character to the result
            int use = min(freq[currentCharIndex], repeatLimit);
            result.append(use, 'a' + currentCharIndex);
            freq[currentCharIndex] -= use;

            // If there are more of the current character left, add a smaller character
            if (freq[currentCharIndex] > 0) {
                int smallerCharIndex = currentCharIndex - 1;
                
                // Find the next available smaller character
                while (smallerCharIndex >= 0 && freq[smallerCharIndex] == 0) {
                    smallerCharIndex--;
                }
                
                // If no smaller character is available, stop
                if (smallerCharIndex < 0) {
                    break;
                }
                
                // Add one occurrence of the smaller character to the result
                result.push_back('a' + smallerCharIndex);
                freq[smallerCharIndex]--;
            }
        }

        return result;  // Return the final result
    }
};

/*
    Time Complexity: O(N + 26 * log 26)
        - The initial frequency count of the string takes O(N), where N is the length of the input string.
        - In the while loop, we process each character in the frequency array. For each character, we check and update the frequency, which takes constant time (since there are at most 26 different characters).
        - The most expensive operation in each iteration of the while loop is finding the next available smaller character (which takes O(26) in the worst case, since there are only 26 characters). Hence, the total complexity for processing the characters is O(26 * log 26) in the worst case (though this step is limited by the number of available characters, so it's very small).
        - Therefore, the overall time complexity is O(N), dominated by the initial scan of the string.

    Space Complexity: O(1)
        - The space complexity is constant, O(1), because the frequency array `freq` always has a fixed size of 26 (one for each lowercase English letter).
        - The additional space used by the result string is O(N), which is required to store the output. But this is not considered in the space complexity since the result string is the output and not auxiliary space.
*/
