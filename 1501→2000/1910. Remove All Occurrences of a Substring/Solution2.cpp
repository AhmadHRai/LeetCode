class Solution {
    public:
        // Removes all occurrences of a substring from a string using a stack
        string removeOccurrences(string s, string part) {
            stack<char> stk; // Stack to build the result string
            int strLength = s.length(); // Length of the input string
            int partLength = part.length(); // Length of the substring to be removed
    
            // Iterate through each character in the input string
            for (int index = 0; index < strLength; index++) {
                // Push the current character onto the stack
                stk.push(s[index]);
    
                // Check if the top elements of the stack match the substring
                if (stk.size() >= partLength && checkMatch(stk, part, partLength)) {
                    // If they match, remove the substring from the stack
                    for (int j = 0; j < partLength; j++) {
                        stk.pop();
                    }
                }
            }
    
            // Build the result string from the stack
            string result = "";
            while (!stk.empty()) {
                result = stk.top() + result;
                stk.pop();
            }
    
            return result;
        }
    
    private:
        // Checks if the top elements of the stack match the substring
        bool checkMatch(stack<char>& stk, string& part, int partLength) {
            // Create a temporary stack to avoid modifying the original stack
            stack<char> temp = stk;
    
            // Compare the top elements of the temporary stack with the substring
            for (int partIndex = partLength - 1; partIndex >= 0; partIndex--) {
                if (temp.top() != part[partIndex]) {
                    return false; // Mismatch found
                }
                temp.pop();
            }
            return true; // All elements match
        }
    }

    /*
    Approach Summary:
        This solution uses a stack to iteratively build the result string while removing occurrences of a given substring. It checks for matches by comparing the top 
        elements of the stack with the substring and removes matches as they are found.
    
    Complexity Analysis:
    - Time Complexity: O(N), where N is the length of the input string, because each character is visited once.
    - Space Complexity: O(N), for storing characters in the stack.
    */
    