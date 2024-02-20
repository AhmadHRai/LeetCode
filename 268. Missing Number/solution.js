/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function (nums) {
  let xor = 0,
    i = 0;
  for (i = 0; i < nums.length; i++) {
    xor = xor ^ i ^ nums[i];
  }
  return xor ^ i;

  /* 
  // normal solution for normal brains -- ignore for now
    let numSet = new Set(nums);

    for(let i=0; i<nums.length; i++){
        if(!numSet.has(i)){
            return i
        }
    }

    return nums.length;
  */
};

/* 
Link = https://leetcode.com/problems/missing-number/solutions/69791/4-line-simple-java-bit-manipulate-solution-with-explaination/
The basic idea is to use XOR operation. We all know that a^b^b =a, (not really, we don't) which means two xor operations with the same number will eliminate the number and reveal the original number.
In this solution, I apply XOR operation to both the index and value of the array. In a complete array with no missing numbers, the index and value should be perfectly corresponding( nums[index] = index), so in a missing array, what left finally is the missing number.

Complexity:
    The time complexity is O(n) and a space complexity is O(1). The time complexity is O(n) because the function iterates through the input array once, performing a constant time operation for each element. The space complexity is O(1) as the function uses a fixed amount of memory to store the variables xor and i, regardless of the size of the input array.
*/
