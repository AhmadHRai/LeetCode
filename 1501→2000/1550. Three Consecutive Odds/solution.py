class Solution:
    def isOdd(self, num: int) -> bool:
        return num % 2 != 0  # Check if a number is odd

    def threeConsecutiveOdds(self, arr: List[int]) -> bool:
        # Iterate through the array up to the third last element
        for i in range(len(arr)-2):
            # Check if current element and next two elements are odd
            if self.isOdd(arr[i]) and self.isOdd(arr[i+1]) and self.isOdd(arr[i+2]):
                return True  # Return True if three consecutive odds are found
        return False  # Return False if no such sequence is found

"""
Approach:
- Define a helper method `isOdd` to determine if a number is odd.
- Implement `threeConsecutiveOdds` method to iterate through the array `arr` and check for sequences of three consecutive odd numbers.
- Iterate through the array using a loop up to the third last element (`len(arr)-2`).
- Check at each index `i` if `arr[i]`, `arr[i+1]`, and `arr[i+2]` are odd using the `isOdd` method.
- Return `True` as soon as a sequence of three consecutive odd numbers is found.
- If no such sequence is found after iterating through the array, return `False`.

Complexity Analysis:
- Time Complexity: O(n), where n is the length of the array `arr`.
  - The function iterates through the array once (`len(arr)-2` iterations), checking three consecutive elements each time.
  
- Space Complexity: O(1).
  - The function uses only a constant amount of extra space regardless of the input size, as it only uses a few extra variables for iteration and checking.
"""