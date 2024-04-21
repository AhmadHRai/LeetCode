/**
 * @param {number[]} nums
 * @return {number[]}
 */
var majorityElement = function(nums) {
    // The idea is to use a variant of the Boyer-Moore majority vote algorithm
    // We need to find at most two candidates that have the potential to appear more than n/3 times
    // We use two variables to store the candidates and two counters to keep track of their frequencies
    // We iterate over the array and update the candidates and counters accordingly
    // Then we verify if the candidates actually appear more than n/3 times by counting their occurrences again

    let n = nums.length; // get the length of the array
    let candidate1 = null; // initialize the first candidate to null
    let candidate2 = null; // initialize the second candidate to null
    let count1 = 0; // initialize the first counter to zero
    let count2 = 0; // initialize the second counter to zero

    for (let num of nums) { // loop over the array
        if (num === candidate1) { // if the current element is equal to the first candidate
            count1++; // increment the first counter
        } else if (num === candidate2) { // else if the current element is equal to the second candidate
            count2++; // increment the second counter
        } else if (count1 === 0) { // else if the first counter is zero
            candidate1 = num; // update the first candidate to the current element
            count1++; // increment the first counter
        } else if (count2 === 0) { // else if the second counter is zero
            candidate2 = num; // update the second candidate to the current element
            count2++; // increment the second counter
        } else { // else both counters are non-zero and both candidates are different from the current element
            count1--; // decrement the first counter
            count2--; // decrement the second counter
        }
    }

    let result = []; // initialize an empty array to store the result

    count1 = 0; // reset the first counter to zero
    count2 = 0; // reset the second counter to zero

    for (let num of nums) { // loop over the array again
        if (num === candidate1) { // if the current element is equal to the first candidate
            count1++; // increment the first counter
        } else if (num === candidate2) { // else if the current element is equal to the second candidate
            count2++; // increment the second counter
        }
    }

    if (count1 > Math.floor(n / 3)) { // if the first candidate appears more than n/3 times
        result.push(candidate1); // add it to the result array
    }

    if (count2 > Math.floor(n / 3)) { // if the second candidate appears more than n/3 times
        result.push(candidate2); // add it to the result array
    }

    return result; // return the result array
};

/* 
The solution is in linear time because it only iterates over the array twice, once to find the candidates and once to verify them. Each iteration takes O(n) time, where n is the 
length of the array. Therefore, the total time complexity is O(n) + O(n) = O(n).
The solution is in O(1) space because it only uses constant extra space, regardless of the size of the input array. It only uses four variables to store the candidates and 
counters, and an array to store the result. The size of the result array is at most two, since there can be at most two elements that appear more than n/3 times. Therefore, the 
total space complexity is O(4 + 2) = O(1).
*/