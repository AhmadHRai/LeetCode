class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        // Create an unordered map to store the frequency of each string in the array
        unordered_map<string, int> counter;
        
        // Iterate over each string in the array and update the frequency count
        for (auto& v : arr) {
            ++counter[v];
        }
        
        // Iterate over each string in the array again to find the kth distinct string
        for (auto& v : arr) {
            // Check if the current string is distinct (appears only once)
            if (counter[v] == 1) {
                // Decrement k since we've found one distinct string
                --k;
                // If k reaches 0, return the current string as the kth distinct string
                if (k == 0) return v;
            }
        }
        
        // If no kth distinct string is found, return an empty string
        return "";
    }
};

/*
Approach:
1. Use an unordered map to count the frequency of each string in the input vector `arr`.
2. Iterate through the array to populate the frequency counter.
3. Iterate through the array again to find the kth distinct string:
   - Check if the current string is distinct (frequency is 1).
   - Decrement k for each distinct string found.
   - When k reaches 0, return the current string as the kth distinct string.
4. If no such string is found, return an empty string.

Complexity Analysis:
- Time Complexity: O(n), where n is the number of elements in the input vector `arr`.
  - Building the frequency counter takes O(n) time.
  - The second iteration to find the kth distinct string also takes O(n) time.
- Space Complexity: O(n), where n is the number of elements in the input vector `arr`.
  - The unordered map used to store the frequency of each string can have up to n unique strings in the worst case.
*/
