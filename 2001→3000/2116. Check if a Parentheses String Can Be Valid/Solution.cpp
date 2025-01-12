class Solution {
public:
    // Function to determine if the string can be valid based on locked and unlocked brackets
    bool canBeValid(string s, string locked) {
        int length = s.size();

        // If the length of the string is odd, it cannot form valid pairs of brackets
        if (length % 2 == 1) {
            return false;
        }

        // Variables to count open brackets and unlocked positions
        int openBrackets = 0, unlocked = 0;

        // Iterate through the string to handle '(' and ')' based on locking
        for (int i = 0; i < length; i++) {
            // Count unlocked positions
            if (locked[i] == '0') {
                unlocked++;
            } 
            // Count open brackets
            else if (s[i] == '(') {
                openBrackets++;
            } 
            // Handle closing brackets
            else if (s[i] == ')') {
                // If there are open brackets, match them
                if (openBrackets > 0) {
                    openBrackets--;
                } 
                // If no open brackets, use an unlocked position if available
                else if (unlocked > 0) {
                    unlocked--;
                } 
                // If neither condition is met, return false
                else {
                    return false;
                }
            }
        }

        // Match remaining open brackets with unlocked characters from the end
        int balance = 0;
        for (int i = length - 1; i >= 0; i--) {
            // Count unlocked positions in reverse
            if (locked[i] == '0') {
                balance--;   // Treat unlocked as closing bracket for balance check
                unlocked--;
            } 
            // Count open brackets in reverse
            else if (s[i] == '(') {
                balance++;   // Treat open bracket as increasing balance
                openBrackets--;
            } 
            // Handle closing brackets in reverse
            else if (s[i] == ')') {
                balance--;   // Treat closing bracket as decreasing balance
            }
            
            // If at any point balance is positive, return false
            if (balance > 0) {
                return false;
            }
            
            // Break early if all unlocked positions and open brackets are accounted for
            if (unlocked == 0 && openBrackets == 0) {
                break;
            }
        }

        // If there are unmatched open brackets remaining, return false
        if (openBrackets > 0) {
            return false;
        }

        // If all conditions are satisfied, return true
        return true;
    }
};

/*
Approach Summary:
The function checks whether the string `s` can be made valid by considering locked and unlocked brackets. It first checks for an odd length, which cannot form valid pairs. It then counts the number of open brackets and unlocked positions while iterating through the string. A second pass from the end ensures that all remaining unmatched brackets can be paired with unlocked positions. The function returns true only if all conditions for a valid configuration are met.

Complexity Analysis:
- Time Complexity: O(n), where n is the length of the string `s`. The function makes two passes through the string.
- Space Complexity: O(1), as only a fixed number of integer variables are used regardless of input size.
*/
