
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> matchingWords;
        TrieNode* root = new TrieNode();  // Initialize the root of the Trie.

        // Insert all suffixes of each word into the Trie.
        for (const auto& word : words) {
            for (int startIndex = 0; startIndex < word.size(); startIndex++) {
                // Insert each suffix starting from index `startIndex`.
                insertWord(root, word.substr(startIndex));
            }
        }

        // Check each word to see if it exists as a substring in the Trie.
        for (auto word : words) {
            if (isSubstring(root, word)) {
                matchingWords.push_back(word);
            }
        }

        return matchingWords;
    }

private:
    class TrieNode {
    public:
        // Tracks how many times this substring appears in the Trie.
        int frequency;
        // Maps characters to their respective child nodes.
        unordered_map<char, TrieNode*> childNodes;
    };

    // Function to insert a word (or suffix) into the Trie.
    void insertWord(TrieNode* root, const string& word) {
        TrieNode* currentNode = root;
        for (char c : word) {
            // If the character already exists as a child node, move to it.
            if (currentNode->childNodes.find(c) !=
                currentNode->childNodes.end()) {
                currentNode = currentNode->childNodes[c];
                // Increment the frequency of the node.
                currentNode->frequency++;
            } else {
                // If the character does not exist, create a new node.
                TrieNode* newNode = new TrieNode();
                // Initialize the frequency to 1.
                newNode->frequency = 1;
                // Add the new node as a child.
                currentNode->childNodes[c] = newNode;
                currentNode = newNode;  // Move to the new node.
            }
        }
    }

    // Function to check if a word exists as a substring in the Trie.
    bool isSubstring(TrieNode* root, string& word) {
        TrieNode* currentNode = root;  // Start from the root node.
        for (char c : word) {
            // Traverse the Trie following the characters of the word.
            currentNode = currentNode->childNodes[c];
        }
        // A word is a substring or a different string if its frequency in the
        // Trie is greater than 1.
        return currentNode->frequency > 1;
    }
};

/* 
Intuition

In this approach, we will use a Trie to store all suffixes of any word in words and then determine for each word if it appears as part of any suffix in the Trie.

    A Trie is a tree-like data structure used to store substrings. If you are new to Tries, you might want to check out the Trie Explore Card 🔗. This resource provides an in-depth look at the trie data structure, explaining its key concepts and applications with a variety of problems to solidify understanding of the pattern.

Each node (TrieNode) represents a substring. A TrieNode has:

    A frequency that keeps track of how many times the substring, represented by the path from the root to that node, has appeared as a suffix.
    A map to store its child nodes, representing the next characters of the substring.

After defining our TrieNode class, we go over every word in words and insert each suffix of it into the Trie. To insert a string word into the Trie, we start from the root (which represents an empty string "") and check if a child node exists for the first character of the word. If yes, then we move to that child node, incrementing its frequency and we repeat the same for the second character of the word. Otherwise, we create a new TrieNode and add it to the children of the current node. We repeat this process, until we reach the end of the word, meaning that we have efficiently inserted it into the Trie.

After inserting all suffixes of each word, the Trie essentially stores all possible substrings as paths from the root to a leaf node. The frequency count at each node reflects how many words in the array share that particular substring.

Now, to determine whether a word appears as a substring within the words array, we iterate over all characters of the word, traversing the Trie. When we reach the end of the word, we check the frequency of the node we are currently at. If it is greater than 1, this means that the word is present as a substring of another word as well, not just itself, so we count it to the result.
Algorithm
TrieNode class.

Each TrieNode has:

    A counter, frequency, to track the number of times the corresponding string occurs within words.
    A map of characters to TrieNodes, named childNodes.

insertWord(root, word) function

    Initialize currentNode to root.
    For every character, c of word:
        If c is a child node of currentNode:
            Move currentNode to the child node corresponding to c.
            Increment the frequency of currentNode.
        Otherwise,
            Create a new TrieNode, initialize its frequency to 1 and set it as the child of the currentNode for character c.
            Move currentNode to new node.

isSubstring(root, word) function

    Initialize currentNode to root.
    For every character, c of word:
    - Move currentNode to the child node corresponding to c.
    Check the frequency of the currentNode:
        If it is greater than 1, return true.
        Otherwise, return false.

Main stringMatching function:

    Initialize an empty array of strings, named matchingWords.
    Initialize the root of the Trie.
    For every word in words:
        Loop with startIndex from 0 to word.size() - 1:
            Insert the suffix word[startIndex:] to the Trie.
    For every word in words:
        If isSubstring(root, word), insert word into matchingWords.
    Return matchingWords.

Complexity Analysis

Let n be the size of the words array and m be the length of the longest string in words.

    Time complexity: O(m2×n)

    The insertWord(root, word) and the isSubstring(word) functions involve a loop over the characters of word, so they have a time complexity of O(m). We insert every suffix of every string of words into the Trie, resulting in O(n×m) insertions. Therefore, the overall time complexity is O(m×n×m)=O(m2×n).

    Space complexity: O(m2×n)

    In the worst case, all suffixes of all words are unique and must be stored separately in the Trie. Each word has O(m) suffixes, each of which requires O(m) TrieNodes. Therefore, the Trie can grow up to O(m2×n) in size. The matchingWords array has a size of O(m×n) and hence, it does not increase the total space complexity.

*/