// 14/05/2023

/**
 * @param {string} boxes
 * @return {number[]}
 */
var minOperations = function (boxes) {
  const n = boxes.length;
  const ans = new Array(n).fill(0); // initialize answer array with 0s

  // calculate answer for each box i
  for (let i = 0; i < n; i++) {
    let ops = 0; // initialize number of operations needed to move balls to box i
    for (let j = 0; j < n; j++) {
      if (boxes[j] == "1") {
        // if box j has a ball
        ops += Math.abs(i - j); // add number of operations needed to move ball from box j to box i
      }
    }
    ans[i] = ops; // store answer for box i
  }

  return ans;
};
