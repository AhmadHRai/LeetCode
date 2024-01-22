/**
 * @param {number[]} nums
 * @return {number[]}
 */

var findErrorNums = function (nums) {
  let dup = -1;
  let missing = -1;

  for (let i = 1; i <= nums.length; i++) {
    let count = nums.filter((num) => num === i).length;

    if (count == 2) {
      dup = i;
    } else if (count == 0) {
      missing = i;
    }
  }

  return [dup, missing];
};

/* 
Brute Force Approach

    Initialization:
        Initialize variables dup and missing to -1. These will be used to store the duplicate and missing numbers.

    Iteration through Possible Numbers:
        Iterate through numbers from 1 to the length of the input array (nums).

    Count Occurrences:
        For each number, count the occurrences in the input array nums by iterating through it.

    Identify Duplicate and Missing:
        If the count is 2, set dup to the current number, indicating a duplicate.
        If the count is 0, set missing to the current number, indicating a missing number.

    Return Result:
        After the iteration, return a vector containing the found duplicate (dup) and missing (missing) numbers.

Complexity

    Time complexity:
    O(n^2)

    Space complexity:
    O(1)

*/
