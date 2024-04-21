// Define a function that takes an array of numbers and a target value as parameters
var twoSum = function(nums, target) {
    // Create a map to store the numbers and their indices in the array
    let map = new Map();
    
    // Loop through the array from the first element to the last element
    for(let i = 0; i < nums.length; i ++) {
        // If the map contains the complement of the current element and the target value
        if(map.has(target - nums[i])) {
            // Return an array of the index of the complement and the current index
            return [map.get(target - nums[i]), i];
        } else {
            // Otherwise, put the current element and its index into the map
            map.set(nums[i], i);
        }
    }
    // If no such pair of indices exists, return an empty array
	return [];
};

/* The time complexity of this solution is O(n), where n is the length of the array. This is because we use one loop to iterate through the array, and each lookup and insertion in 
the map takes O(1) time.
The space complexity of this solution is O(n), because we use a map to store n elements and their indices in the worst case.
 */