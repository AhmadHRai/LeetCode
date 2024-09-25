#include <vector>
#include <string>
#include <cstring>

using namespace std;

// Trie structure to hold scores and children nodes
struct Trie {
    int score; // Score of the prefix
    Trie *children[26]; // Array to hold pointers to child nodes

    // Constructor to initialize the Trie node
    Trie() {
        score = 0; // Initialize score to 0
        memset(children, 0, sizeof(children)); // Set all children to nullptr
    }

    // Method to add a string to the Trie
    void add(string &s, int i) {
        // Increment score if we're adding a prefix (i > 0)
        if (i) score++;
        // If we've reached the end of the string, return
        if (i == s.size()) return;
        // If the child node for the current character doesn't exist, create it
        if (!children[s[i] - 'a']) children[s[i] - 'a'] = new Trie();
        // Recursive call to add the next character
        children[s[i] - 'a']->add(s, i + 1);
    }

    // Method to perform depth-first search and calculate the prefix scores
    int dfs(string &s, int i) {
        // If we've reached the end of the string, return the score
        if (i == s.size()) return score;
        // Return the accumulated score and recursively call dfs on the child node
        return score + children[s[i] - 'a']->dfs(s, i + 1);
    }
};

class Solution {
public:
    // Method to compute the sum of prefix scores for each word
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie *trie = new Trie(); // Create a new Trie
        // Add each word to the Trie
        for (string &s : words) trie->add(s, 0);
        vector<int> res; // Vector to hold the results
        // Calculate prefix scores for each word
        for (string &s : words) res.push_back(trie->dfs(s, 0));
        return res; // Return the result vector
    }
};

/*
Approach:
1. Use a Trie to store all prefixes of the given words while counting the number of words that share each prefix.
2. For each word, traverse the Trie to compute the sum of scores for all its prefixes.
3. Store and return the results for all words.

Time Complexity:
- O(N * L), where N is the number of words and L is the average length of the words. Each word is inserted into the Trie and each word's score is computed in linear time relative to its length.

Space Complexity:
- O(N * L) in the worst case for the Trie structure, where each character of each word can potentially create a new node in the Trie.
*/
