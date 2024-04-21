class Solution {
public:
    int maxDepth(string s) {
        // Initialize variables to store the maximum depth and the current depth.
        int res = 0;
        int depth = 0;

        // Iterate through each character in the string.
        for(int i = 0; i < s.size(); ++i) {
            // If the current character is an opening parenthesis, increment the current depth.
            if(s[i] == '(') {
                ++depth;
            }
            // If the current character is a closing parenthesis, decrement the current depth.
            else if(s[i] == ')') {
                --depth;
            }
            // Update the maximum depth if the current depth is greater than the maximum depth found so far.
            res = max(depth, res);
        }

        // Return the maximum depth found.
        return res;
    }
};

/* 
Approach Summary

    This solution iterates through each character in the input string `s`. It maintains a variable `depth` to keep track of the current 
    nesting depth of parentheses. When an opening parenthesis is encountered, `depth` is incremented. When a closing parenthesis is 
    encountered, `depth` is decremented. The maximum depth encountered during the iteration is stored in `res`.

Time Complexity Analysis

    The time complexity is O(n), where n is the length of the input string `s`. This is because each character in the string is visited once.

Space Complexity Analysis

    The space complexity is O(1), as the algorithm uses a constant amount of space to store variables and does not use any additional 
    data structures that grow with the size of the input string.

 */