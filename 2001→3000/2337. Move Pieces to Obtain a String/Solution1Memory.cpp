class Solution {
public:
    static bool canChange(string& s, string& t) {
        const int n = s.size();
        // Iterate through both strings using two pointers, i for s and j for t
        for (int i = 0, j = 0; i < n || j < n; i++, j++) {
            // Skip over any underscores ('_') in both strings
            while (i < n && s[i] == '_') i++;
            while (j < n && t[j] == '_') j++;

            // Compare the current characters in both strings
            char c = s[i];
            if (c != t[j]) return 0; // If characters don't match, return false

            // Movement restrictions for 'L' and 'R'
            if (c == 'L' && i < j) return 0; // 'L' cannot move right
            if (c == 'R' && i > j) return 0; // 'R' cannot move left
        }
        return 1; // If all checks pass, return true
    }
};

/*
Approach:
1. Use two pointers to iterate through both strings simultaneously.
2. Skip over any underscores in both strings to find the next non-blank characters.
3. Compare corresponding characters in both strings.
4. For 'L' characters, ensure that they are not moved to the right (i.e., their position in s must not be less than their position in t).
5. For 'R' characters, ensure that they are not moved to the left (i.e., their position in s must not be greater than their position in t).
6. Return true if the strings can be transformed into each other, otherwise return false.

This approach uses two pointers to track and compare characters from both strings, while skipping underscores. It also enforces movement restrictions on 'L' and 'R' characters.

Difference:
1- Memory Usage: This solution uses the reference to the strings (string& s, string& t), ensuring no extra memory is used for copying the strings, which makes it slightly more memory-efficient.
2- Pointer Management: loop uses a combined approach with a single for loop, incrementing both i and j simultaneously.
3- Code Structure: The loop structure is more compact, with fewer lines of code, iterating over both strings in a single loop.
4- Performance: This solution has slightly better memory performance, as it avoids copying the input strings. It also uses a more compact loop structure, which might result in marginally better performance for larger inputs.

Complexity Analysis:
- Time Complexity: O(n), where n is the length of the strings. We iterate through both strings once, making comparisons and skipping underscores.
- Space Complexity: O(1), as we are using only a few integer variables and pointers for tracking the characters, without any additional data structures.
*/
