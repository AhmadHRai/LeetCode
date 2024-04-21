/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maximumScore = function (nums, k) {
  let res = nums[k];
  let i = k;
  let j = k;
  let min_val = nums[k];

  while (i > 0 || j < nums.length - 1) {
    if (i === 0) {
      j += 1;
      min_val = Math.min(min_val, nums[j]);
    } else if (j === nums.length - 1) {
      i -= 1;
      min_val = Math.min(min_val, nums[i]);
    } else if (nums[i - 1] > nums[j + 1]) {
      i -= 1;
      min_val = Math.min(min_val, nums[i]);
    } else {
      j += 1;
      min_val = Math.min(min_val, nums[j]);
    }

    res = Math.max(res, min_val * (j - i + 1));
  }

  return res;
};

/* 
Approach : Two Pointers

    Initialize left = k and right = k.
    While left > 0 or right < nums.length - 1:
        If left == 0, then right += 1.
        Else if right == nums.length - 1, then left -= 1.
        Else if nums[left - 1] > nums[right + 1], then left -= 1.
        Else right += 1.
    Update the answer as max(answer, (right - left + 1) * min(nums[left], nums[left + 1], ..., nums[right])).
    Return answer.

Complexity

    Time complexity : O(n), where n is the length of nums.
    Space complexity : O(1)

*/
