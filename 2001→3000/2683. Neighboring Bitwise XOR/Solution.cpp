class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        // int XOR = 0;
        // for (auto element : derived) {
        //     XOR = XOR ^ element;
        // }
        // return XOR == 0;

        // Initialize the variable to hold the cumulative XOR of all elements
        int n = derived.size(); // Get the size of the derived array
        int ans = 0; // Variable to store the XOR result

        // Iterate through each element in the derived array
        for (int i = 0; i < n; i++) {
            ans ^= derived[i]; // Compute the cumulative XOR
        }

        // Check if the cumulative XOR is zero
        if (ans == 0) return true; // If XOR is zero, a valid array exists

        return false; // Otherwise, return false
    }
};

/*
Approach Summary:
The function checks if a valid array can be constructed from the given `derived` array by calculating the cumulative XOR of all its elements. If the result of this XOR operation is zero, it indicates that a valid configuration exists; otherwise, it does not.

Complexity Analysis:
- Time Complexity: O(n), where n is the number of elements in the `derived` array. The function iterates through the entire array once to compute the cumulative XOR.
- Space Complexity: O(1), as no additional data structures are used that scale with input size; only a fixed number of variables are utilized.
*/