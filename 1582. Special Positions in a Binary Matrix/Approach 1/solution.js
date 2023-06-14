function numSpecial(mat) {
  const m = mat.length; // Number of rows in the matrix
  const n = mat[0].length; // Number of columns in the matrix

  // Arrays to store counts of '1's in each row and column
  const rowCount = new Array(m).fill(0); // Initialize row count array with 0s
  const colCount = new Array(n).fill(0); // Initialize column count array with 0s

  // Counting '1's in each row and column
  for (let row = 0; row < m; row++) {
    for (let col = 0; col < n; col++) {
      if (mat[row][col] === 1) {
        rowCount[row]++; // Increment row count when '1' is encountered in the row
        colCount[col]++; // Increment column count when '1' is encountered in the column
      }
    }
  }

  let ans = 0; // Variable to store the count of "special" elements

  // Checking for "special" elements
  for (let row = 0; row < m; row++) {
    for (let col = 0; col < n; col++) {
      if (mat[row][col] === 1) {
        // If the element is '1'
        if (rowCount[row] === 1 && colCount[col] === 1) {
          // If the row and column containing this '1' have exactly one '1' (i.e., the element is "special")
          ans++; // Increment the count of "special" elements
        }
      }
    }
  }

  return ans; // Return the count of "special" elements
}
