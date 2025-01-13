class Solution {
public:
    int minimumLength(string s) {
        // Optimize input/output operations
        ios::sync_with_stdio(0); 
        cin.tie(0); 

        // Step 1: Initialize a frequency array to count occurrences of each character
        vector<int> ct(26); // Array to store frequency of each lowercase letter

        // Step 2: Count the frequency of each character in the string
        for (char c : s) {
            ct[c - 'a']++; // Increment frequency for the current character
        }

        // Step 3: Calculate the total length after deletions count
        int res = 0; // Variable to accumulate the total length of remaining characters
        for (int i = 0; i < 26; i++) {
            // If frequency is odd, add 1 (keep one character), if even and non-zero, add 2 (keep two characters)
            res += (ct[i] % 2 ? 1 : (ct[i] ? 2 : 0));
        }

        // Step 4: Return the minimum length after deletions count
        return res; // Return the calculated total length of remaining characters
    }
};

/*
Approach Summary:
The function calculates the minimum length of a string after making deletions to ensure that all remaining characters can form pairs. It initializes a frequency array to count occurrences of each character. After counting, it checks each character's frequency: if it's odd, it retains one character; if it's even and non-zero, it retains two. Finally, it returns the total length of characters that can remain after these deletions.

Complexity Analysis:
- Time Complexity: O(n), where n is the length of the string `s`. The function iterates through the string to count character frequencies and then through a fixed-size array to calculate the total length.
- Space Complexity: O(1), since we are using a fixed-size array of size 26 for character counts, which can be considered constant space for practical purposes.
*/
