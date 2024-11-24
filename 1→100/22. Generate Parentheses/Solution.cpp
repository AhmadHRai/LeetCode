class Solution {
public:
    // generate parentheses combinations
    void generateParenthesisHelper(int openCount, int closeCount, std::string current, std::vector<std::string>& result) {
        // Base case: If no more open or close parentheses to add, the current string is a valid combination
        if (openCount == 0 && closeCount == 0) {
            result.push_back(current); // Add the current valid combination to the result
            return;
        }
        
        // If there are still open parentheses to add, add an open parenthesis and recurse
        if (openCount > 0) {
            generateParenthesisHelper(openCount - 1, closeCount + 1, current + "(", result);
        }
        
        // If there are unmatched close parentheses, add a close parenthesis and recurse
        if (closeCount > 0) {
            generateParenthesisHelper(openCount, closeCount - 1, current + ")", result);
        }
    }
    
    // Function to generate all valid combinations of parentheses
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result; // Vector to store all valid combinations
        generateParenthesisHelper(n, 0, "", result); // Start recursion with n open parentheses and 0 close parentheses
        return result; // Return the list of valid parentheses combinations
    }
};

/*
Approach Summary:
- The solution uses backtracking to generate all valid combinations of parentheses.
- The helper function `generateParenthesisHelper` takes the counts of open and close parentheses remaining, the current string, and the result vector.
- It recursively adds open and close parentheses while ensuring the number of close parentheses never exceeds the number of open parentheses at any point.
- The recursion stops when all open and close parentheses are used, and the current valid combination is added to the result.

Complexity Analysis:
- Time Complexity: O(4^n / √n), where n is the number of pairs of parentheses. This is because the number of valid combinations grows exponentially, and the Catalan number, which counts valid combinations of parentheses, approximates 4^n / √n.
- Space Complexity: O(n), where n is the number of pairs of parentheses. The depth of the recursion can go up to 2n, and the space used to store the valid combinations in the result vector is proportional to the number of combinations.
*/
