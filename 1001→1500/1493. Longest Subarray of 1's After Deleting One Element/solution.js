/**
 * @param {number[]} arr
 * @return {number}
 */
var longestSubarray = function(arr) {
    let max = 0;
    let deleted = 0;
    let l = 0;
    let r = 0; 

    while(r < arr.length) {
        if(arr[r] === 1 || deleted === 0) {
            if(arr[r] === 0) deleted = 1;
            max = Math.max(max, r - l + 1 - deleted);
            r++;
        } else {
            if(arr[l] === 0) deleted = 0;
            l++;
        }
    }

    return max === arr.length ? max - 1 : max;
};