/* 
Approach
The approach used in the code is similar to the previous one in solution1.cpp, but it does not use an unordered map to store the functions for each operator. Instead, it uses a series of if-else statements to check which operator the token is and perform the corresponding operation. This approach may be simpler to implement, but it may also be less efficient and less scalable than using a map.
 */

class Solution {
public:
    // Define a function that takes a vector of strings as input and returns an int as output
    int evalRPN(vector<string>& tokens) {
        // Create a stack to store the operands
        stack<int> operatorStack;
        // Get the size of the input vector
        int l = tokens.size();
    
        // Loop through each token in the input vector
        for(int i=0;i<l;i++){
            // If the token is one of the four basic operators
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" ||tokens[i] == "/"){
                // Pop the top element of the stack and store it as the second operand
                int operator2 = operatorStack.top();
                operatorStack.pop();
                // Pop the next element of the stack and store it as the first operand
                int operator1 =  operatorStack.top();
                operatorStack.pop();

                // Declare a variable to store the temporary result
                int tempResult;
                // Check which operator the token is and perform the corresponding operation on the two operands
                if(tokens[i] == "+"){
                    tempResult = (operator1 + operator2);
                }
                else if(tokens[i] == "-"){
                    tempResult = (operator1 - operator2);
                }
                else if(tokens[i] == "*"){
                    tempResult = (operator1 * operator2);
                }
                else if(tokens[i] == "/"){
                    tempResult = (operator1 / operator2);
                }

                // Push the temporary result to the stack
                operatorStack.push(tempResult);

            }
            else{
                // If the token is not an operator, it is an operand
                // Convert the token from string to int and push it to the stack
                operatorStack.push(stoi(tokens[i]));
            }
        }

        // After looping through all the tokens, the stack should have only one element, which is the final value of the expression
        // Return the top element of the stack as the output
        return operatorStack.top();
    }
};

/* 
Complexity 

The time complexity of the code is O(n), where n is the number of tokens in the input vector. This is because the code loops through each token once and performs constant time 
operations on the stack and the if-else statements.

The space complexity of the code is O(n), where n is the number of tokens in the input vector. This is because the code uses a stack that can store up to n elements in the worst 
case, when all the tokens are operands.
 */