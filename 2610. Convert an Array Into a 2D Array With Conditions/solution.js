/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var findMatrix = function (nums) {
  let newArray = [];
  // frequency vector is initialized with a size of nums.size() + 1 to accommodate indexing from 0 to nums.size().
  let frequencyArray = new Array(nums.length + 1).fill(0);

  for (let number of nums) {
    // If the frequency of integer number (frequency[number]) is equal to or greater than the size of ans, it means we need to add a new empty subarray to the result result.
    if (frequencyArray[number] >= newArray.length) {
      newArray.push([]);
    }

    // The integer number is then added to the subarray in ans corresponding to its current frequency (frequency[number]).
    newArray[frequencyArray[number]].push(number);

    // Finally, the frequency of integer number is incremented.
    frequencyArray[number]++;
  }

  return newArray;
};

/*
Complexity

    Time complexity:
    O(n)

    Space complexity:
    O(n)
*/
