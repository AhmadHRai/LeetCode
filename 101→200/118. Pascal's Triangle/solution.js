/**
 * @param {number} numRows
 * @return {number[][]}
 */
var generate = function (numRows) {
  if (numRows === 0) {
    return [];
  }

  var result = [[1]];

  for (var i = 1; i < numRows; i++) {
    var prevRow = result[i - 1];
    var newRow = [1];

    for (var j = 1; j < prevRow.length; j++) {
      var sum = prevRow[j - 1] + prevRow[j];
      newRow.push(sum);
    }

    newRow.push(1);
    result.push(newRow);
  }

  return result;
};

/**
 * Time Complexity: O(n^2)
 * Space Complexirt: O(n)
 */
