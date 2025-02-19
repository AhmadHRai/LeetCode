class Solution {
    public:
        string getHappyString(int n, int k) {
            string result = ""; 
            string chars = "abc"; // Characters to use in the string
    
            backtrack(n, k, result, chars);
    
            return result;
        }
    
    private:
        void backtrack(int n, int& k, string& result, const string& chars) {
            // Base case: If the result string has reached the desired length
            if (result.length() == n) {
                k--; // Decrement k for each valid string found
                if (k == 0) {
                    return; // We found the k-th string, stop further processing
                }
                return;
            }
    
            // Try all possible characters
            for (char c : chars) {
                // Check if the character is different from the last one in the result
                if (result.empty() || result.back() != c) {
                    result.push_back(c); // Add the character to the result
                    backtrack(n, k, result, chars); // Recurse to find the next character
                    if (k == 0) return; // Stop further processing if we found the k-th string
                    result.pop_back(); // Backtrack: remove the last character
                }
            }
        }
    }
    /*
    Approach Summary:
        This solution uses a recursive backtracking approach to find the k-th lexicographically smallest happy string of length n. It iteratively tries all possible 
        characters, ensuring that no two consecutive characters are the same, and stops once the k-th valid string is found.
    
    Complexity Analysis:
        Time Complexity: O(N * 3^N), where N is the length of the string, because in the worst case, all possible combinations of characters need to be explored.
        Space Complexity: O(N), for storing the recursion stack and the result string.
    */
    