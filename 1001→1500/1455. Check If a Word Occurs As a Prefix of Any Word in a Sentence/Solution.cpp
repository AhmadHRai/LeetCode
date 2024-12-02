class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        // Initialize word count (word_count) to 1 since we're starting from the first word
        // Initialize 'j' to 0 to keep track of the matching index in searchWord
        int word_count = 1, j = 0;
        
        // Loop through each character in the sentence while keeping track of the index in searchWord
        for (auto i = 0; i < sentence.size() && j < searchWord.size(); ++i) {
            
            // Increment word count when encountering a space, indicating the start of a new word
            word_count += sentence[i] == ' ';
            
            // Check if the current character in sentence matches the current character in searchWord
            if (sentence[i] == searchWord[j]) {
                // If matching, continue the search for the next character in searchWord
                // Only continue searching for the word if we're at the beginning of a new word or if j > 0
                j = j > 0 ? j + 1 : (i == 0 || sentence[i - 1] == ' ');
            } else {
                // Reset 'j' to 0 if the characters don't match
                j = 0;
            }
        }
        
        // If we've found the entire searchWord as a prefix of a word, return the word count
        // Otherwise, return -1 to indicate no match was found
        return j == searchWord.size() ? word_count : -1;
    }
};

/*
Approach:
1. Initialize a counter for the word index (word_count) and a pointer for the search word (j).
2. Iterate through each character in the sentence while checking for a match with the characters in searchWord.
3. When a space is encountered, increment the word count since it indicates the start of a new word.
4. If a matching character is found, either continue looking for the next character in searchWord or reset based on the context.
5. If the searchWord is found as a prefix of any word, return the word's index. Otherwise, return -1.

The solution works by performing a linear scan through the sentence and matching characters of searchWord. It tracks the position of searchWord within words using a simple two-pointer approach, and handles the transition between words by detecting spaces.

Complexity Analysis:
- Time Complexity: O(n), where n is the number of characters in the sentence. We iterate through the sentence once and perform constant-time operations within the loop.
- Space Complexity: O(1), as no additional space is used apart from a few variables to keep track of the indices and word count.
*/
