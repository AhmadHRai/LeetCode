# **_Pre Count Approach_**

1.  It first calculates the count of '1's in each row and column and stores them in the rowCount and colCount vectors, respectively.
2.  Then, it iterates through each element of the matrix and checks if the element is '1' and if its corresponding row and column contain exactly one '1'. If so, it counts it as a "special" element.
3.  Finally, it returns the count of "special" elements found in the matrix.

# Complexity

- _Time complexity:_\
  O (m × n)

- _Space complexity:_\
  O (m + n)
