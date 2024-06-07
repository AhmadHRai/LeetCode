/**
 * Trie data structure for efficient prefix search.
 */
class trie {
public:
    bool terminal;          // Flag to indicate end of a word
    trie* next[26];         // Array of pointers to next trie nodes

    // Constructor to initialize trie node
    trie() {
        terminal = false;
        for (int i = 0; i < 26; i++) {
            next[i] = nullptr;
        }
    }
};

/**
 * Solution class that implements trie operations and replaces words in a sentence based on prefixes.
 */
class Solution {
    trie* base = new trie();    // Initialize the base of the trie

    /**
     * Inserts a word into the trie.
     *
     * @param word The word to be inserted into the trie.
     */
    void insert(string word) {
        int len = word.size();
        trie* iter = base;
        for (int i = 0; i < len; i++) {
            // Create new trie node if path doesn't exist
            if (!iter->next[word[i] - 'a']) {
                iter->next[word[i] - 'a'] = new trie();
            }
            iter = iter->next[word[i] - 'a'];   // Move to next trie node
        }
        iter->terminal = true;  // Mark end of word
    }

    /**
     * Searches for the shortest root of a word in the trie.
     *
     * @param word The word to search for the shortest root.
     * @return The shortest root found in the trie.
     */
    string search(string &word) {
        int len = word.size();
        string cu;
        trie* iter = base;
        for (int i = 0; i < len; i++) {
            // If current character path doesn't exist in trie, return the original word or the shortest prefix found
            if (!iter->next[word[i] - 'a']) {
                if (iter->terminal) return cu;   // Return shortest root found if end of word is reached
                return word;    // Return original word if path not found
            }
            cu += word[i];  // Append character to current prefix
            iter = iter->next[word[i] - 'a'];   // Move to next trie node
            if (iter->terminal) return cu;   // Return shortest root found if end of word is reached
        }
        return cu;   // Return current prefix if word traversal completes
    }

public:
    /**
     * Replaces words in the sentence based on the shortest root found in the trie.
     *
     * @param dictionary A vector of strings representing the dictionary of roots.
     * @param sentence A string representing the sentence to be processed.
     * @return A string with replaced words based on shortest roots found in the dictionary.
     */
    string replaceWords(vector<string>& dictionary, string sentence) {
        ios_base::sync_with_stdio(false);   // Disable synchronization with C I/O
        cin.tie(NULL);  // Disable flushing of the output buffer
        string ret, t;  // Initialize empty strings for result and temporary word storage

        // Insert all dictionary words into trie
        for (string i: dictionary) {
            insert(i);
        }

        // Process each character in the sentence
        for (char i: sentence) {
            if (i == ' ') { // If space is encountered, search for shortest root of current word
                ret += search(t);   // Append shortest root to result
                ret += ' '; // Append space to result
                t.clear();  // Clear temporary word storage
            } else {
                t += i; // Append character to temporary word storage
            }
        }

        ret += search(t);   // Append shortest root of last word in sentence to result
        return ret; // Return sentence with replaced words based on shortest roots found
    }
};

/*
Approach:
    1. Trie Construction:
        - Implement a trie data structure (`trie`) with methods to insert words and search for the shortest prefix (root).
        - Insert each word from the dictionary into the trie.

    2. Sentence Processing:
        - Iterate through each character in the sentence.
        - Collect characters to form words until a space is encountered.
        - For each word formed, search the trie for the shortest root (prefix).
        - Append the shortest root to the result string.
        - Handle spaces by appending them directly to the result.

Complexity Analysis:
    - Time Complexity:
        - Trie Construction: O(n * m)
          where n is the number of words in the dictionary and m is the average length of the words.
        - Sentence Processing: O(p * m)
          where p is the number of words in the sentence and m is the average length of the words.
        - Overall, the time complexity is O((n + p) * m).

    - Space Complexity:
        - Trie Storage: O(n * m)
          where n is the number of words in the dictionary and m is the average length of the words.
        - Additional space for storing the sentence and result strings.
        - Overall, the space complexity is O(n * m).
*/
