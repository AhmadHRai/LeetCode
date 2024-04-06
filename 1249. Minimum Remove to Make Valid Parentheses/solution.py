class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        # Convert the input string to a list to allow modification.
        s = list(s)
        # Initialize an empty stack to keep track of the indices of opening parentheses.
        stack = []
        # Iterate through each character in the string along with its index.
        for i, char in enumerate(s):
            # If the character is an opening parenthesis, push its index onto the stack.
            if char == '(':
                stack.append(i)
            # If the character is a closing parenthesis, check if the stack is not empty.
            elif char == ')':
                # If the stack is not empty, pop the top index from the stack.
                if stack:
                    stack.pop()
                # If the stack is empty, it means there is no matching opening parenthesis for the current closing parenthesis.
                # In this case, replace the current character with an empty string to remove it.
                else:
                    s[i] = ''
        # After processing all characters, there might still be unmatched opening parentheses left in the stack.
        # Iterate through the stack and replace the characters at the indices stored in the stack with an empty string to remove them.
        while stack:
            s[stack.pop()] = ''
        # Join the modified list of characters back into a string and return it.
        return ''.join(s)


""" Approach

    The solution uses a stack to keep track of the indices of opening parentheses in the input string. It iterates through each character in the string. If the character is an 
    opening parenthesis, its index is pushed onto the stack. If the character is a closing parenthesis, the solution checks if the stack is not empty. If the stack is not empty, it 
    means there is a matching opening parenthesis for the current closing parenthesis, so the top index is popped from the stack. If the stack is empty, it means there is no matching 
    opening parenthesis for the current closing parenthesis, so the character is replaced with an empty string to remove it. After processing all characters, there might still be 
    unmatched opening parentheses left in the stack. These are removed by replacing the characters at the indices stored in the stack with an empty string. Finally, the modified list 
    of characters is joined back into a string and returned.

Complexity

    Time complexity: O(n), where n is the length of the string. This is because each character in the string is processed exactly once.
    
    Space complexity: O(n), due to the use of a list to store the characters of the string and a stack to store the indices of opening parentheses. In the worst-case scenario, the 
    stack could contain all indices of opening parentheses, especially if the string contains many unmatched opening parentheses.
 """ 
