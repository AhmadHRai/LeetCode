class Solution {
public:
    // Method to find the shortest palindrome that can be formed by appending characters
    string shortestPalindrome(string s) {
        // Create a reversed version of the input string
        string rev_s = s; 
        reverse(rev_s.begin(), rev_s.end()); // Reverse the string
        
        // Create a new string that combines the original, a separator, and the reversed string
        string l = s + "#" + rev_s; 
        
        // Initialize a vector for storing the lengths of the longest prefix suffix (LPS)
        vector<int> p(l.size(), 0); 
        for (int i = 1; i < l.size(); i++) {
            int j = p[i - 1]; // Start with the previous LPS length
            
            // Update j to find the current matching length
            while (j > 0 && l[i] != l[j]) 
                j = p[j - 1]; // Move j to the last matched position
            
            // Increment j if the characters match and store the LPS length
            p[i] = (j += l[i] == l[j]); 
        }
        
        // Construct the shortest palindrome by appending necessary characters from the reversed string
        return rev_s.substr(0, s.size() - p[l.size() - 1]) + s; 
    }
};

/*
Approach:
1. Reverse the input string and concatenate it with the original string using a separator to avoid overlap.
2. Use the KMP (Knuth-Morris-Pratt) algorithm's prefix function to find the length of the longest palindromic prefix.
3. Calculate the number of characters that need to be appended to the original string to form a palindrome.
4. Return the combination of the necessary characters from the reversed string and the original string.

Time Complexity:
- O(n) for creating the prefix array, where `n` is the length of the string, leading to efficient processing.

Space Complexity:
- O(n) for storing the prefix array and the concatenated string.
*/
