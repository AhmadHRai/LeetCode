class Solution {
public:
    // Method to construct the largest number from a list of integers
    string largestNumber(vector<int>& nums) {
        // Vector to hold the string representation of the numbers
        vector<string> array;
        for (int num : nums) {
            // Convert each integer to a string and store it in the array
            array.push_back(to_string(num));
        }

        // Custom comparator for sorting the strings
        sort(array.begin(), array.end(), [](const string &a, const string &b) {
            // Sort by comparing concatenated strings in reverse order
            return (b + a) < (a + b); // Place larger concatenated result first
        });

        // Debugging: Output the sorted strings (optional)
        for(int i = 0; i < array.size(); i++) {
            cout << array[i] << " "; // Print each element in the sorted array
        } 

        // Handle the case where the largest number is "0"
        if (array[0] == "0") {
            return "0"; // If the first element is "0", the largest number is "0"
        }

        // Build the largest number from the sorted array
        string largest;
        for (const string &num : array) {
            largest += num; // Concatenate all strings to form the largest number
        }

        return largest; // Return the largest number as a string
    }
};

/*
Approach:
1. Convert each integer in the input vector to a string and store it in a new vector.
2. Sort this string vector using a custom comparator that determines the order based on 
   which concatenation of two strings yields a larger result.
3. If the largest concatenated string is "0", return "0" (handles cases with multiple zeros).
4. Concatenate the sorted strings to form the final largest number.

Time Complexity:
- O(n log n) due to the sorting step, where `n` is the number of elements in the input vector.

Space Complexity:
- O(n) for storing the string representations of the integers. The space used for sorting is typically O(1) if we disregard the input and output space.
*/
