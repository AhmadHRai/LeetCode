class Solution {
public:
    int minimumLength(string s) {
        // Initialize two pointers i and j to the start and end of the string
        int i = 0, j = s.size() - 1, ch = 0;
        
        // Loop until the pointers meet in the middle or the characters at the current positions are not the same
        while (i < j && s[i] == s[j]) {
            // Store the current character at the start of the string
            ch = s[i];
            
            // Increment the left pointer until it points to a character different from ch
            while (i < j && s[i] == ch)
                ++i;
            
            // Decrement the right pointer until it points to a character different from ch
            while (i < j && s[j] == ch)
                --j;
        }
        
        // If the characters at the current positions are the same as ch, return 0 as the string is empty after deletion
        // Otherwise, return the length of the remaining string after deletion
        return s[i] == ch ? 0 : j - i + 1;
    }
};

/* 
Approach

    Two Pointers Approach: The solution uses two pointers, i and j, to traverse the string from both ends. The approach is to increment i and decrement j until they meet or 
    until the characters at the current positions are not the same. This is done to skip over the similar characters at the ends of the string.

    Key Points:
    The solution iteratively compares characters from both ends of the string.
    It uses a variable ch to keep track of the current character being compared.
    The inner loops are used to move the pointers past the current character ch until a different character is found or the pointers meet.

Complexity Analysis

    Time Complexity:    The time complexity of this solution is O(n), where n is the length of the string s. This is because each character in the string is visited at most 
    twice (once by i and once by j) in the worst case.
    
    Space Complexity:   The space complexity is O(1), as no additional space is used that scales with the input size. The variables i, j, and ch are used, but their memory 
    usage is constant regardless of the input size.

 */