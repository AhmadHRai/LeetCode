# Comparison of Solutions for "Length of Last Word"

## Solution 1: Iterative Counting

- **Approach**: Trims the input string and iterates through it from right to left, counting the length of the last word.
- **Complexity**:
- **Time Complexity**: O(n), where n is the length of the input string.
- **Space Complexity**: O(1).
- **Efficiency**: Efficient in terms of time complexity, as it iterates through the string only once.

## Solution 2: Split and Length

- **Approach**: Trims the input string, splits it into an array of words, and returns the length of the last word.
- **Complexity**:
- **Time Complexity**: O(n), where n is the length of the input string.
- **Space Complexity**: O(n), where n is the number of words.
- **Efficiency**: Less efficient in terms of space complexity due to the creation of an array of words.

## Solution 3: Two-Pointer Approach

- **Approach**: Iterates through the input string from the end to the beginning, looking for the last non-space character, and then counts the number of characters until it encounters a space.
- **Complexity**:
- **Time Complexity**: O(n), where n is the length of the input string.
- **Space Complexity**: O(1).
- **Efficiency**: Efficient in terms of time complexity, as it iterates through the string only once. Also efficient in terms of space complexity, as it does not use additional data structures.

## Conclusion

- **Solution 1** is straightforward and efficient in terms of time complexity, making it a good choice for most cases.
- **Solution 2** is less efficient in terms of space complexity due to the creation of an array of words, making it less suitable for very long strings.
- **Solution 3** is the most efficient in terms of both time and space complexity, making it the best choice for scenarios where efficiency is a priority.
