class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n = nums.size();
        // Swap each number with the number at its correct index if it is within the range [1, n] and not already at its correct index
        for(int i = 0; i < nums.size(); i++) {
            while(nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i]-1]) {
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        // Find the first index that does not match its value plus one, which corresponds to the first missing positive number
        for(int i = 0; i < nums.size(); i++) if(nums[i] != i + 1) return i + 1;
        // If no positive number is found, return n+1 as the first missing positive number
        return nums.size() + 1;
    }
};

/* 
Approach Summary:
    This solution uses a swapping technique to place each number at its correct index if it is within the range [1, n]. It iterates through the array, swapping each number with the 
    number at its correct index if it is not already there. Finally, it finds the first index that does not match its value plus one, which corresponds to the first missing positive 
    number.

Complexity Analysis:
    Time Complexity: O(n), where n is the number of elements in the array. This is because each element is visited at most twice.
    Space Complexity: O(1), as the solution uses a constant amount of space to store the pointers and does not depend on the size of the input array.
 */
