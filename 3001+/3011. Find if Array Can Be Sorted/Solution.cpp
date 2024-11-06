class Solution {
public:
    // Function to check if the array can be sorted using the given conditions
    static bool canSortArray(const vector<int> &nums) {
        // Get the size of the input array
        const uint8_t n = nums.size();
        
        // Initialize variables:
        // pmax keeps track of the maximum value from previous segments
        // cmin keeps track of the minimum value in the current segment
        // cmax keeps track of the maximum value in the current segment
        uint16_t pmax = 0, cmin = 0, cmax = 0;
        
        // pcnt will store the population count of the current value
        uint8_t pcnt = 0;
        
        // Loop through each element in the array
        for (const uint16_t v : nums) {
            // Get the population count (number of 1-bits) in the current number
            if (const uint8_t ccnt = popcount(v); pcnt == ccnt) {
                // If the population count is the same as the previous one, we are still in the same segment
                // Update the current segment's min and max values
                cmin = min(cmin, v);
                cmax = max(cmax, v);
            } else if (cmin < pmax) {
                // If the minimum of the current segment is smaller than the previous segment's max value,
                // the array cannot be sorted and we return false
                return false;
            } else {
                // Otherwise, the current segment has ended, so update pmax (the previous segment's max)
                // and reset the current segment values (cmin, cmax, pcnt) to the new segment's values
                pmax = cmax;
                cmin = cmax = v;
                pcnt = ccnt;
            }
        }
        
        // Return true if the minimum value of the last segment is greater than or equal to the max value of the previous segment
        return cmin >= pmax;
    }
};

/*
Approach Summary:
- The problem asks whether we can sort the array in a way that the population counts (number of 1-bits) of elements in each consecutive segment are the same.
- We maintain two segments while traversing the array: the previous segment and the current segment.
- For each element in the array, we calculate its population count (`popcount`), and we compare it with the population count of the previous element.
- If the population count is the same, we extend the current segment and update the minimum and maximum values for the segment.
- If the population count is different, we check if the minimum value of the current segment is greater than or equal to the maximum value of the previous segment.
  - If not, we return false, as sorting is not possible.
  - Otherwise, we update the previous segment's maximum value to the current segment's maximum, and reset the current segment's min, max, and population count.
- The process continues until all elements are processed, and at the end, we check if the last segment's minimum value is greater than or equal to the previous segment's maximum value.

Complexity Analysis:
- Time Complexity: O(n), where n is the length of the array. We iterate through the array exactly once, and each operation inside the loop is constant time.
- Space Complexity: O(1), since we only use a constant amount of extra space for the variables (`pmax`, `cmin`, `cmax`, `pcnt`, etc.) regardless of the input size.
*/
