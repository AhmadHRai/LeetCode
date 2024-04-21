/**
 * @param {number} rowIndex
 * @return {number[]}
 */
var getRow = function (rowIndex) {
  // initialize the number of rows to generate
  let numRows = rowIndex + 1;
  // initialize the array of rows with the first row [1]
  let rows = [[1]];

  // define a recursive function to append a new row based on the previous row
  const appendRow = (idx) => {
    // add 0 to both ends of the previous row
    let prevRow = [0, ...rows[idx - 1], 0];
    // initialize an empty array for the current row
    let row = [];

    // loop through the previous row and add adjacent elements
    for (let j = 0; j < prevRow.length - 1; j++) {
      row.push(prevRow[j] + prevRow[j + 1]);
    }
    // add the current row to the array of rows
    rows.push(row);

    // if there are still more rows to generate, call the function again with the next index
    if (rows.length < numRows) appendRow(idx + 1);
  };

  // if there are more than one row to generate, call the function with index 1
  if (numRows > 1) appendRow(1);

  // return the last row in the array of rows, which is the kth row of Pascal's triangle
  return rows[rows.length - 1];
};

/*
The time complexity of this code is O(k^2), where k is the input parameter rowIndex. This is because we need to generate k rows of Pascal’s triangle,
and each row takes O(k) time to construct. The space complexity of this code is O(k), since we only need to store one row of Pascal’s triangle at a time.
 */
