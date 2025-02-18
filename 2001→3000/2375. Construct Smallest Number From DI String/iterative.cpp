class Solution {
    public:
        string smallestNumber(string pattern) {
            string result; // Result string to store the smallest number
            stack<char> st; // Stack to manage digits
            int n = pattern.size(); // Size of the pattern
    
            // Push digits onto the stack and pop when 'I' is encountered
            for (int i = 0; i <= n; ++i) {
                // Push digits '1' to 'n+1' onto the stack
                st.push('1' + i);
    
                // If we reach an 'I' or it's the end, pop from stack
                if (i == n || pattern[i] == 'I') {
                    // Pop all digits from the stack and append to the result
                    while (!st.empty()) {
                        result += st.top();
                        st.pop();
                    }
                }
            }
    
            return result;
        }
    }
    /*
    Approach Summary:
        This solution uses a stack to efficiently build the smallest number that matches the given pattern. It iteratively pushes digits onto the stack and pops them when 
        an 'I' is encountered or at the end of the pattern, ensuring that the digits are appended to the result string in the correct order.
    
    Complexity Analysis:
    - Time Complexity: O(N), where N is the length of the pattern, because each character in the pattern is processed once.
    - Space Complexity: O(N), for storing the stack and the result string.
    */
    