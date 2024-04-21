class Solution {
public:
    // This function takes a string s and returns the number of palindromic substrings in it
    int countSubstrings(string s) {
        // Get the length of the string
        int n = s.length(), ans = 0;
        // Loop through the string from the first to the last character
        for (int i = 0; i < n; ++i) {
            // Call the helper function with the current character as the center of an even-length palindrome
            int even = palindromeCount(s, i, i + 1);
            // Call the helper function with the current character as the center of an odd-length palindrome
            int odd = palindromeCount(s, i, i);
            // Add the number of even-length and odd-length palindromes to the answer
            ans += even + odd;
        }
        // Return the answer
        return ans;
    }

    // This helper function takes the string, the left and right indices of the center of a palindrome, and returns the number of palindromes that can be formed by expanding the center
    int palindromeCount(const string& s, int left, int right) {
        // Initialize a variable to store the count
        int count = 0;
        // While the left and right indices are valid and the characters at those indices are equal
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            // Move the left index to the left and the right index to the right
            --left;
            ++right;
            // Increment the count
            ++count;
        }
        // Return the count
        return count;
    }
};

/* 
Approach:
    The code uses a looping and expanding approach to solve the problem of counting palindromic substrings in a string. A palindromic substring is a substring that is the same 
    forward and backward. The code loops through the string from the first to the last character, and for each character, it calls a helper function with the character as the 
    center of a palindrome. The helper function expands the center to the left and right, and counts the number of palindromes that can be formed by doing so. The code adds the 
    number of palindromes for each character to the final answer, and returns it.

Complexity:
    The time complexity is O(n^2), where n is the length of the string. This is because the code uses a loop to iterate over the string, and for each character, it calls the 
    helper function, which takes O (n) time in the worst case. Therefore, the total time complexity is O (n * n), which is equivalent to O (n^2).

    The space complexity is O(1), because the code does not use any extra space to store the intermediate results. The code only uses some auxiliary variables, but they do not 
    affect the overall space complexity.
 */