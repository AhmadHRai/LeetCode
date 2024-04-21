/**
 * @param {number[]} nums
 * @return {number[]}
 */
var rearrangeArray = function (nums) {
  const pos = [],
    neg = [];

  nums.forEach((num) => {
    if (num >= 0) {
      pos.push(num);
    } else {
      neg.push(num);
    }
  });

  let i = 0;
  while (2 * i < nums.length) {
    nums[2 * i] = pos[i];
    nums[2 * i + 1] = neg[i];
    i++;
  }
  return nums;
};
