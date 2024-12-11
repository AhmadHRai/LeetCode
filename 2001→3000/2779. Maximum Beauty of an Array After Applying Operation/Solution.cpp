class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); // Sort the array to make it easier to find valid subsequences
        int start = 0, ans = 0;
        
        // Iterate over the sorted array
        for(int i = 0; i < nums.size(); i++) {
            // Ensure that the difference between the max and min of the current window does not exceed 2*k, we can replace the while loop with an if statement
            while (nums[i] - nums[start] > 2 * k) {
                start++; // If the difference exceeds 2*k, move the 'start' pointer to reduce the window size
            }
            // Calculate the length of the current valid subsequence
            ans = max(ans, i - start + 1);
        }
        return ans; // Return the maximum subsequence length found
    }
};


/*
This solution is designed to solve the problem of maximizing the beauty of an array after performing a series of operations. The beauty of an array is 
    defined as the length of the longest subsequence consisting of equal elements after modifying the array elements based on the given operation. 
    The operations allow you to modify each element by choosing an index and replacing it with any integer within the range [nums[i] - k, nums[i] + k].

Problem Understanding:
    - You are given:
        A list nums of integers.
        A non-negative integer k.

    In one operation, for any index i, you can replace the value at nums[i] with any number from the range [nums[i] - k, nums[i] + k]. The goal is to maximize the beauty of the array, where beauty is the length of the longest subsequence of equal values after applying the operation any number of times.

Approach:

    Sorting: First, sort the array nums. This is helpful because once sorted, we can more easily identify a subsequence of values where the difference between the maximum and minimum values is at most 2 * k (i.e., within the allowable modification range).

    Two-pointer Technique (Sliding Window): The sliding window approach is used here to explore possible subsequences of numbers that can be transformed into the same value after applying the operation. The idea is to maintain a window of elements that can all be converted to the same value by modifying each element in the window.

    While-loop: The while loop is used to adjust the start pointer such that the window of elements is valid. The window is valid if the difference between the maximum and minimum values in the window is less than or equal to 2 * k. If the window becomes invalid (i.e., the difference exceeds 2 * k), we move the start pointer to shrink the window and make it valid again.

    Maximizing the Length of Valid Subsequence: For every valid window (subsequence), we compute its length and update the maximum beauty (the longest subsequence).

Complexity:
    Time Complexity:

        Sorting the array takes O(n log n) where n is the number of elements in nums.
        The sliding window part of the algorithm runs in O(n), as both start and i pointers move from left to right across the array without ever going backwards.

    Thus, the overall time complexity is O(n log n) due to the sorting step.
    Space Complexity:

        The space complexity is O(1) since we are only using a few extra variables (start, ans) and modifying the input array in place. No additional space is used for data structures like hashmaps or sets.
*/