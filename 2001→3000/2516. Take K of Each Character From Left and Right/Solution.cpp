class Solution {
public:
    int takeCharacters(string s, int k) {
        int ca = 0, cb = 0, cc = 0;  // Initialize counters for 'a', 'b', and 'c' in the string
        int n = s.size();  // Get the length of the string
        int ans = n;  // Initialize the answer to be the maximum possible length of the substring
        
        // Count the occurrences of 'a', 'b', and 'c' in the string
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') ca++;
            if (s[i] == 'b') cb++;
            if (s[i] == 'c') cc++;
        }

        // If any of the counts of 'a', 'b', or 'c' is less than k, it's impossible to take k characters of each
        if (ca < k || cb < k || cc < k) return -1;

        int i = n - 1, j = n - 1;  // Initialize two pointers i and j to the end of the string
        while (i >= 0) {  // Loop through the string from the right side (index n-1 to 0)
            // Decrease the count for the character at position i
            if (s[i] == 'a') ca--;
            if (s[i] == 'b') cb--;
            if (s[i] == 'c') cc--;
            
            // While any character count is less than k, move j to the left
            while (ca < k || cb < k || cc < k) {
                if (s[j] == 'a') ca++;
                if (s[j] == 'b') cb++;
                if (s[j] == 'c') cc++;
                j--;  // Move the left pointer j to the left
            }
            
            // Update the answer to the minimum of the current answer and the length of the valid substring
            ans = min(ans, i + n - 1 - j);
            i--;  // Move the right pointer i to the left
        }
        
        return ans;  // Return the minimum length of the valid substring
    }
};

/*
Approach Summary:
- We are tasked with finding the minimum number of characters that must be removed from a string such that there are at least `k` occurrences of each character ('a', 'b', and 'c') in the remaining substring.
- First, we count the occurrences of 'a', 'b', and 'c' in the string. If any of them is less than `k`, we immediately return -1, as it's impossible to form such a substring.
- We then use the two-pointer technique to track the valid window. One pointer (`i`) starts from the right of the string, and another pointer (`j`) also starts from the right.
- We decrease the character counts as `i` moves to the left. If any character count falls below `k`, we move `j` to the left, increasing the character counts until the condition is satisfied again.
- The answer is updated by calculating the minimum number of characters to remove as the window changes.

Complexity Analysis:
- Time Complexity: O(n), where `n` is the length of the string. Each character is processed once by the two pointers (`i` and `j`), making this a linear-time solution.
- Space Complexity: O(1), since we are only using a fixed amount of space for the counters (`ca`, `cb`, `cc`), and the pointers (`i`, `j`), regardless of the size of the input string.
*/

/*
https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/solutions/2947980/c-two-pointer-solution-o-n
Here we use the two pointer technique - i and j represents the characters we take from left and right respectively.
First , we count number of 'a','b','c' in the string to check whether solution is possible or not. Now, as we decrease i pointer, we keep check of count of different alphabets and if any of these count becomes less than k, we start j pointer until the condition is satisfied.
*/