/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function (s) {
  // Initialize an empty stack to keep track of opening brackets.
  const stack = [];

  // Iterate through each character in the string.
  for (const c of s) {
    // If the character is an opening bracket, push it onto the stack.
    if (c === '(' || c === '{' || c === '[') {
      stack.push(c);
    } else {
      // If the character is a closing bracket, check if the stack is not empty and the top of the stack matches the opening bracket for this closing bracket.
      const last = stack.pop();
      if (
        !last ||
        (c === ')' && last !== '(') ||
        (c === '}' && last !== '{') ||
        (c === ']' && last !== '[')
      ) {
        // If the stack is empty or the top of the stack does not match the opening bracket for this closing bracket, return false.
        return false;
      }
    }
  }

  // After iterating through all characters, if the stack is empty, it means all opening brackets have been properly closed.
  // If the stack is not empty, it means there are unmatched opening brackets, so return false.
  return stack.length === 0;
};

/* 
Approach Explanation:
    The function isValid takes a string s as input and checks if it is a valid sequence of parentheses.
    An empty stack is used to keep track of opening brackets. When an opening bracket is encountered, it is pushed onto the stack.
    When a closing bracket is encountered, the function checks if the stack is not empty and if the top of the stack matches the opening bracket for this closing bracket. If 
    not, it returns false.
    After iterating through all characters in the string, if the stack is empty, it means all opening brackets have been properly closed. If the stack is not empty, it means 
    there are unmatched opening brackets, so the function returns false.

Time Complexity Analysis:
    The time complexity of this function is O(n), where n is the length of the input string. This is because the function iterates through each character in the string once.

Space Complexity Analysis:
    The space complexity is O(n) in the worst case, where n is the length of the input string. This is because in the worst case, all characters in the string are opening 
    brackets, and they are all pushed onto the stack.
*/
