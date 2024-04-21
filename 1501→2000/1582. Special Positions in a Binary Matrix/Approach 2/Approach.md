# **Brute Force Approach**

1.  It iterates through each element of the matrix, checking if it equals 1.
2.  For each element that equals 1, it checks the entire row and column to see if there are any other '1's apart from the current row or column.
3.  If the element has no other '1's in its row and column except for itself, it is considered "special," and the counter 'ans' is incremented.
4.  Finally, the function returns the count of "special" elements found in the matrix.

# Complexity

- _Time complexity:_\
  O ( m . n . (m + n))

- _Space complexity:_\
  O(1)
