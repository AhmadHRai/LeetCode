class Solution {
public:
    int maximumGain(string s, int x, int y) {
        // Initialize the result variable to keep track of the maximum gain
        int res = 0;
        
        // Variables to store the patterns and their corresponding scores
        string top, bot;
        int top_score, bot_score;

        // Determine which pattern ("ab" or "ba") has the higher score
        if (y > x) {
            top = "ba";
            top_score = y;
            bot = "ab";
            bot_score = x;
        } else {
            top = "ab";
            top_score = x;
            bot = "ba";
            bot_score = y;
        }

        // First pass: remove "top" substrings to maximize the score
        vector<char> stack;
        for (char ch : s) {
            // Check if the current character forms the "top" substring with the top of the stack
            if (ch == top[1] && !stack.empty() && stack.back() == top[0]) {
                // Add the score for this "top" substring and pop from the stack
                res += top_score;
                stack.pop_back();
            } else {
                // Push the current character onto the stack
                stack.push_back(ch);
            }
        }

        // Second pass: remove "bot" substrings from the remaining characters in the stack
        vector<char> new_stack;
        for (char ch : stack) {
            // Check if the current character forms the "bot" substring with the top of the new stack
            if (ch == bot[1] && !new_stack.empty() && new_stack.back() == bot[0]) {
                // Add the score for this "bot" substring and pop from the new stack
                res += bot_score;
                new_stack.pop_back();
            } else {
                // Push the current character onto the new stack
                new_stack.push_back(ch);
            }
        }

        // Return the maximum gain achieved
        return res;
    }
};

/* 
Approach

    The solution aims to maximize the gain by removing specific substrings from the given string.
    - Determine which substring ("ab" or "ba") has the higher score and process that substring first.
    - In the first pass, remove occurrences of the "top" substring from the string, which gives a higher score.
    - In the second pass, remove occurrences of the "bot" substring from the remaining characters, which gives a lower or equal score.
    - Use two stacks to efficiently process and remove the substrings while keeping track of the scores.

Complexity

    Time complexity: O(n), where n is the length of the string. This is because each character is processed twice, once for each pass.
    
    Space complexity: O(n), due to the space required for the stacks used to track characters.
 */
