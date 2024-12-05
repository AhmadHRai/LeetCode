class Solution {
public:
    static bool canChange(string start, string target) {
        int n = start.size();
        int i = 0, j = 0;

        while (i < n || j < n) {
            // Move to the next non-blank character in start
            while (i < n && start[i] == '_') i++;
            // Move to the next non-blank character in target
            while (j < n && target[j] == '_') j++;

            // If both pointers have reached the end, we are done
            if (i == n && j == n) return true;

            // If one has reached the end but not the other, return false
            if (i == n || j == n) return false;

            // Compare characters at current positions
            if (start[i] != target[j]) return false;

            // Check movement restrictions for 'L' and 'R'
            if (start[i] == 'L' && i < j) return false; // 'L' cannot move right
            if (start[i] == 'R' && i > j) return false; // 'R' cannot move left

            // Move to the next character
            i++;
            j++;
        }
        return true;
    }
};

/*
Approach:
1. Iterate through both strings using two pointers, i for start and j for target.
2. Skip over underscores ('_') in both strings to find the next non-blank character.
3. Compare corresponding characters in both strings.
4. For 'L' characters, check if they move left (i.e., the index in start should be greater than or equal to their position in target).
5. For 'R' characters, check if they move right (i.e., the index in start should be less than or equal to their position in target).
6. Return true if all conditions are satisfied, otherwise return false.

This solution uses two pointers to compare and validate if start can be transformed into target by respecting movement restrictions for 'L' and 'R'.

Difference:
1- Memory Usage: This solution uses copies of the strings (string start, string target), leading to a higher memory usage since it creates duplicates of the original input strings.
2- Pointer Management: The loop uses a while loop for both pointers (i and j), which allows more explicit control over the iterations and exits the loop early if both strings are exhausted.
3- Code Structure: The loop structure is slightly longer, as it uses separate while loops to skip over underscores before comparing characters.
4- Performance: While functional, this solution may consume more memory due to copying strings and slightly more verbose loop management. However, it does the same work in terms of runtime (O(n)).

Complexity Analysis:
- Time Complexity: O(n), where n is the length of the strings. We traverse both strings once, skipping over underscores and performing constant-time checks.
- Space Complexity: O(1), as the solution uses only a few integer variables and does not rely on any additional data structures.
*/
