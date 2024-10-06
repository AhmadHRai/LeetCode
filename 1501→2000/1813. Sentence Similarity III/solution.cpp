#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        // Helper function to split a sentence into words
        auto splitWords = [](const string& sentence) {
            vector<string> words; // To store the words from the sentence
            string word = "";     // Current word being constructed
            for (char c : sentence) {
                // If we encounter a space, add the word to the vector and reset the word
                if (c == ' ') {
                    if (!word.empty()) {
                        words.push_back(word);
                        word = "";
                    }
                } else {
                    // Add the character to the current word
                    word += c;
                }
            }
            // Add the last word to the vector if it's non-empty
            if (!word.empty()) words.push_back(word);
            return words;
        };

        // Split both sentences into words
        vector<string> words1 = splitWords(sentence1);
        vector<string> words2 = splitWords(sentence2);
        
        // Ensure words1 refers to the longer sentence
        if (words1.size() < words2.size()) swap(words1, words2);
        
        // Variables to keep track of matching words from the start and end
        int start = 0, end = 0;
        int n1 = words1.size(), n2 = words2.size();
        
        // Compare words from the start of both sentences
        while (start < n2 && words1[start] == words2[start]) start++;
        
        // Compare words from the end of both sentences
        while (end < n2 && words1[n1 - end - 1] == words2[n2 - end - 1]) end++;
        
        // Check if the unmatched portion is in the middle
        // The total number of matched words (from start and end) should cover the shorter sentence
        return start + end >= n2;
    }
};
/*
Approach:
1. Splitting Sentences into Words:
   - The first step is to split both input sentences into individual words. This is done using a helper function `splitWords`, which iterates over each character in the sentence and splits it based on spaces.

2. Ensuring Sentence1 is the Longer Sentence:
   - To make the comparison easier, we always make sure that `words1` refers to the longer sentence, and `words2` refers to the shorter one. If necessary, we swap them.

3. Comparing Words from the Start:
   - We use a pointer `start` to count how many words match between the two sentences from the beginning (i.e., left to right).

4. Comparing Words from the End:
   - Similarly, we use a pointer `end` to count how many words match between the two sentences from the end (i.e., right to left).

5. Checking the Remaining Middle Part:
   - After comparing from both ends, the unmatched portion should only be in the middle of the longer sentence. If the sum of matched words (`start + end`) is greater than or equal to the length of the shorter sentence (`n2`), then the sentences are considered similar.

6. Return the Result:
   - Return `true` if the total number of matched words from the start and end is sufficient to cover the shorter sentence; otherwise, return `false`.

Complexity Analysis:
- Time Complexity: O(n1), where `n1` is the length of the longer sentence (in terms of words). The time complexity is dominated by the word-by-word comparison from the start and end.
- Space Complexity: O(n1 + n2), where `n1` and `n2` are the number of words in the two sentences. We store the words in vectors after splitting both sentences.
*/
