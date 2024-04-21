class Solution {
public:
    bool checkValidString(string s) {
        // Initialize two counters to track the minimum and maximum number of open parentheses required to balance the string.
        int cmin = 0, cmax = 0;
        // Iterate through each character in the string.
        for (char c : s) {
            // If the character is an opening parenthesis, increment both counters.
            if (c == '(')
                cmax++, cmin++;
            // If the character is a closing parenthesis, decrement the maximum counter and update the minimum counter to be at least 0.
            if (c == ')')
                cmax--, cmin = max(cmin - 1, 0);
            // If the character is a wildcard, increment the maximum counter and update the minimum counter to be at least 0.
            if (c == '*')
                cmax++, cmin = max(cmin - 1, 0);
            // If at any point the maximum counter becomes negative, return false because it's impossible to balance the string.
            if (cmax < 0) return false;
        }
        // If the minimum counter is 0 at the end, return true because all open parentheses have been balanced.
        return cmin == 0;
    }
};

/*

Intuition:

    One pass on the string S,
    we need to know,
    how many ')' we are waiting for.

    If we meet too many ')', we can return false directly.
    If we wait for no ')' at the end, then we are good.

Explanation:

    We count the number of ')' we are waiting for,
    and it's equal to the number of open parenthesis.
    This number will be in a range and we count it as [cmin, cmax]

    cmax counts the maximum open parenthesis,
    which means the maximum number of unbalanced '(' that COULD be paired.
    cmin counts the minimum open parenthesis,
    which means the number of unbalanced '(' that MUST be paired.

Example:

    It's quite straight forward actually.
    When you met "(", you know you need one only one ")", cmin = 1 and cmax = 1.
    When you met "(*(", you know you need one/two/three ")", cmin = 1 and cmax = 3.

    The string is valid for 2 condition:

        cmax will never be negative.
        cmin is 0 at the end.

Approach

    The solution uses two counters, `cmin` and `cmax`, to track the minimum and maximum number of open parentheses required to balance the string. It iterates through each character 
    in the string. If the character is an opening parenthesis, it increments both counters. If the character is a closing parenthesis, it decrements the maximum counter and updates 
    the minimum counter to be at least 0. If the character is a wildcard, it increments the maximum counter and updates the minimum counter to be at least 0. If at any point the 
    maximum counter becomes negative, it returns false because it's impossible to balance the string. If the minimum counter is 0 at the end, it returns true because all open 
    parentheses have been balanced.

Complexity:

    Time complexity: O(n), where n is the length of the string. This is because each character in the string is processed exactly once.
    
    Space complexity: O(1), as the solution uses a constant amount of space to store the counters and does not depend on the size of the input string.
*/