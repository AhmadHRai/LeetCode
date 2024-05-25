class Solution {
public:
    /**
     * @brief Finds all possible word breaks in the input string using a recursive approach.
     * 
     * @param s The input string to be broken into words.
     * @param words A dictionary of words to check for valid word breaks.
     * @param i The current index in the input string to start searching for word breaks.
     * @return vector<string> A vector containing all possible word breaks in the input string.
     */
    vector<string> solve(string s, unordered_map<string, bool> &words, int i) {
        // Base case: If the current index exceeds or equals the length of the input string, return an empty string vector.
        if (i >= s.size()) return {""};

        // Initialize variables
        string word;
        vector<string> ans;

        // Iterate through the input string starting from the current index
        for (int j = i; j < s.size(); j++) {
            // Construct substrings from the input string
            word += s[j];

            // If the constructed substring is not found in the dictionary, continue to the next iteration
            if (words.find(word) == words.end()) continue;

            // Word found in the dictionary
            // Recursively find word breaks for the remaining substring
            auto rightPart = solve(s, words, j + 1);

            // Concatenate the current word with each word break in the remaining substring
            for (auto part : rightPart) {
                string end;
                if (part.size() > 0) end += " " + part;
                ans.push_back(word + end);
            }
        }
        // Return the vector containing all possible word breaks
        return ans;
    }

    /**
     * @brief Breaks the input string into words using the words in the given word dictionary.
     * 
     * @param s The input string to be broken into words.
     * @param wordDict The dictionary containing valid words.
     * @return vector<string> A vector containing all possible word breaks in the input string.
     */
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // Create a dictionary of words for efficient word lookup
        unordered_map<string, bool> words;
        for (auto i : wordDict) {
            words[i] = true;
        }
        // Call the solve function to find all possible word breaks starting from index 0
        return solve(s, words, 0);
    }
};

/*
Approach:

    This solution utilizes a recursive approach to find all possible word breaks in the input string. It iterates through the input string, starting from each position, and 
    constructs substrings to check if they form valid words in the dictionary. If a valid word is found, it recursively finds word breaks for the remaining substring and 
    concatenates them with the current word.

Complexity Analysis:

    Time Complexity: The time complexity mainly depends on the length of the input string and the number of words in the dictionary. Since the solution explores all possible 
    combinations, the time complexity can be exponential in the worst case, but it can be optimized with memoization. Let n be the length of the input string and m be the 
    average length of words in the dictionary. With memoization, the time complexity is reduced to O(n^3 * m), where n is the length of the string and m is the average 
    length of words in the dictionary.

    Space Complexity: The space complexity is also influenced by the memoization approach. It is O(n^2 * m), where n is the length of the input string and m is the average 
    length of words in the dictionary. This is primarily due to the memoization map used to store intermediate results.
*/