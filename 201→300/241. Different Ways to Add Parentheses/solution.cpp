class Solution {
public:
    // Main method to compute different ways to evaluate the expression
    vector<int> diffWaysToCompute(string input) {
        unordered_map<string, vector<int>> dpMap; // Memoization map
        return computeWithDP(input, dpMap); // Start the computation
    }

private:
    // Helper method to compute results recursively with memoization
    vector<int> computeWithDP(const string &input, unordered_map<string, vector<int>> &dpMap) {
        // Check if we have already computed the result for this input
        if (dpMap.find(input) != dpMap.end()) {
            return dpMap[input]; // Return cached result
        }

        vector<int> result; // Vector to store possible results
        int size = input.size();

        // Iterate through the input string to find operators
        for (int i = 0; i < size; ++i) {
            char cur = input[i];
            // Check for operators
            if (cur == '+' || cur == '-' || cur == '*') {
                // Split the input string into left and right parts
                string left = input.substr(0, i);
                string right = input.substr(i + 1);

                // Compute results for left and right parts
                vector<int> leftResults = computeWithDP(left, dpMap);
                vector<int> rightResults = computeWithDP(right, dpMap);

                // Combine results based on the current operator
                for (int n1 : leftResults) {
                    for (int n2 : rightResults) {
                        if (cur == '+') {
                            result.push_back(n1 + n2); // Addition
                        } else if (cur == '-') {
                            result.push_back(n1 - n2); // Subtraction
                        } else { // cur == '*'
                            result.push_back(n1 * n2); // Multiplication
                        }
                    }
                }
            }
        }

        // If there are no results, it means the input is a number
        if (result.empty()) {
            result.push_back(atoi(input.c_str())); // Convert string to integer
        }

        // Save the result in the memoization map
        dpMap[input] = result;
        return result; // Return the computed results
    }
};

/*
Approach:
1. Use a recursive approach with memoization to compute all possible results from different ways to evaluate the expression.
2. For each operator found in the input string, split the string into left and right parts and recursively compute results for both parts.
3. Combine the results based on the operator and store them in a vector.
4. If the input string does not contain any operators, it is a number, so convert it to an integer and return.
5. Store results in a map to avoid redundant calculations.

Time Complexity:
- O(n^3) in the worst case due to the number of ways to split the input and the operations performed. Each split could lead to multiple recursive calls.

Space Complexity:
- O(n) for the recursion stack and O(n) for the memoization map storing results for subproblems.
*/
