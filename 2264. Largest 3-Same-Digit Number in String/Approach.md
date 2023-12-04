# Example Explanation

Here's a step-by-step explanation using tables:

| **Step** | **Index** | **Current Substring** | **Unique Digit?** | **Result** |
| -------- | --------- | --------------------- | ----------------- | ---------- |
| 1        | 0         | "677"                 | No                | -1         |
| 2        | 1         | "777"                 | Yes (7)           | 7          |
| 3        | 2         | "771"                 | No                | 7          |
| 4        | 3         | "713"                 | No                | 7          |
| 5        | 4         | "133"                 | No                | 7          |
| 6        | 5         | "333"                 | Yes (3)           | 7          |
| 7        | 6         | "333"                 | Yes (3)           | 7          |
| 8        | 7         | "339"                 | No                | 7          |
| 9        | 8         | "399"                 | No                | 7          |

The final result is "777" as it is the largest good integer.

Explanation:

- We traverse through the string "6777133339" and identify substrings of length 3.
- For each substring, we check if it consists of only one unique digit.
- If yes, we update the `result` to be the maximum of the current digit and the existing `result`.
- After the loop, we check if a good integer was found (i.e., `result` is not -1).
- If yes, we construct the maximum good integer using the digit stored in `result`, which is "777".

# Intuition

To find the maximum good integer, we need to traverse through the given string `num` and identify all substrings of length 3 with only one unique digit. Among these substrings, we should choose the one with the maximum digit.

# Approach

1.  Initialize a variable `result` to store the maximum digit of the good integer found so far. Set it to -1 initially.
2.  Iterate through the string `num` from index 0 to `num.length() - 3`.
3.  Check if the substring of length 3 starting at the current index consists of only one unique digit. If yes, update the `result` to be the maximum of the current digit and the existing `result`.
4.  After the loop, if `result` is still -1, it means no good integer was found, so return an empty string.
5.  Otherwise, construct the maximum good integer using the digit stored in `result` and return it.

# Complexity

- The time complexity is O(n), where n is the length of the input string `num`.
- The space complexity is O(1) as we are using a constant amount of space for variables.
