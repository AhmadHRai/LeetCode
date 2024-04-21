class Solution {
public:
    string makeGood(string s) {
        // Use a stack to keep track of characters in the string.
        stack<char> stack;
        
        // Iterate through each character in the string.
        for (char c : s) {
            // Check if the stack is not empty and the top character of the stack is the same as the current character but with different case.
            if (!stack.empty() && abs(c - stack.top()) == 32) {
                // If the condition is met, pop the top character from the stack.
                stack.pop();
            } else {
                // If the condition is not met, push the current character onto the stack.
                stack.push(c);
            }
        }
        
        // Initialize an empty string to store the result.
        string result;
        // While the stack is not empty, pop characters from the stack and prepend them to the result string.
        while (!stack.empty()) {
            result = stack.top() + result;
            stack.pop();
        }
        
        // Return the final result string.
        return result;
    }
};

/* 
Approach

    The solution uses a stack to process the input string character by character. It iterates through each character in the string. If the stack is not empty and the top character of 
    the stack is the same as the current character but with a different case (i.e., one is uppercase and the other is lowercase), it pops the top character from the stack. Otherwise, 
    it pushes the current character onto the stack. This process ensures that adjacent characters that are the same but have different cases are removed. Finally, the characters are 
    popped from the stack and prepended to the result string to form the final string.

Complexity

    Time complexity: O(n), where n is the length of the string. This is because each character in the string is processed exactly once.
    
    Space complexity: O(n), due to the use of a stack to store characters. In the worst-case scenario, the stack could contain all characters from the string, especially if the 
    string contains many adjacent characters that need to be removed.
 */
