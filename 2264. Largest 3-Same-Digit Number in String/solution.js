/**
 * @param {string} num
 * @return {string}
 */
var largestGoodInteger = function (num) {
  let result = -1;
  for (let i = 0; i + 2 < num.length; i++) {
    if (num[i] === num[i + 1] && num[i] === num[i + 2]) {
      result = Math.max(result, parseInt(num[i]));
    }
  }
  return result === -1 ? "" : String(result).repeat(3);
};
