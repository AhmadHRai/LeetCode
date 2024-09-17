#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // Method to find uncommon words from two sentences
    vector<string> uncommonFromSentences(string s1, string s2) {
        // Maps to count occurrences of words in each sentence
        unordered_map<string, int> count1, count2;
        // String streams to read words from the sentences
        stringstream ss1(s1), ss2(s2);
        string word;

        // Count words in the first sentence
        while (ss1 >> word) {
            count1[word]++; // Increment the count for each word
        }

        // Count words in the second sentence
        while (ss2 >> word) {
            count2[word]++; // Increment the count for each word
        }

        // Vector to store the uncommon words
        vector<string> uncommonWords;

        // Find uncommon words in the first sentence
        for (const auto& entry : count1) {
            const string& word = entry.first; // Get the word
            // Check if the word appears only once in the first sentence and is absent in the second
            if (entry.second == 1 && count2.find(word) == count2.end()) {
                uncommonWords.push_back(word); // Add to the uncommon words list
            }
        }

        // Find uncommon words in the second sentence
        for (const auto& entry : count2) {
            const string& word = entry.first; // Get the word
            // Check if the word appears only once in the second sentence and is absent in the first
            if (entry.second == 1 && count1.find(word) == count1.end()) {
                uncommonWords.push_back(word); // Add to the uncommon words list
            }
        }

        // Return the list of uncommon words
        return uncommonWords;
    }
};

/*
Approach:
1. Use two unordered maps to count the occurrences of each word in both sentences.
2. Iterate through the first sentence to populate `count1`, then through the second sentence to populate `count2`.
3. Check the counts in both maps:
   - A word is considered uncommon if it appears exactly once in one sentence and does not appear in the other.
4. Collect and return all uncommon words from both sentences.

Time Complexity:
- O(n + m), where `n` is the number of words in `s1` and `m` is the number of words in `s2`. Each word is processed once.

Space Complexity:
- O(n + m) for storing the counts of words in the two maps. In the worst case, each word could be unique.
*/
