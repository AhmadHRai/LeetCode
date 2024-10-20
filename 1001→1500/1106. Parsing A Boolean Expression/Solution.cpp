class Solution {
public:
    // Function to evaluate a boolean expression
    bool parseBoolExpr(string expression) {
        // Stack to store operators and boolean values
        stack<char> st;

        // Iterate through each character in the expression
        for (char currChar : expression) {
            if (currChar == ',' || currChar == '(') {
                continue;  // Skip commas and opening parentheses
            }
            if (currChar == 't' || currChar == 'f' || currChar == '!' ||
                currChar == '&' || currChar == '|') {
                // Push boolean values and operators onto the stack
                st.push(currChar);
            }
            else if (currChar == ')') {
                // Closing parenthesis indicates end of a subexpression
                bool hasTrue = false, hasFalse = false;

                // Evaluate the subexpression until an operator is encountered
                while (st.top() != '!' && st.top() != '&' && st.top() != '|') {
                    char topValue = st.top();
                    st.pop();
                    if (topValue == 't') hasTrue = true;
                    if (topValue == 'f') hasFalse = true;
                }
                
                // Pop the operator and apply it to the accumulated values
                char op = st.top();
                st.pop();
                if (op == '!') {
                    // NOT operator: flip the boolean value
                    st.push(hasTrue ? 'f' : 't');
                } else if (op == '&') {
                    // AND operator: push 't' if no 'f' was found, else push 'f'
                    st.push(hasFalse ? 'f' : 't');
                } else {
                    // OR operator: push 't' if any 't' was found, else push 'f'
                    st.push(hasTrue ? 't' : 'f');
                }
            }
        }
        // Return true if the final result is 't', otherwise false
        return st.top() == 't';
    }
};

/*
Approach:
1. Stack-Based Parsing:
   - Use a stack to keep track of operators and boolean values ('t' for true, 'f' for false).
   - Operators are `!` (NOT), `&` (AND), and `|` (OR).

2. Character Handling:
   - Ignore commas and opening parentheses since they don't affect the expression directly.
   - Push `t`, `f`, `!`, `&`, and `|` onto the stack as they're encountered.
   - On encountering `)`, evaluate the subexpression by popping stack values until an operator is reached.

3. Operator Application:
   - For `!`: Flip the boolean value.
   - For `&`: Return true only if all values are true (otherwise false).
   - For `|`: Return true if any value is true (otherwise false).

Complexity Analysis:
- Time Complexity: O(n), where n is the length of the expression, as each character is processed once.
- Space Complexity: O(n), due to the use of the stack.
*/
