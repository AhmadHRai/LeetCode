// One Liners
var transpose1 = function (matrix) {
  return matrix[0].map((_, colIndex) => matrix.map((row) => row[colIndex]));
};
/* 
    map calls a provided callback function once for each element in an array, in order, and constructs a new array from the results. callback is invoked only for 
    indexes of the array which have assigned values; it is not invoked for indexes which have been deleted or which have never been assigned values.

    callback is invoked with three arguments: the value of the element, the index of the element, and the Array object being traversed.
 */

function transpose2(matrix) {
  return matrix[0].map((col, c) => matrix.map((row, r) => matrix[r][c]));
}

// Functional approach using reduce
function transpose3(matrix) {
  return matrix.reduce((prev, next) => next.map((item, i) => (prev[i] || []).concat(next[i])), []);
}

// Traditional Approach
function transpose4(matrix) {
  const res = new Array(matrix[0].length).fill(null).map(() => new Array(matrix.length));

  for (let row = 0; row < matrix.length; row++) {
    for (let col = 0; col < matrix[0].length; col++) {
      res[col][row] = matrix[row][col];
    }
  }

  return res;
}
