/**
 * @param {number[]} nums
 * @return {number}
 */
var minOperations = function (nums) {
  let hash = [],
    maxCount = 0,
    win = [];
  for (let n of nums) hash[n] = 1;
  for (let n in hash) {
    while (n - win[0] >= nums.length) win.shift();
    maxCount = Math.max(win.push(n), maxCount);
  }
  return nums.length - maxCount;
};

/*
Approach

    Store all unique values from nums in an object hash.
    Create win = [] (sliding window) and cnt = 0 (max count of all values in the window).
    Iterate through hash in increasing order. For each value n:
        While n - win[0] >= nums.length, shift the lowest value out of win.
        Push n into win. If win.length > cnt, set cnt equal to it.
    Return nums.length - cnt.

Complexity

    Time complexity: O(n)
    Space complexity: O(n)

*/
