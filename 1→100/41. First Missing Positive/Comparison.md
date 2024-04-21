## Comparison of Solutions for "41. First Missing Positive"

### Solution 1: Marking and Checking

- **Approach**: Marks all non-positive numbers as `n+1` to ensure they are not considered as missing positive numbers. Then, it iterates through the array, marking the index of each number as negative if the number is within the range `[1, n]`. Finally, it finds the first index that is not marked as negative, which corresponds to the first missing positive number.
- **Complexity**:
- **Time Complexity**: O(n), where n is the number of elements in the array. This is because each element is visited at most twice.
- **Space Complexity**: O(1), as the solution uses a constant amount of space to store the pointers and does not depend on the size of the input array.

### Solution 2: Swapping and Checking

- **Approach**: Uses a swapping technique to place each number at its correct index if it is within the range `[1, n]`. It iterates through the array, swapping each number with the number at its correct index if it is not already there. Finally, it finds the first index that does not match its value plus one, which corresponds to the first missing positive number.
- **Complexity**:
- **Time Complexity**: O(n), where n is the number of elements in the array. This is because each element is visited at most twice.
- **Space Complexity**: O(1), as the solution uses a constant amount of space to store the pointers and does not depend on the size of the input array.

### Comparison

- **Solution 1** is straightforward and easy to understand but requires two passes through the array.
- **Solution 2** is more efficient in terms of the number of iterations but might be slightly harder to understand due to the swapping logic.

Both solutions have a time complexity of O(n) and a space complexity of O(1), making them efficient for solving the problem.
