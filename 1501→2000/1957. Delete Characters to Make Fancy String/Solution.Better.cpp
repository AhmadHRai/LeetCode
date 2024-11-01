class Solution {
public:
    static string makeFancyString(string& s) {
        int n = s.size();  // Length of the input string
        int i = 0;         // Index to store valid characters in the modified string
        char prev = '@';   // Placeholder for the previous character, initially set to a non-alphabet character

        // Iterate over each character in the input string
        for (int len = 0; char c : s) {
            // Reset `len` if the current character is different from the previous one
            if (prev != c) len = 1;
            else len++; // Otherwise, increment `len` for consecutive characters

            // Only add the character to the result if there are fewer than 3 consecutive duplicates
            if (len <= 2) 
                s[i++] = c; // Assign the character at the `i`th position in `s` and increment `i`

            prev = c; // Update `prev` to the current character
        }

        // Resize the string to include only valid characters
        s.resize(i);
        return s;  // Return the modified "fancy" string
    }
};

/*
Approach:

    The solution uses a single pass through the input string `s` to remove any excessive consecutive characters.
    We keep track of the current character `c` and count its consecutive occurrences with `len`.
    If `len` exceeds 2, the character is skipped in the modified string.
    Only up to two consecutive identical characters are added to `s`, which is resized at the end to remove extraneous characters.

Complexity:

    Time Complexity: O(n), where `n` is the length of the input string `s`, as each character is processed once.
    Space Complexity: O(1), since no extra space is used apart from modifying the input string in-place.
*/
