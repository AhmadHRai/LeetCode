class Solution {
public:
    // Method to find the length of the longest common prefix between two arrays of integers
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> st; // Set to store all prefixes from arr1
        
        // Iterate through each integer in arr1
        for (int i = 0; i < arr1.size(); i++) {
            string val = to_string(arr1[i]); // Convert integer to string
            string prefix; // Initialize an empty string to store prefixes
            
            // Iterate through each character in the string representation of the integer
            for (auto ch : val) {
                prefix += ch; // Append character to prefix
                st.insert(prefix); // Add the current prefix to the set
            }
        }
        
        int ans = 0; // Variable to store the maximum length of common prefix
        
        // Check every prefix combination in arr2
        for (int i = 0; i < arr2.size(); i++) {
            string val = to_string(arr2[i]); // Convert integer to string
            string prefix; // Initialize an empty string to store prefixes
            
            // Iterate through each character in the string representation of the integer
            for (auto ch : val) {
                prefix += ch; // Append character to prefix
                // If the prefix exists in the set, update the maximum length
                if (st.count(prefix)) {
                    ans = max(ans, (int)prefix.size()); // Update ans with the length of the prefix
                }
            }
        }
        
        return ans; // Return the length of the longest common prefix
    }
};

/*
Approach:
1. Create a set to store all possible prefixes of numbers from `arr1`.
2. For each number in `arr1`, convert it to a string and generate all its prefixes, storing them in the set.
3. For each number in `arr2`, convert it to a string and check its prefixes against the set.
4. Track the maximum length of prefixes found in the set from `arr2`.

Time Complexity:
- O(N * M), where N is the total number of integers in `arr1` and M is the total number of integers in `arr2`. Each integer's string representation is processed character by character.

Space Complexity:
- O(P), where P is the total number of unique prefixes stored in the set. In the worst case, it can be proportional to the combined lengths of all integers in `arr1`.
*/
