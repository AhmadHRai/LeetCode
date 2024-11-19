class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long global, local;  // Declare variables to store the global and local maximum sums
        global = local = 0;  // Initialize both global and local sums to 0
        
        bool pre[(int)(1e5 + 1)] = {false};  // Boolean array to track if a number has appeared in the current window
        
        int l, r, n = nums.size();  // Declare left pointer, right pointer, and size of the input array

        for(l = r = 0; l < n; l++) {  // Iterate over the array with 'l' as the left pointer
            local += nums[l];  // Add the current element to the local sum
            
            while(pre[nums[l]] || l - r == k) {  // If the number has appeared already or the window size exceeds k
                local -= nums[r];  // Subtract the element at the left pointer (sliding window)
                pre[nums[r++]] = false;  // Mark the number at the left pointer as not part of the current window and move the right pointer
            }
            
            pre[nums[l]] = true;  // Mark the current number as part of the window

            if(l - r + 1 == k)  // If the current window size is exactly k
                global = max(global, local);  // Update the global maximum sum if the local sum is greater

        }
        
        return global;  // Return the global maximum sum found
    }
};

/*
Approach Summary:
- This solution uses the sliding window technique with two pointers (left `l` and right `r`) to find the maximum sum of a subarray of length `k` with all distinct elements.
- We use an array `pre` to track which elements have been seen in the current window. This helps in ensuring all elements in the window are distinct.
- As we iterate through the array with `l` as the left pointer, we add the current element `nums[l]` to the local sum.
- If an element has already appeared in the current window or the window size exceeds `k`, we move the right pointer `r` forward, adjusting the local sum and marking elements as not part of the window.
- Once the window size is exactly `k`, we check if the current sum is the maximum and update the global maximum if necessary.

Complexity Analysis:
- Time Complexity: O(n), where `n` is the number of elements in the array. The sliding window approach ensures each element is added and removed at most once, leading to a linear scan of the array.
- Space Complexity: O(maxValue), where `maxValue` is the size of the `pre` array, which is `1e5 + 1` in this case. This is used to track the occurrence of each number within the window. This can be considered O(1) since the size is constant.
*/
