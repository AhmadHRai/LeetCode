class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum=0, maxLen=0; // Initialize sum and maxLen
        unordered_map<int, int> seen{{0, -1}}; // Initialize seen map with 0 and -1
        
        for(int i=0; i<nums.size(); i++){ // Iterate through the array
            sum += nums[i]==1 ? 1 : -1; // Update sum based on the current element
            if(seen.count(sum)) // If sum is already in the map
                maxLen = max(maxLen, i-seen[sum]); // Update maxLen if necessary
            else // If sum is not in the map
                seen[sum] = i; // Add sum to the map with the current index
        }
        return maxLen; // Return the maximum length of a contiguous subarray with an equal number of 0s and 1s
    }
};

/* 
Approach

    Initialization: The solution starts by initializing sum to 0 and maxLen to 0. sum keeps track of the cumulative sum of the array elements, treating 1s as +1 and 0s as -1. maxLen 
        stores the maximum length of a contiguous subarray with an equal number of 0s and 1s found so far.
    
    Hash Map: An unordered map seen is used to store the sum of elements encountered so far and the index at which each sum was first seen. It is initialized with a key-value pair of 0 
        and -1, indicating that the sum 0 has been seen at index -1 (before the start of the array).
    
    Iteration: The solution iterates through the array, updating sum by adding 1 for each 1 encountered and subtracting 1 for each 0. If sum is already in the map, it means that the 
        current subarray has an equal number of 0s and 1s, and maxLen is updated to the maximum of its current value and the difference between the current index and the index at which sum was first seen. If sum is not in the map, it is added with the current index as its value.
    
    Return Value: After iterating through the entire array, the function returns maxLen, which represents the maximum length of a contiguous subarray with an equal number of 0s and 1s.

Complexity Analysis

    Time Complexity: O(n), where n is the size of the input array. This is because each element in the array is processed once.
    Space Complexity: O(n), as in the worst case, the hash map seen could store n elements, each representing a unique sum encountered so far.

 */