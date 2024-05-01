class Solution {
public:
    string reversePrefix(string word, char ch) {
        // Iterate through each character in the string
        for(int i = 0; i < word.length(); i++) {
            // If the current character matches the target character, reverse the segment from index 0 to the current index (inclusive)
            if(word[i] == ch) {
                reverse(begin(word), begin(word)+i+1);
                break; // Exit the loop after reversing the segment
            }
        }
        // Return the modified string
        return word;
    }
};

/* 
Approach:

This solution iterates through the string `word` to find the first occurrence of the character `ch`. Once the character is found, it reverses the segment of the string 
from index 0 to the index of the character (inclusive) using the `reverse` function from the C++ Standard Library. The iteration stops after reversing the segment, as 
there is no need to continue searching for further occurrences of `ch`.

Complexity:

    Time Complexity: O(n), where n is the length of the string `word`. This is because the algorithm iterates through each character in the string once.
    Space Complexity: O(1), as the algorithm modifies the input string in-place and does not use any additional space that scales with the input size.

*/