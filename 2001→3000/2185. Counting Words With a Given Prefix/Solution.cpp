class Solution {
public:
    // Function to count how many words in the vector start with the given prefix
    int prefixCount(vector<string>& words, string pref) {
        // Initialize a counter for words that match the prefix
        int count = 0;
        
        // Iterate through each word in the input vector
        for (string& word : words) {
            // Check if the current word starts with the specified prefix
            if (word.find(pref) == 0) {
                // Increment count if the prefix matches
                count++;
            }
        }
        
        // Return the total count of words that start with the prefix
        return count;
    }
};

/*
Approach Summary:
The function iterates through each word in the provided vector and checks if it starts with the specified prefix using the `find` method. If a word starts with the prefix (i.e., `find` returns 0), it increments a counter. Finally, it returns the total count of such words.

Complexity Analysis:
- Time Complexity: O(n * m), where n is the number of words and m is the average length of the words. This is because for each word, we may need to check up to its length to determine if it starts with the prefix.
- Space Complexity: O(1), as we are only using a fixed amount of additional space for counting and do not use any extra data structures that scale with input size.
*/
