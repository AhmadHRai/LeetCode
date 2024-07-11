class Solution {
public:
    string reverseParentheses(string s) {
        // Get the length of the string
        int n = s.length();
        
        // Initialize a vector to keep track of matching parentheses indices
        vector<int> index_pairs(n, 0);
        
        // Use a deque to keep track of the start indices of open parentheses
        deque<int> stack_start_ind;

        // Iterate through each character in the string to find matching parentheses
        for (int char_ind = 0; char_ind < n; ++char_ind) {
            char char_s = s[char_ind];
            if (char_s == '(') {
                // Push the index of the open parenthesis onto the stack
                stack_start_ind.push_back(char_ind);
            } else if (char_s == ')') {
                // Pop the index of the matching open parenthesis from the stack
                int start_ind = stack_start_ind.back();
                stack_start_ind.pop_back();
                
                // Store the matching indices for both parentheses
                index_pairs[char_ind] = start_ind;
                index_pairs[start_ind] = char_ind;
            }
        }

        // Initialize the result string and variables for current index and direction
        string res;
        int cur_ind = 0;
        int cur_dir = 1;

        // Process the string to handle parentheses and reverse sections
        while (cur_ind < n) {
            char char_s = s[cur_ind];
            if (char_s == '(' || char_s == ')') {
                // Jump to the matching parenthesis and reverse direction
                cur_ind = index_pairs[cur_ind];
                cur_dir *= -1;
            } else {
                // Append the character to the result string
                res.push_back(char_s);
            }
            cur_ind += cur_dir;
        }

        // Return the final result string after processing
        return res;
    }
};

/* 
Approach

    The solution processes a string with nested parentheses to reverse the sections within parentheses. 
    - First, find matching parentheses and store their indices in the `index_pairs` vector.
    - Use a deque to track the start indices of open parentheses.
    - Iterate through the string, adjusting the direction of traversal when encountering parentheses, and reverse the segments accordingly.
    - Build the result string by appending characters and handle direction changes when necessary.

Complexity

    Time complexity: O(n), where n is the length of the string. This is because each character is processed a constant number of times.
    
    Space complexity: O(n), due to the space required for storing indices in the `index_pairs` vector and the deque.
 */
