class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // Constants and initialization
        const int OFFSET = -5 * 1e4;  // Minimum value of possible input (based on problem constraints)
        const int RANGE_SIZE = 1e5 + 1; // Size of frequency array
        int frequency[RANGE_SIZE] = {0}; // Frequency array for counting occurrences
        int maxValue = -1, minValue = RANGE_SIZE; // Variables to track the range of values in nums

        // Step 1: Compute frequency of each value and determine the range
        for (int num : nums) {
            int adjustedValue = num - OFFSET;  // Adjust the value to be non-negative
            frequency[adjustedValue]++;       // Increment the frequency count for the adjusted value
            maxValue = max(adjustedValue, maxValue);  // Update maximum value encountered
            minValue = min(adjustedValue, minValue);  // Update minimum value encountered
        }

        // Step 2: Rebuild the sorted array based on frequencies
        for (int i = 0, value = minValue; value <= maxValue; value++) {
            int count = frequency[value];   // Get frequency of the current value
            fill(nums.begin() + i, nums.begin() + i + count, value + OFFSET); // Fill the array with the current value
            i += count; // Move the index forward by the frequency count
        }

        return nums;  // Return the sorted array
    }
};

/*
Approach

    1. **Frequency Counting**:
       - Use a frequency array to count occurrences of each value in `nums`.
       - Adjust values to ensure they are non-negative for proper indexing.
       - Track the minimum and maximum values to define the range of indices needed.

    2. **Rebuilding the Sorted Array**:
       - Iterate through the frequency array.
       - For each value in the range from `xmin` to `xMax`, fill the `nums` array with the corresponding values based on their frequencies.
       - This effectively sorts the array in-place.

Complexity

    Time complexity: O(n), where n is the number of elements in `nums`. The time complexity is dominated by the single pass required to count frequencies and then another pass to rebuild the array.
    
    Space complexity: O(k), where k is the range of values in `nums`. The space complexity is due to the frequency array of size `N`.

This approach efficiently sorts the array by leveraging frequency counting, making it suitable for cases with limited value ranges and a high number of elements.
*/
