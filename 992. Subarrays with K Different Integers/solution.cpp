class Solution {
public:
    int subArray(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> map; // create an unordered map to store the count of each number in the current subarray
        int count = 0, start = 0, end = 0; // initialize variables for count of valid subarrays, start and end index of subarray
        while (end < n) { // loop through the array from the start to end index
            map[nums[end]]++; // add the current element to the map and increment its count
            while (map.size() > k) { // if the number of distinct elements in the map is greater than k, move the start index and remove elements from the map
                map[nums[start]]--; // decrement the count of the element at the start index
                if (map[nums[start]] == 0) { // if the count of the element at the start index becomes 0, remove it from the map
                    map.erase(nums[start]);
                }
                start++; // increment the start index to move the window
            }
            count += end - start + 1; // add the count of valid subarrays for the current subarray to the total count
            end++; // increment the end index to move the window
        }
        return count; // return the total count of valid subarrays
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // return the count of subarrays with exactly k distinct elements minus the count of subarrays with less than k distinct elements
        return subArray(nums, k) - subArray(nums, k - 1);
    }
};

/* 
Approach Summary

    The algorithm counts the number of subarrays with exactly `k` distinct elements. It does this by maintaining a sliding window of 
    elements and using a hash map to keep track of the count of each number in the current subarray. If the number of distinct elements 
    in the map exceeds `k`, the start index of the window is moved to the right, and elements are removed from the map until the number 
    of distinct elements is less than or equal to `k`. The count of all valid subarrays is maintained and returned at the end.

    The algorithm starts by initializing variables for the size of the array, the hash map, and the count of valid subarrays, as well as 
    the start and end indices of the subarray. It then enters a loop that continues until the end of the array is reached. Inside the 
    loop, the current element is added to the map and its count is incremented. A while loop checks if the number of distinct elements 
    in the map is greater than `k`. If it is, the start index is moved to the right, and elements are removed from the map until the 
    number of distinct elements is less than or equal to `k`. After each iteration of the outer loop, the count of all valid subarrays 
    is incremented by the difference between the end and start indices plus 1.

Time Complexity Analysis

    The time complexity of this algorithm is O(n), where n is the length of the input array `nums`. This is because each element in the 
    array is visited at most twice: once by the end pointer and once by the start pointer.

Space Complexity Analysis

    The space complexity is O(k), as the algorithm uses a hash map to store the count of each number in the current subarray, and the 
    size of the map is at most `k`.

 */