class Solution {
public:
    long long wonderfulSubstrings(string word) {
        // Initialize an array to store the count of substrings with unique characters
        long cnt[1024] = { 1 };
        // Initialize a mask to represent the unique characters in the current substring
        int mask = 0;
        // Initialize the result to store the total number of wonderful substrings
        long long res = 0;

        // Iterate through each character in the string
        for (auto ch : word) {
            // Update the mask by toggling the bit corresponding to the current character
            mask ^= 1 << (ch - 'a');
            // Add the count of substrings that share the same unique characters as the current substring
            res += cnt[mask];
            // For each of the 10 possible characters, add the count of substrings that share the same unique characters
            // except for the current character, effectively counting substrings that end with the current character
            // and include all other characters except the one that makes the substring not wonderful
            for (auto n = 0; n < 10; ++n)
                res += cnt[mask ^ (1 << n)];
            // Increment the count of the current substring's unique characters
            ++cnt[mask];
        }
        // Return the total number of wonderful substrings
        return res;
    }
};

/* 
Approach:

This solution uses a bitwise approach to count the number of wonderful substrings in a given string `word`. It iterates through each character in the string, updating a 
mask that represents the current substring's unique characters. For each character, it calculates the number of wonderful substrings ending with that character by 
summing the counts of all substrings that share the same unique characters (including the current character) and all substrings that share the same unique characters 
except for the current character.

Complexity:
    Time Complexity: O(n), where n is the length of the string `word`. This is because the algorithm iterates through each character in the string once.
    Space Complexity: O(1), as the algorithm uses a fixed-size array `cnt` to store the counts of substrings with unique characters, and the space complexity does not 
                        depend on the input size.
*/