class Solution {
public:
    // Function to count prefix-suffix pairs in the given vector of words
    long long countPrefixSuffixPairs(vector<string>& words) {
        // Initialize result to store the count of prefix-suffix pairs
        long long result = 0;
        
        // Create an unordered map to store occurrences of each word
        unordered_map<string, int> m;
        
        // Initialize the map with the first word and its occurrence
        m[words[0]] = 1;
        
        // Iterate through each word starting from the second one
        for (int i = 1; i < words.size(); ++i) {
            // Check each previously encountered word in the map
            for (const auto& [prev_word, occurence] : m) {
                // If the current word is shorter than the previous word, skip it
                if (words[i].size() < prev_word.size())
                    continue;
                // Check if the current word has the previous word as both prefix and suffix
                else if (words[i].compare(words[i].size() - prev_word.size(), prev_word.size(), prev_word) == 0 &&
                         words[i].compare(0, prev_word.size(), prev_word) == 0)
                    // If both conditions are met, add occurrences to the result
                    result += occurence;    
            }
            // Increment the occurrence of the current word in the map
            ++m[words[i]];
        }
        
        // Return the total count of prefix-suffix pairs found
        return result;
    }
};

/*
Approach Summary:
The function iterates through each word in the input vector and checks against previously seen words stored in an unordered map. For each new word, it checks if it has any previously seen word as both a prefix and a suffix. If it does, it adds the number of occurrences of that prefix-suffix pair to the result.

Complexity Analysis:
- Time Complexity: O(n * k), where n is the number of words and k is the average length of words. This is because for each word, we may need to compare it with all previous words.
- Space Complexity: O(n), as we are using an unordered map to store occurrences of words.
*/
