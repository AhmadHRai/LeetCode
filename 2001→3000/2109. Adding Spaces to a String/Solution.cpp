class Solution {
public:
    string addSpaces(string& s, vector<int>& spaces) {
        // m is the number of spaces to insert, and n is the size of the original string 's'
        const int m = spaces.size(), n = s.size();
        
        // Initialize a new string 't' of size n + m, filled with spaces
        string t(n + m, ' ');
        
        // Add the length of the string 's' to the spaces list to handle the last part of the string
        spaces.push_back(n); // This reduces the number of branches we need to handle for the last character
        
        int j = 0, i = 0; // Pointer 'j' tracks the space indices, and 'i' tracks the current character in the original string
        
        // Loop through each character in the original string 's'
        for (i = 0; i < n; i++) {
            // If the current index 'i' is not a space position, copy the character to 't'
            while (i < n && i != spaces[j]) {
                t[i + j] = s[i];
                i++;
            }
            
            // If we are at a position where a space should be inserted, place it at the correct position in 't'
            if (j < m) {
                t[i + j + 1] = s[i];
                j++; // Move to the next space position
            }
        }
        
        // Return the new string 't' with spaces added at the specified positions
        return t;
    }
};

/*
Approach:
1. Initialize the size of the new string 't' as the original string size plus the number of spaces.
2. Use a pointer 'i' to iterate through the characters in the original string and a pointer 'j' to track the positions where spaces need to be added.
3. Traverse the string and copy characters to the new string 't' until reaching a space position. When a space is required, insert it at the appropriate position in 't'.
4. After inserting the spaces, return the newly formed string with spaces added at the correct indices.

The solution uses a greedy approach with two pointers. One pointer moves through the original string, and the other keeps track of the space positions. The idea is to build the result string step-by-step by placing characters and spaces in the correct positions.

Complexity Analysis:
- Time Complexity: O(n + m), where n is the length of the string and m is the number of spaces to insert. The string is iterated once, and each space insertion is handled in constant time.
- Space Complexity: O(n + m), as we are creating a new string of size n + m to accommodate both the original characters and the spaces.
*/
