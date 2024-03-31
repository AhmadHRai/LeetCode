class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long answer = 0; // Variable to store the final count of subarrays
        int lastMinIndex = -1; // Index of the last occurrence of minK
        int lastMaxIndex = -1; // Index of the last occurrence of maxK
        int lastIndexOutsideRange = -1; // Index of the last number that is outside the [minK, maxK] range

        // Iterate through the array to count valid subarrays
        for (int i = 0; i < nums.size(); ++i) {
            // If current element is outside the [minK, maxK] range, update the index
            if (nums[i] < minK || nums[i] > maxK) lastIndexOutsideRange = i;
            // If current element equals minK, update the index of the last occurrence of minK
            if (nums[i] == minK) lastMinIndex = i;
            // If current element equals maxK, update the index of the last occurrence of maxK
            if (nums[i] == maxK) lastMaxIndex = i;

            // Count subarrays ending at index i which have minK and maxK within them
            answer += max(0, min(lastMinIndex, lastMaxIndex) - lastIndexOutsideRange);
        }

        return answer; // Return the total count of valid subarrays
    }
};

/* 
Approach Summary

    The algorithm counts the number of subarrays that contain both `minK` and `maxK` within them. It does this by iterating through the 
    array and maintaining indices of the last occurrence of `minK`, `maxK`, and the last number that is outside the `[minK, maxK]` 
    range. For each element in the array, it updates these indices accordingly and counts the number of subarrays ending at the current 
    index that have `minK` and `maxK` within them.

    The algorithm starts by initializing variables for the final count of subarrays, the indices of the last occurrence of `minK` and 
    `maxK`, and the last number outside the range. It then enters a loop that continues until the end of the array is reached. Inside 
    the loop, it updates the indices based on the current element and counts the number of subarrays ending at the current index that 
    have `minK` and `maxK` within them.

Time Complexity Analysis

    The time complexity of this algorithm is O(n), where n is the length of the input array `nums`. This is because each element in the 
    array is visited once.

Space Complexity Analysis

    The space complexity is O(1), as the algorithm uses a constant amount of space to store variables and does not use any additional 
    data structures that grow with the size of the input array.

 */