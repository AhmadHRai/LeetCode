# Intuition

Hercy contributes money to the Leetcode bank based on a specific pattern. He starts with $1 on the first day and increases his contribution by $1 each subsequent day. Additionally, on each Monday, he increases the contribution by $1 more than the previous Monday. To calculate the total amount after a certain number of days, we need to follow this contribution pattern.

# Approach

1.  Calculate the number of complete weeks (week_count = n / 7).
2.  Calculate the total contribution from complete weeks using the arithmetic sum formula for each week: `((week_count * (week_count - 1)) / 2) * 7`.
3.  Calculate the total contribution from days beyond complete weeks using the arithmetic sum formula: `(week_count * 28)`.
4.  Calculate the contribution from the remaining days (less than a week) using the arithmetic sum formula for the remaining days: `((remaining_days * (remaining_days + 1)) / 2) + (week_count * remaining_days)`.
5.  Sum up the contributions calculated in steps 2, 3, and 4 to get the total amount.

# Complexity

- The time complexity is O(1) since the calculations are constant time.
- The space complexity is O(1) as well, as we are not using any additional data structures.
