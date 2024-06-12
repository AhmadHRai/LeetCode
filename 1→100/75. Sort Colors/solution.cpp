/**
 * Sorts an array of integers where elements are either 0, 1, or 2, in-place.
 * 
 * @param {vector<int>&} nums - The array of integers to be sorted.
 * @return {void} - Modifies the array nums in-place to sort it.
 */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Initialize three pointers: l (low), m (middle), h (high)
        int l = 0;
        int m = 0;
        int h = nums.size() - 1;

        // Traverse the array using the middle pointer m
        while (m <= h) {
            if (nums[m] == 0) {
                // If current element is 0, swap it with element at l, increment l and m
                swap(nums[l], nums[m]);
                l++;
                m++;
            } else if (nums[m] == 1) {
                // If current element is 1, move m forward
                m++;
            } else if (nums[m] == 2) {
                // If current element is 2, swap it with element at h, decrement h
                swap(nums[m], nums[h]);
                h--;
            }
        }
    }
};

/*
Approach:
    1. Three-pointers Approach:
        - Use three pointers: l (low), m (middle), and h (high).
        - Initialize l at the start of the array, m also at the start, and h at the end of the array.
    2. Traverse the Array:
        - Use the middle pointer m to traverse the array from the beginning to the end.
        - Depending on the value of nums[m]:
            - If nums[m] is 0, swap it with nums[l], increment both l and m.
            - If nums[m] is 1, move m forward (no action needed for 1 as it's in the correct place).
            - If nums[m] is 2, swap it with nums[h], decrement h (nums[m] is placed at the end).
    3. Ensure Array is Sorted:
        - Continue this process until m surpasses h, ensuring the entire array is sorted in-place.

Complexity Analysis:
    - Time Complexity: O(n)
      Each element is processed at most twice (once by m and potentially once by l or h), making it a linear time algorithm.
    - Space Complexity: O(1)
      No extra space is used apart from the three pointers, making it an in-place sorting algorithm.

*/

