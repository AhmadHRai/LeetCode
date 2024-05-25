class Solution {
public:
    /**
     * @brief Breaks the given string into words using the provided word dictionary.
     * 
     * @param s The input string to be broken into words.
     * @param wordDict The dictionary containing valid words.
     * @return A vector of strings representing all possible word breaks for the input string.
     */
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // Initialize the maximum length of words in the dictionary
        int max_len = 0;
        // Initialize an unordered_set to store words from the dictionary
        unordered_set<string> dict;
        // Populate the word set and find the maximum word length
        for(string& str : wordDict) {
            dict.insert(str);
            max_len = max(max_len, static_cast<int>(str.length()));
        }

        // Initialize a map to store the results of word breaks at each position
        unordered_map<int, vector<string>> mp;
        // Perform word breaking recursively starting from the first character
        return break_word(s, 0, dict, max_len, mp);
    }

protected:
    /**
     * @brief Recursively breaks the input string into words starting from a given position.
     * 
     * @param s The input string.
     * @param n The current position in the string.
     * @param dict The set of valid words.
     * @param max_len The maximum length of words in the dictionary.
     * @param mp A map to store memoized results of word breaks.
     * @return A vector of strings representing all possible word breaks starting from position n.
     */
    vector<string> break_word(const string& s, int n, unordered_set<string>& dict, 
                              int max_len, unordered_map<int, vector<string>>& mp) {
        // If the result for position n is already computed, return it
        if(mp.count(n)) return mp[n];

        // Initialize an empty string to accumulate characters
        string str;
        // Iterate over characters starting from position n
        for(int i = n; i < s.length() && str.length() <= max_len; ++i) {
            str += s[i];
            // If the accumulated substring is a valid word
            if(dict.count(str)) {
                // If it reaches the end of the string, add the word to the result
                if(i == s.length() - 1)
                    mp[n].push_back(str);
                // Otherwise, recursively find word breaks for the remaining substring
                else {
                    vector<string> vs = break_word(s, i + 1, dict, max_len, mp);
                    // Concatenate the current word with each word break in the remaining substring
                    for(auto& a : vs)
                        mp[n].push_back(str + " " + a);
                }
            }
        }
        // Return the result for position n
        return mp[n];
    }
};

/*
Approach:

    This solution utilizes a recursive approach with memoization to efficiently find all possible word breaks in the input string.
    It iterates through the string and checks if substrings starting from each position form valid words in the dictionary.
    If a valid word is found, it recursively finds word breaks for the remaining substring and concatenates them with the current word.

Complexity Analysis:

    Time Complexity: The time complexity mainly depends on the length of the input string and the number of words in the dictionary. Due to memoization, the time complexity 
    is reduced to O(n^2 * m), where n is the length of the string and m is the average length of words in the dictionary.
    
    Space Complexity: The space complexity is O(n^2), where n is the length of the input string. This is primarily due to the memoization map used to store intermediate results.
*/