class Solution {
public:
    // Method to construct the largest number from a list of integers
    string largestNumber(vector<int> &num) {
        // Vector to hold the string representation of the numbers
        vector<string> arr;
        for (auto i : num) {
            // Convert each integer to a string and store it in the array
            arr.push_back(to_string(i));
        }
        
        // Sort the array using a custom comparator
        sort(begin(arr), end(arr), [](string &s1, string &s2) { 
            // Compare concatenated strings to determine order
            return s1 + s2 > s2 + s1; 
        });
        
        // String to hold the result
        string res;
        for (auto s : arr) {
            // Concatenate all sorted strings to form the largest number
            res += s;
        }
        
        // Handle case where the largest number is "0"
        while (res[0] == '0' && res.length() > 1) {
            // Remove leading zeros if the result is not just "0"
            res.erase(0, 1);
        }
        
        return res; // Return the final largest number as a string
    }
};

/*
Approach:
1. Convert each integer in the input vector to a string and store it in a new vector.
2. Sort this vector using a custom comparator that determines the order based on 
   which concatenation of two strings yields a larger result.
3. Concatenate the sorted strings to form the final largest number.
4. Remove leading zeros in case the result is not just "0".

Time Complexity:
- O(n log n) due to the sorting step, where `n` is the number of elements in the input vector.

Space Complexity:
- O(n) for storing the string representations of the integers. The space used for sorting is typically O(1) if we disregard the input and output space.
*/
