class Solution {
public:
    bool rotateString(string s, string goal) {
        // Check if the lengths of `s` and `goal` are the same.
        // If not, `s` cannot be a rotation of `goal`.
        return s.size() == goal.size() 
            // Concatenate `s` with itself and check if `goal` is a substring of this new string.
            && (s + s).find(goal) != string::npos;
    }
};

/*
Approach:

    This solution checks if `goal` can be obtained by rotating `s`. A string can be rotated to produce all possible 
    rotations by concatenating it with itself. By doing this, all rotations of `s` appear as substrings within `s + s`.
    Therefore, we only need to check if `goal` appears as a substring in `s + s`. 
    Additionally, we confirm that `s` and `goal` have the same length, as different lengths would immediately rule out rotation.

Complexity:

    Time Complexity: O(n), where `n` is the length of `s`. Concatenating `s` with itself and searching for `goal` 
    within this new string both take linear time.

    Space Complexity: O(n) for storing the concatenated string `s + s`.
*/
