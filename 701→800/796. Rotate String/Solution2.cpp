class Solution {
private:
    // Helper function to check if `A` matches `B` when rotated by `rotation` positions
    bool rotateString(string A, string B, int rotation) {
        // Iterate through each character of `A` and `B`
        for (int i = 0; i < A.length(); i++) {
            // Check if characters at `A[i]` and `B[(i + rotation) % B.length()]` are the same
            if (A[i] != B[(i + rotation) % B.length()]) {
                return false; // If any character doesn't match, return false
            }
        }
        return true; // All characters matched, return true
    }

public:
    // Main function to check if `goal` is a rotation of `s`
    bool rotateString(string s, string goal) {
        // If the lengths are different, `goal` cannot be a rotation of `s`
        if (s.length() != goal.length()) {
            return false;
        }
        
        // If both strings are empty, they are trivially rotations of each other
        if (s.length() == 0) {
            return true;
        }

        // Try every possible rotation
        for (int i = 0; i < s.length(); i++) {
            // Check if rotating `s` by `i` positions matches `goal`
            if (rotateString(s, goal, i)) {
                return true;
            }
        }

        return false; // No valid rotation found
    }
};

/*
Approach:

    This solution checks if `goal` is a rotation of `s` by trying every possible rotation. 
    For each rotation `i`, it checks if rotating `s` by `i` characters results in `goal`. 
    The `rotateString` helper function compares characters one-by-one in `s` and the rotated `goal` 
    string, returning `false` immediately if a mismatch is found. The outer loop ensures each rotation is tested.

Complexity:

    Time Complexity: O(n^2), where `n` is the length of `s`. There are `n` possible rotations to check, 
    and each rotation requires a linear scan of `n` characters.

    Space Complexity: O(1) as only a fixed amount of additional space is used.
*/
