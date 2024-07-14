class Solution {
public:
    string countOfAtoms(string formula) {
        // Get the length of the formula
        int n = formula.length();
        
        // Maps to store element counts and manage nested parentheses
        unordered_map<string, int> result_counter;
        stack<unordered_map<string, int>> parenthesis_stack;
        int cur_ind = 0;

        // Process each character in the formula
        while (cur_ind < n) {
            char cur_char = formula[cur_ind];

            if (cur_char == '(') {
                // Start a new scope for nested parentheses
                cur_ind++;
                parenthesis_stack.push(unordered_map<string, int>());
                continue;
            }

            if (cur_char == ')') {
                // End of a nested scope, handle multiplier for parentheses
                string mult_str = "";
                cur_ind++;

                // Read the multiplier if present
                while (cur_ind < n && isdigit(formula[cur_ind])) {
                    mult_str += formula[cur_ind];
                    cur_ind++;
                }

                int mult = mult_str.empty() ? 1 : stoi(mult_str);
                unordered_map<string, int> last_counter = parenthesis_stack.top();
                parenthesis_stack.pop();
                unordered_map<string, int>& target = parenthesis_stack.empty() ? result_counter : parenthesis_stack.top();
                
                // Update the counts for elements in the parenthesis scope
                for (const auto& [elem, counter] : last_counter) {
                    target[elem] += counter * mult;
                }
                continue;
            }

            // Process elements and their counts
            string cur_elem = "";
            string cur_counter_str = "";
            unordered_map<string, int>& target = parenthesis_stack.empty() ? result_counter : parenthesis_stack.top();

            while (cur_ind < n && formula[cur_ind] != '(' && formula[cur_ind] != ')') {
                if (isalpha(formula[cur_ind])) {
                    if (isupper(formula[cur_ind]) && !cur_elem.empty()) {
                        // Add previous element count to the result
                        target[cur_elem] += cur_counter_str.empty() ? 1 : stoi(cur_counter_str);
                        cur_elem = "";
                        cur_counter_str = "";
                    }
                    cur_elem += formula[cur_ind];
                } else {
                    cur_counter_str += formula[cur_ind];
                }
                cur_ind++;
            }

            // Add the last element to the result
            target[cur_elem] += cur_counter_str.empty() ? 1 : stoi(cur_counter_str);
        }

        // Prepare the result string sorted by element names
        vector<string> parts;
        for (const auto& [elem, counter] : result_counter) {
            parts.push_back(elem + (counter == 1 ? "" : to_string(counter)));
        }
        sort(parts.begin(), parts.end());

        string result;
        for (const auto& part : parts) {
            result += part;
        }

        return result;
    }
};

/* 
Approach

    The solution parses a chemical formula string to count the number of each type of atom considering nested parentheses and multipliers.
    - Use a stack to manage nested scopes and a map to keep track of atom counts.
    - Process characters to handle elements, multipliers, and parentheses.
    - Update the count of elements based on the multipliers and handle nested scopes accordingly.
    - Construct and return the result string with elements sorted in lexicographical order.

Complexity

    Time complexity: O(n log n), where n is the length of the formula. This includes the time to parse the formula and sort the result.
    
    Space complexity: O(n), due to the space required for the stack and maps used to store element counts and manage nested scopes.
 */
