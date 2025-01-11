class Solution {
public:
    // Function to determine if the string can be constructed into k palindromic substrings
    bool canConstruct(string s, int k) {
        // If the length of the string is less than k, it's impossible to form k substrings
        if (s.length() < k) return false;
        
        // If the length of the string equals k, each character must be its own substring
        if (s.length() == k) return true;
        
        // Variable to keep track of characters with odd frequencies using bit manipulation
        int oddCount = 0;
        
        // Iterate through each character in the string
        for(auto& chr: s) {
            // Toggle the bit corresponding to the character's position in the alphabet
            oddCount ^= 1 << (chr - 'a');
        }

        // Count the number of bits set in oddCount and check if it is less than or equal to k
        return __builtin_popcount(oddCount) <= k;
    }
};

/*
Approach Summary:
The function checks if it is possible to construct `k` palindromic substrings from the given string `s`. It first verifies that the length of `s` is at least `k`. Then, it uses bit manipulation to track which characters have odd frequencies by toggling bits corresponding to each character. Finally, it counts how many characters have odd frequencies using `__builtin_popcount` and checks if this count is less than or equal to `k`.

Complexity Analysis:
- Time Complexity: O(n), where n is the length of the string `s`. This is due to iterating through the string once to toggle bits for each character.
- Space Complexity: O(1), since we are using a fixed-size integer variable for counting odd frequencies, regardless of input size.
*/
