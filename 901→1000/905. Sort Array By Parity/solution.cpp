class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            if (nums[i] % 2 > nums[j] % 2) {
                swap(nums[i], nums[j]);
            }
            if (nums[i] % 2 == 0) {
                i++;
            }
            if (nums[j] % 2 == 1) {
                j--;
            }
        }
        return nums;
    }
};


/* 
The time complexity of this solution is O(n), where n is the length of the input array.
The space complexity is O(1), as we are not using any extra space.

The approach used here is called two-pointer approach. We use two pointers, one at the beginning and one at the end of the array.
We swap the elements at these pointers if they are not in the correct order (even before odd).
We increment the left pointer if it points to an even number and decrement the right pointer if it points to an odd number.
This way, we can move all even numbers to the beginning of the array and all odd numbers to the end of the array.
 */