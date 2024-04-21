/*
Approach
    It uses a map mp to calculate the frequency of each number in nums.
    If any number occurs only once in nums, it's impossible to achieve the desired pattern, so the function returns -1.
    It calculates the number of moves needed to make all occurrences of each number a multiple of 3. If there are remaining occurrences (not divisible by 3), it adds one more move for each such occurrence.
    Finally, it returns the total number of moves needed to achieve the desired pattern.

Complexity
    Time complexity:
    O(n)

    Space complexity:
    O(n)
*/

/**
 * @param {number[]} nums
 * @return {number}
 */
var minOperations = function(nums) {
    const mp = new Map();
    
    for (let num of nums) {
        mp.set(num, (mp.get(num) || 0) + 1);
    }
    
    let count = 0;
    for (let [key, value] of mp.entries()) {
        let t = value;
        if (t === 1) return -1;
        count += Math.floor(t / 3);
        if (t % 3 !== 0) count++;
    }
    
    return count;
};
