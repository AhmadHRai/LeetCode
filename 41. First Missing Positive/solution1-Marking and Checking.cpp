class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // Mark all non-positive numbers as n+1
        for (int i = 0; i < n; i++) if (nums[i] <= 0) nums[i] = n + 1;
        // Mark the index of the number as negative if the number is within the range [1, n]
        for (int i = 0; i < n; i++) if (abs(nums[i]) <= n && nums[abs(nums[i]) - 1] > 0) nums[abs(nums[i]) - 1] *= -1;
        // Find the first index that is not marked as negative, which corresponds to the first missing positive number
        for (int i = 0; i < n; i++) if (nums[i] > 0) return i + 1;
        // If no positive number is found, return n+1 as the first missing positive number
        return n + 1;
    }
};

/* 
Approach Summary:
    This solution first marks all non-positive numbers as n+1 to ensure they are not considered as missing positive numbers. Then, it iterates through the array, marking the index 
    of each number as negative if the number is within the range [1, n]. Finally, it finds the first index that is not marked as negative, which corresponds to the first missing 
    positive number.

Complexity Analysis:
    Time Complexity: O(n), where n is the number of elements in the array. This is because each element is visited at most twice.
    Space Complexity: O(1), as the solution uses a constant amount of space to store the pointers and does not depend on the size of the input array.
 */
