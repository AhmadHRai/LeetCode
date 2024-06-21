from typing import List

class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], X: int) -> int:
        i = win_of_make_satisfied = satisfied = max_make_satisfied = 0
        
        # Iterate through the customers and grumpy arrays simultaneously
        for c, g in zip(customers, grumpy):
            satisfied += (1 - g) * c  # Add to satisfied if not grumpy
            win_of_make_satisfied += g * c  # Add to the window of make satisfied
            
            # Slide the window of length X
            if i >= X:
                win_of_make_satisfied -= grumpy[i - X] * customers[i - X]
            
            # Update the maximum make satisfied within the sliding window
            max_make_satisfied = max(win_of_make_satisfied, max_make_satisfied)
            
            i += 1  # Increment the index
        
        # Return the total satisfied customers, including the maximum make satisfied in any window
        return satisfied + max_make_satisfied

"""
Approach:
- Use two sliding windows:
  - `satisfied`: Tracks customers who are already satisfied without using the X-minute window.
  - `win_of_make_satisfied`: Tracks customers who can be made satisfied by activating the X-minute window.
- Iterate through `customers` and `grumpy` arrays simultaneously using a single loop.
- Calculate `satisfied` and `win_of_make_satisfied` based on whether the current minute is grumpy or not.
- Slide the `win_of_make_satisfied` window by subtracting the customers who are no longer within the X-minute range.
- Update `max_make_satisfied` to keep track of the maximum customers that can be made satisfied within any X-minute window.
- Return the sum of `satisfied` and `max_make_satisfied`, which gives the maximum number of satisfied customers possible.

Complexity Analysis:
- Time Complexity: O(n), where n is the length of the `customers` and `grumpy` arrays.
  - The algorithm processes each element of the arrays once.
  - Sliding window operations are done in constant time.
- Space Complexity: O(1).
  - The algorithm uses a constant amount of extra space regardless of the input size.
  - Only a few variables are used to store intermediate results.
"""
