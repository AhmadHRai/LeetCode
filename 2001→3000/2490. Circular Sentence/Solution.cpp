class Solution {
public:
    bool isCircularSentence(string sentence) {
        istringstream iss(sentence);
        string word;
        vector<string> words;

        // Split the sentence into words and store them in the `words` vector
        while (iss >> word) {
            words.push_back(word);
        }

        int n = words.size();
        
        // Check if the last character of each word matches the first character of the next word
        for (int i = 0; i < n; ++i) {
            if (words[i].back() != words[(i + 1) % n].front()) {
                return false;
            }
        }
        
        return true; // If all checks pass, the sentence is circular
    }
};

/* 
Approach

    Split the Sentence: We use istringstream to split the input sentence by spaces and store each word in a vector.
    Circular Check: Loop through the vector and check if the last character of each word matches the first character of the next word. The check wraps around to the first word for the last word in the vector.

Complexity Analysis

    Time Complexity: O(n), where nn is the length of the sentence. We go through each character once to split the words, and the circular check involves a single traversal through the words vector.
    Space Complexity: O(m), where mm is the number of words in the sentence, as we store all words in a vector.
 */