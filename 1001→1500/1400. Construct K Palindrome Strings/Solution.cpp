class Solution {
public:
    // Function to determine if the string can be constructed into k palindromic substrings
    bool canConstruct(string s, int k) {
        // If the length of the string is less than k, it's impossible to form k substrings
        if (s.length() < k) return false;
        
        // If the length of the string equals k, each character must be its own substring
        if (s.length() == k) return true;
        
        // Vector to store frequency of each character (26 lowercase letters)
        vector<int> freq(26);
        
        // Variable to count characters with odd frequencies
        int oddCount = 0;
        
        // Count frequency of each character in the string
        for(auto& chr: s) {
            freq[chr - 'a']++; // Increment frequency for the corresponding character
        }

        // Count how many characters have an odd frequency
        for(int i = 0; i < 26; i++) {
            if(freq[i] % 2 == 1) oddCount++; // Increment oddCount for odd frequencies
        }

        // If the number of characters with odd counts exceeds k, return false
        if (oddCount > k) return false;
        
        // Otherwise, it's possible to construct k palindromic substrings
        return true;
    }
};

/*
Approach Summary:
The function checks if it is possible to construct `k` palindromic substrings from the given string `s`. It first verifies that the length of `s` is at least `k`. Then, it counts the frequency of each character and determines how many characters have an odd frequency. A palindrome can have at most one character with an odd frequency; hence, if the number of characters with odd frequencies exceeds `k`, it returns false. Otherwise, it returns true.

Complexity Analysis:
- Time Complexity: O(n), where n is the length of the string `s`. This is due to iterating through the string to count character frequencies and then checking those frequencies.
- Space Complexity: O(1), since we are using a fixed-size array of size 26 for character counts regardless of input size.
*/
