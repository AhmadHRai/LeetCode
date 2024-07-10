class Solution {
public:
    int minOperations(vector<string>& logs) {
        // Initialize the result to keep track of the current directory depth
        int res = 0;

        // Iterate through each log entry
        for (const string& log : logs) {
            // If the log is "../", move up one directory if possible
            if (log == "../") {
                if (res > 0) {
                    res--;
                }
            // If the log is not "./" and not "../", it indicates entering a subdirectory
            } else if (log != "./") {
                res++;
            }
        }

        // Return the final directory depth, which represents the number of operations needed
        return res;
    }
};

/* 
Approach

    The solution processes a list of log entries to determine the number of operations required to reach the current directory level.
    - Iterate through each log entry to adjust the current directory depth.
    - If the log entry is "../", decrease the depth by 1 if the current depth is greater than 0.
    - If the log entry is not "./" (which represents staying in the current directory), increase the depth by 1.
    - Return the final depth, which corresponds to the number of operations needed.

Complexity

    Time complexity: O(n), where n is the number of log entries. Each log entry is processed exactly once.
    
    Space complexity: O(1), as only a few additional variables are used beyond the input data.
 */
