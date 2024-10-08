class Solution {
public:
    int minSwaps(string s) {
        // Initialize a counter for tracking unbalanced '[' brackets
        int size = 0;
        int n = s.size(); // Length of the string

        // Loop through each character in the string
        for (int i = 0; i < n; i++) {
            char ch = s[i]; // Current character

            // If it's an opening bracket '[', increment the counter
            if (ch == '[')
                size++;
            // If it's a closing bracket ']' and there are unmatched '[' brackets
            else if (size > 0)
                size--; // Decrement the counter since this ']' matches a previous '['
        }

        // Return the number of swaps needed to balance the string
        // (size + 1) / 2 gives the minimum number of swaps required
        return (size + 1) / 2;
    }
};
/*
Approach:
1. Tracking Unbalanced Brackets:
   - The goal is to balance the given string of square brackets by performing the minimum number of swaps.
   - We maintain a counter `size` to track how many unmatched opening brackets `[` we have encountered so far.
   - If we find an opening bracket `[`, we increment the counter.
   - If we find a closing bracket `]`, we check if there are any unmatched opening brackets. If there are (`size > 0`), we decrement the counter because this closing bracket balances one of the unmatched opening brackets.
   
2. Calculating Minimum Swaps:
   - After processing the string, the value of `size` will represent the number of unmatched opening brackets.
   - Each swap can resolve two unmatched opening brackets, so the minimum number of swaps required is `(size + 1) / 2`. This formula accounts for odd counts as well, ensuring the correct number of swaps.

Complexity:
    Time Complexity:
    - The time complexity is O(n), where `n` is the length of the string. We loop through the string once to count the unmatched brackets.

    Space Complexity:
    - The space complexity is O(1), since we're only using a few integer variables to keep track of the count of unmatched brackets.
*/
