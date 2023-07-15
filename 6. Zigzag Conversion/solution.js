/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
var convert = function (s, numRows) {
  // If the number of rows is 1 or less than the length of the string, there is no need to convert
  if (numRows === 1 || s.length <= numRows) {
    return s;
  }

  // Create an array of strings to store the characters in each row
  const rows = [];
  for (let i = 0; i < numRows; i++) {
    rows.push("");
  }

  // Initialize the current row index to 0
  let currentRow = 0;
  // Use an array of booleans to indicate the direction of the traversal
  // The first element is true if the direction is down, false otherwise
  // The second element is true if the direction is up, false otherwise
  let direction = [true, false];

  // Use a for-of loop to iterate over the string
  for (let char of s) {
    // Append the current character to the current row string
    rows[currentRow] += char;

    // Use a ternary operator to assign the direction value based on the current row index
    // If the current row is the first row, the direction is down
    // If the current row is the last row, the direction is up
    // Otherwise, keep the same direction as before
    direction = currentRow === 0 ? [true, false] : currentRow === numRows - 1 ? [false, true] : direction;

    // Toggle the direction by using the logical NOT operator
    // If the direction is down, increment the current row index by 1
    // If the direction is up, decrement the current row index by 1
    currentRow += direction[0] ? 1 : -1;
  }

  // Join all the row strings together and return the result
  return rows.join("");
};

// Time complexity: O(n) where n is the length of the string
// The function iterates over each character in the string once and performs constant time operations

// Space complexity: O(n) where n is the length of the string
// The function creates an array of strings with a total length of n to store the characters in each row
