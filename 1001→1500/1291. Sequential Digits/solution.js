/**
 * @param {number} low
 * @param {number} high
 * @return {number[]}
 */
const sequentialDigits = (low, high) => {
  //  use sliding window

  const digits = "123456789"; // a constant string of digits
  const ans = []; // an array to store the answer

  const minLen = low.toString().length; // the minimum length of the sequential digits
  const maxLen = high.toString().length; // the maximum length of the sequential digits

  // loop through the possible lengths from minLen to maxLen
  for (let size = minLen; size <= maxLen; ++size) {
    // loop through the possible starting positions from 0 to digits.length - size
    for (let i = 0; i + size <= digits.length; ++i) {
      // get the substring of digits from i to i + size and parse it as a number
      const num = parseInt(digits.substring(i, i + size));

      // if the number is in the range [low, high], add it to the answer array
      if (num >= low && num <= high) {
        ans.push(num);
      }
    }
  }

  // return the answer array
  return ans;
};

/* 
Complexity:
Time complexity:
    The time complexity of this code is O(log(high) * log(high)), where log(high) is the number of digits in the high parameter.
    This is because we have two nested loops, each of which iterates up to log(high) times in the worst case.
    The inner loop iterates over the possible starting positions of the sequential digits, which is at most 9 - log(high).
    The outer loop iterates over the possible lengths of the sequential digits, which is at most log(high) - log(low) + 1.
    Therefore, the total number of iterations is bounded by (log(high) - log(low) + 1) * (9 - log(high)).
    This is equivalent to O(log(high) * log(high)) in the big O notation, as we ignore the constant factors and lower order terms.

Space complexity:
    The space complexity of this code is O(log(high)), where log(high) is the number of digits in the high parameter.
    This is because we use an array to store the answer, which can have at most log(high) elements in the worst case.
    The other variables are either constant or take O(1) space each, so they do not affect the overall space complexity.

*/
