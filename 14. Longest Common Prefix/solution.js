/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function (strs) {
  // use a ternary operator to check if the input array is empty or null
  let prefix = strs && strs.length ? strs[0] : "";

  // use a for-of loop to iterate over the rest of the strings in the array
  for (let str of strs) {
    // use a while loop to compare the prefix with each string
    while (str.indexOf(prefix) !== 0) {
      // reduce the prefix by one character from the end
      prefix = prefix.slice(0, -1);
      // if the prefix is empty, return it
      if (prefix.length === 0) {
        return "";
      }
    }
  }

  // return the final prefix
  return prefix;
};

/* 
The time complexity of this code is O(mn), where m is the length of the longest common prefix and n is the 
number of strings in the array, since it iterates over each character of each string at most once. The 
space complexity is O(1), since it uses a constant amount of extra space for the prefix variable.
*/
