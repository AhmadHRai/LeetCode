/**
 * Calculates the number of steps required to reduce a binary number to zero
 * following the given rules.
 *
 * @param s A string representing the binary number.
 * @return The number of steps required to reduce the binary number to zero.
 */
class Solution {
public:
    int numSteps(string &s) {
        int res = 0, carry = 0;
        
        // Traverse the string from right to left
        for (auto i = s.size() - 1; i > 0; --i) {
            ++res;  // Every character adds one operation
            
            // If current digit plus carry equals 1
            if (s[i] - '0' + carry == 1) {
                carry = 1;  // Set carry to 1
                ++res;      // Add two operations for the first encountered '1'
            }
        }
        
        return res + carry;  // Return total operations plus final carry
    }
};

/* 
Algorithm:
    1. We haven't encountered any '1': Every char adds one operation.
    2. We encounter our first '1': We set carry to 1 and add two operations.
    3. For the rest:
        a. Every '1' needs one operation (carry makes it 0). Carry remains 1.
        b. Every '0' needs two operations (carry makes it 1). Carry remains 1 as we need to add 1 in this case.

Observation: As seen in 3a and 3b, carry is always 1 after the second phase.

Complexity Analysis:
    - Time Complexity: O(n) - Linear time complexity, where n is the length of the input string s.
    - Space Complexity: O(1) - Constant space complexity, as only a fixed amount of extra space is used regardless of input size.
 */
