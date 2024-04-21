class Solution {
public:
    char findTheDifference(string s, string t) {
        // Create a vector of size 26 to store the frequency of each character in s
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        // Traverse through t and decrement the frequency of each character in freq
        for (char c : t) {
            freq[c - 'a']--;
        }
        
        // The character with non-zero frequency in freq is the answer
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) {
                return i + 'a';
            }
        }
        
        // This line should never be reached
        return ' ';
    }
};
/* 
Approach:
We create a vector freq of size 26 to store the frequency of each character in s.
We traverse through s and increment the frequency of each character in freq.
We traverse through t and decrement the frequency of each character in freq.
The character with non-zero frequency in freq is the answer.

The time complexity of this solution is O(n), where n is the length of s.
The space complexity is O(1), since we are using a fixed-size vector.
 */