class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diffArray(
            n, 0);  // Initialize a difference array with all elements set to 0.

        for (auto shift : shifts) {
            if (shift[2] == 1) {        // If direction is forward (1):
                diffArray[shift[0]]++;  // Increment at the start index to
                                        // indicate a forward shift.
                if (shift[1] + 1 < n) {
                    diffArray[shift[1] +
                              1]--;  // Decrement at the end+1 index to stop the
                                     // effect of the shift.
                }
            } else {                    // If direction is backward (0):
                diffArray[shift[0]]--;  // Decrement at the start index to
                                        // indicate a backward shift.
                if (shift[1] + 1 < n) {
                    diffArray[shift[1] +
                              1]++;  // Increment at the end+1 index to stop the
                                     // effect of the shift.
                }
            }
        }

        string result(n, ' ');
        int numberOfShifts = 0;

        for (int i = 0; i < s.size(); i++) {
            numberOfShifts = (numberOfShifts + diffArray[i]) %
                             26;  // Update cumulative shifts, keeping within
                                  // the alphabet range.
            if (numberOfShifts < 0)
                numberOfShifts +=
                    26;  // Ensure `numberOfShifts` is non-negative.

            // Calculate the new character by shifting `s[i]`
            result[i] = 'a' + (s[i] - 'a' + numberOfShifts) % 26;
        }

        return result;
    }
};

/* 

Intuition

Building on the idea of cumulative sums, we can use a difference array to handle range updates more efficiently. A difference array helps us record changes in values between consecutive elements rather than updating every element in a range directly.

Instead of keeping track of how many shifts should be applied to each character in the alphabet, we’ll use the difference array to store how many more shifts should be applied to the current character compared to the previous one. This allows us to record changes only at the starting and ending points of shifts, rather than updating each character in the range.

For convenience, a positive shift means that the character must move forward in the alphabet, and a negative shift means that it must move backward


Algorithm

    Initialize n to the size of the string s.
    Initialize an array of length n, called diffArray, and set all its elements to 0.
    For every shift = [start, end, direction] in shifts:
        If direction == 1 (shift forward):
            Increment diffArray[start] by 1, indicating that s[start] is shifted forward one more time than the previous character.
            If end + 1 < n:
                Decrement diffArray[end + 1] by 1, as the character exactly after the shift range is shifted forward one time less than the previous character.
        If direction == 0 (shift backward):
            Decrement diffArray[start] by 1, as s[start] is shifted backward one more time than the previous character.
            If end + 1 < n:
                Increment diffArray[end + 1] by 1, as the character exactly after the shift range is shifted backward one time less than the previous character.
    Initialize numberOfShifts to 0.
    Initialize a string result of length n.
    Iterate over s with i from 0 to n - 1:
        Add diffArray[i] to numberOfShifts and take it mod 26.
        If numberOfShifts < 0, increment numberOfShifts by 26.
        Set result[i] to the shifted character: 'a' + (s[i] - 'a' + numberOfShifts) % 26.
    Return result.

Complexity Analysis

Let n be the size of the string s and m the size of the shifts array.

    Time complexity: O(n+m)

    We are iterating over the shifts array to find the difference between the shifts of any two consecutive characters of s. On each iteration, we only perform constant-time operations (accessing and updating two elements of the diffArray) and therefore the initialization of the diffArray requires O(m) time. Then, we create the resulting string with a single pass over the original, which contributes O(n) to the total time complexity.

    Space complexity: O(n)

    We are using an array of size n to store the differences in the shifts between consecutive characters. We are also creating a new string result of length n to avoid modifying the input directly. These data structures have a size that is linear to the length of the input string and therefore the algorithm requires O(n) extra space.
 */