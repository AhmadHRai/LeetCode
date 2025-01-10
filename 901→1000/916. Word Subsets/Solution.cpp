class Solution {
public:
    // Function to find all universal words that satisfy the required character frequencies
    vector<string> wordSubsets(vector<string>& mainWords, vector<string>& requiredWords) {
        // Array to keep track of the maximum character frequencies needed from requiredWords
        int maxCharFreq[26] = {0};
        
        // Temporary array to count character frequencies for each word in requiredWords
        int tempCharFreq[26];
        
        // Iterate through each word in requiredWords to calculate maximum frequencies
        for (const auto& word : requiredWords) {
            // Reset temporary frequency array to zero for the current word
            memset(tempCharFreq, 0, sizeof tempCharFreq); // Alternatively, can use vector<int> tempCharFreq(26, 0);
            
            // Count character frequencies for the current word
            for (char ch : word) {
                tempCharFreq[ch - 'a']++;
            }
            
            // Update maxCharFreq with the maximum frequencies found
            for (int i = 0; i < 26; ++i) {
                maxCharFreq[i] = max(maxCharFreq[i], tempCharFreq[i]);
            }
        }
        
        // Vector to store words from mainWords that are universal
        vector<string> universalWords;
        
        // Iterate through each word in mainWords to check if it's universal
        for (const auto& word : mainWords) {
            // Reset temporary frequency array for the current main word
            memset(tempCharFreq, 0, sizeof tempCharFreq);
            
            // Count character frequencies for the current main word
            for (char ch : word) {
                tempCharFreq[ch - 'a']++;
            }
            
            // Flag to determine if the current word is universal
            bool isUniversal = true;
            
            // Check if current word meets the maximum character frequency requirements
            for (int i = 0; i < 26; ++i) {
                if (maxCharFreq[i] > tempCharFreq[i]) {
                    isUniversal = false; // If not, mark it as not universal and break
                    break;
                }
            }
            
            // If the word is universal, add it to the result list
            if (isUniversal) {
                universalWords.emplace_back(word);
            }
        }
        
        // Return the list of universal words found
        return universalWords;
    }
};

/*
Approach Summary:
The function calculates the maximum frequency of each character needed across all words in `requiredWords`. It then iterates through `mainWords`, counting character frequencies for each word and checking if they meet or exceed the required frequencies. If a word satisfies all requirements, it is added to the result list.

Complexity Analysis:
- Time Complexity: O(n * m + k * 26), where n is the number of words in `mainWords`, m is the average length of those words, and k is the number of words in `requiredWords`. The first part accounts for counting character frequencies in `requiredWords`, while the second part accounts for counting in `mainWords` and checking against maximum frequencies.
- Space Complexity: O(1), since we are using fixed-size arrays of size 26 for character counts regardless of input size.
*/
