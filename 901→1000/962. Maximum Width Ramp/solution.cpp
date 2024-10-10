#include <vector>
#include <stack>
#include <algorithm>

class Solution {
public:
    int maxWidthRamp(std::vector<int>& nums) {
        std::stack<int> stack; // Stack to store indices of potential ramp starts
        int n = nums.size(); // Size of the input vector

        // Step 1: Populate the stack with indices of potential ramp starts
        for (int i = 0; i < n; ++i) {
            // Only push indices where nums[i] is smaller than the top of the stack
            // This ensures that we have a decreasing sequence in the stack
            if (stack.empty() || nums[stack.top()] > nums[i]) {
                stack.push(i); // Store index as a potential starting point
            }
        }

        int max_width = 0; // To store the maximum width of a valid ramp

        // Step 2: Traverse from the end of the array to calculate maximum width
        for (int i = n - 1; i >= 0; --i) {
            // While the current element can form a valid ramp with the top of the stack
            while (!stack.empty() && nums[i] >= nums[stack.top()]) {
                // Update the maximum width by calculating the difference between indices
                max_width = std::max(max_width, i - stack.top());
                // Remove the index from the stack since we found a valid ramp
                stack.pop();
            }
        }

        return max_width; // Return the maximum width of the ramp found
    }
};

/*
Approach:
1. Step 1 - Building a Decreasing Sequence (Stack Construction):
   - The goal in the first loop is to identify indices of potential starting points for the ramp, where the value at the current index is greater than or equal to the value at subsequent indices.
   - We maintain a stack of indices that ensures the values at these indices are in strictly decreasing order. This helps us later identify valid ramps.

2. Step 2 - Traversing Backward and Finding Ramps:
   - In the second loop, we traverse from the last element of the array backward.
   - For each element, we try to pop indices from the stack while the current element is greater than or equal to the value at the index stored at the top of the stack.
   - When a valid ramp is found (i.e., the value at the current index `i` is greater than or equal to the value at the top of the stack), we calculate the width of the ramp (difference between indices) and update the maximum width.
   - We continue popping from the stack to check for other valid ramps that can be formed with the current element.

3. Time Complexity:
   - Stack Population: O(n), since we iterate through the array once and push each index into the stack at most once.
   - Ramp Calculation: O(n), as each index is processed and popped from the stack at most once.
   - Overall, the time complexity is O(n), where `n` is the length of the input array.

4. Space Complexity:
   - The space complexity is O(n), since we use a stack to store indices and the maximum size of the stack can be `n` (if the entire array is in strictly decreasing order).
*/
