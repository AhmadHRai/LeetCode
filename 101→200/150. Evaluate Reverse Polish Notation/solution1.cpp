/* Approach
It is a stack-based approach that evaluates an arithmetic expression in Reverse Polish Notation (RPN). RPN is a notation where the operators follow their operands, such as 3 4 + 
instead of 3 + 4. The code uses a stack to store the operands and an unordered map to store the functions for each operator. The code loops through each token in the input vector 
and performs the following steps:

    If the token is an operand, it converts it from string to int and pushes it to the stack.
    If the token is an operator, it pops two operands from the stack and applies the corresponding function to them. Then it pushes the result back to the stack.
    After looping through all the tokens, the stack should have only one element, which is the final value of the expression. The code returns the top element of the stack as the 
    output.

 */

class Solution {
public:
    // Define a function that takes a vector of strings as input and returns an int as output
    int evalRPN(vector<string>& tokens) {
        // Create an unordered map that maps each operator to a lambda function that performs the corresponding operation on two ints
        unordered_map<string, function<int (int, int) > > map = {
            { "+" , [] (int a, int b) { return a + b; } }, // Addition
            { "-" , [] (int a, int b) { return a - b; } }, // Subtraction
            { "*" , [] (int a, int b) { return a * b; } }, // Multiplication
            { "/" , [] (int a, int b) { return a / b; } }  // Division
        };
        // Create a stack to store the operands
        std::stack<int> stack;
        // Loop through each token in the input vector
        for (string& s : tokens) {
            // If the token is not an operator, it is an operand
            if (!map.count(s)) {
                // Convert the token from string to int and push it to the stack
                stack.push(stoi(s));
            } else {
                // If the token is an operator, it needs two operands
                // Pop the top element of the stack and store it as the first operand
                int op1 = stack.top();
                stack.pop();
                // Pop the next element of the stack and store it as the second operand
                int op2 = stack.top();
                stack.pop();
                // Apply the function that corresponds to the operator on the two operands and push the result to the stack
                stack.push(maps);
            }
        }
        // After looping through all the tokens, the stack should have only one element, which is the final value of the expression
        // Return the top element of the stack as the output
        return stack.top();
    }
};

/* 
Complexity:
    The time complexity of the code is O(n), where n is the number of tokens in the input vector. This is because the code loops through each token once and performs constant 
    time operations on the stack and the map.

    The space complexity of the code is O(n), where n is the number of tokens in the input vector. This is because the code uses a stack and a map that can store up to n elements 
    in the worst case, when all the tokens are operands.
 */