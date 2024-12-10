class Solution {
public:
    // Function to find the maximum length of a substring that appears at least 3 times
    int maximumLength(string s) {
        int n = s.size();
        int l = 1, r = n;  // Set the initial search range for the substring length
        
        // Perform a binary search to find the maximum length of the special substring
        if (!helper(s, n, l)) return -1;  // If the smallest length doesn't work, return -1
        
        // Binary search to find the longest valid substring length
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (helper(s, n, mid)) l = mid;  // If mid works, search the right half
            else r = mid;  // Otherwise, search the left half
        }

        return l;  // Return the longest valid length
    }

private:
    // Helper function to check if a substring of length 'x' occurs at least 3 times
    bool helper(const string& s, int n, int x) {
        vector<int> cnt(26, 0);  // Array to store the frequency of each character (for substrings)
        int p = 0;  // Pointer to track the starting position of the current substring

        // Iterate through the string to check all substrings of length 'x'
        for (int i = 0; i < n; i++) {
            // Move 'p' until the characters match (s[p] == s[i])
            while (s[p] != s[i]) p++;

            // Check if the current substring has length >= x
            if (i - p + 1 >= x) cnt[s[i] - 'a']++;  // Increment the count for the current character

            // If any character appears more than 2 times, we can return true
            if (cnt[s[i] - 'a'] > 2) return true;
        }

        return false;  // If no character occurs more than 2 times, return false
    }
};

/*
Approach Summary:
This approach uses binary search to efficiently find the maximum valid substring length, optimizing the process compared to a brute force solution.
- We perform a binary search to find the maximum length of a substring that appears at least 3 times.
- The search range for substring lengths starts from 1 to the length of the string `n`.
- In each iteration, we check if a substring of length `mid` can appear at least 3 times using the `helper` function.
- The `helper` function uses a sliding window approach to count the occurrences of characters in substrings of length `x` and checks if any character appears more than twice.

Complexity Analysis:
- Time Complexity: O(n log n), where `n` is the length of the string `s`.
  - The binary search runs for log(n) iterations, and in each iteration, the `helper` function runs in O(n) time, leading to an overall time complexity of O(n log n).
- Space Complexity: O(1), since the space used for the count array `cnt` is constant (size 26 for each character in the alphabet), and no additional data structures grow with input size.
*/
