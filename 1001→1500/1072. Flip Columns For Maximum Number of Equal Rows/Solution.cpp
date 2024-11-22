class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int> hmap; // Create a hash map to count occurrences of each relative row pattern
        
        // Iterate over each row in the matrix
        for(auto x: matrix){
            string s=""; // Initialize a string to store the relative row pattern
            int top=x[0]; // The first element of the row is the reference for the row's pattern
            // Traverse each element in the row
            for(int i=0;i<x.size();i++){
                // If the current element is the same as the first element, append '1' to the string
                if(x[i]==top)
                    s+='1';
                else
                    s+='0'; // Otherwise, append '0'
            }
            hmap[s]++; // Increment the count of the current row pattern in the hash map
        }
        
        int result=0; // Variable to store the maximum number of rows with the same relative ordering
        // Iterate over all the row patterns in the hash map
        for(auto &[key,val]:hmap)
            result=max(result,val); // Update the result with the highest count of identical row patterns
        
        // The result represents the maximum number of rows with the same relative ordering,
        // which can be flipped to make all elements identical across those rows.
        return result; // Return the final result
    }
};

/*
Approach Summary:
- The solution uses a hash map (unordered_map) to store relative row patterns.
- For each row in the matrix, we generate a pattern by comparing each element with the first element in the row.
- The pattern is represented as a string of '1's and '0's based on whether the element matches the first element of the row.
- The rows with the same relative pattern can be toggled simultaneously to make them equal across all columns.
- The answer is the maximum number of rows that have the same relative ordering.

Complexity Analysis:
- Time Complexity: O(m * n), where m is the number of rows and n is the number of columns in the matrix.
  - We iterate through each row, and for each row, we traverse through all its elements to generate a pattern.
- Space Complexity: O(m * n), because in the worst case, we store each unique row pattern in the hash map, which can be as large as the total number of rows times the length of each row.
*/
