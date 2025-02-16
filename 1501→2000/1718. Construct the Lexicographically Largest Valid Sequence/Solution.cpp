class Solution {
    public:
        // Constructs a distanced sequence of length n * 2 - 1
        vector<int> constructDistancedSequence(int n) {
            // Initialize the sequence with zeros
            vector<int> ans(n * 2 - 1, 0);
    
            // Track visited numbers to ensure each appears exactly twice
            vector<bool> visited(n + 1, false);
    
            // Start the recursive construction process
            calc(0, ans, visited, n);
            return ans;
        }
    
    private:
        // Recursive function to construct the distanced sequence
        bool calc(int index, vector<int>& ans, vector<bool>& visited, int n) {
            // Base case: If the entire sequence is filled, return true
            if (index == ans.size()) {
                return true;
            }
    
            // If the current position is already filled, move to the next index
            if (ans[index] != 0) {
                return calc(index + 1, ans, visited, n);
            } else {
                // Try numbers from n to 1 to construct the lexicographically largest sequence
                for (int i = n; i >= 1; i--) {
                    if (visited[i]) {
                        continue; // Skip if the number has been used twice
                    }
                    visited[i] = true; // Mark the number as used
                    ans[index] = i;
    
                    if (i == 1) {
                        // If i is 1, only one occurrence is needed, so move to the next index
                        if (calc(index + 1, ans, visited, n)) {
                            return true;
                        }
                    } else if (index + i < ans.size() && ans[index + i] == 0) {
                        // Place the second occurrence of i at the correct distance
                        ans[index + i] = i;
                        if (calc(index + 1, ans, visited, n)) {
                            return true; // Sequence found, no need to backtrack
                        }
                        ans[index + i] = 0; // Reset if the sequence doesn't work out
                    }
                    ans[index] = 0; // Reset the current position
                    visited[i] = false; // Allow the number to be used again
                }
            }
            return false; // No valid sequence found
        }
    }

    /*
    Approach Summary:
        This solution constructs a distanced sequence by using a recursive backtracking approach. It iteratively tries numbers from n to 1, ensuring each number appears exactly twice and is placed at the correct distance.
    
    Complexity Analysis:
        Time Complexity: O(N!), where N is the input number, because in the worst case, all permutations of numbers need to be explored.
        Space Complexity: O(N), for storing the sequence and visited numbers.
    */
    