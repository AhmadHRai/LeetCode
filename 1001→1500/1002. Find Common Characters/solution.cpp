class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        // Initialize the frequency array for the first word
        vector<int> last = count(words[0]);
        
        // Iterate through the remaining words to find common characters
        for (int i = 1; i < words.size(); i++) {
            last = intersection(last, count(words[i]));
        }
        
        // Build the result vector based on the common characters found
        vector<string> result;
        for (int i = 0; i < 26; i++) {
            while (last[i] > 0) {
                result.push_back(string(1, 'a' + i));
                last[i]--;
            }
        }
        
        return result;
    }
    
private:
    // Helper function to count character frequencies in a string
    vector<int> count(const string& str) {
        vector<int> frequency(26, 0);
        for (char c : str) {
            frequency[c - 'a']++;
        }
        return frequency;
    }
    
    // Helper function to find the minimum frequency for each character between two frequency arrays
    vector<int> intersection(const vector<int>& a, const vector<int>& b) {
        vector<int> t(26, 0);
        for (int i = 0; i < 26; i++) {
            t[i] = min(a[i], b[i]);
        }
        return t;
    }
};

/*
Approach:
    1. Initialize Frequency Array:
        Start by counting the frequency of each character in the first word. This will be our reference frequency array.

    2. Update Frequency Array:
        For each subsequent word, count the frequency of each character.
        Update the reference frequency array to keep only the minimum frequency of each character seen so far. This ensures that the reference frequency array will ultimately represent the characters that are common to all words and the minimum number of times they appear in any word.

    3. Build Result:
        Iterate through the reference frequency array.
        For each character that has a non-zero frequency, add it to the result list the number of times it appears in the reference frequency array.

Complexity:

    Time Complexity:
        - Counting characters in each word: O(n * m), where n is the number of words and m is the average length of the words.
        - Updating the reference frequency array: O(n * 26), since we compare 26 possible characters for each word.
        - Constructing the result list: O(26), iterating through the frequency array to build the result.
        - Overall, the time complexity is O(n * m), where n is the number of words and m is the length of the longest word.

    Space Complexity:
        - The space required for the frequency arrays is O(26) for each word.
        - Additional space for the result list depends on the number of common characters, which is O(m) in the worst case (though typically much smaller).
        - Overall, the space complexity is O(26) + O(m) = O(m).
*/

