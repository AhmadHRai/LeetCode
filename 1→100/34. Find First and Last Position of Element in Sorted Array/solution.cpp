// Define a class that contains a function to search the first and last position of a target element in a sorted array
class Solution {
public:
    // Define a function that takes a vector of integers and a target element as parameters
    vector<int> searchRange(vector<int>& nums, int target) {
        // Initialize a vector of size 2 with -1 values to store the answer
        vector<int> ans(2, -1);
        // Initialize two variables to store the start and end indices of the array
        int start = 0, end = (int)nums.size() - 1;
        // Use a while loop to perform binary search on the array
        while(start <= end) {
            // Calculate the middle index by adding the start and end indices and dividing by 2
            int mid = start + (end-start)/2;
            // If the element at the middle index is smaller than the target, move the start index to the right of the middle index
            if(nums[mid] < target) start = mid+1;
            else {
                // If the element at the middle index is equal to the target, update the first position in the answer vector to the middle index
                if(nums[mid] == target) ans[0] = mid;
                // Move the end index to the left of the middle index
                end = mid-1;
            }
        }
        // Reset the start and end indices to perform another binary search on the array
        start = 0, end = (int)nums.size() - 1;
        // Use another while loop to perform binary search on the array
        while(start <= end) {
            // Calculate the middle index by adding the start and end indices and dividing by 2
            int mid = start + (end-start)/2;
            // If the element at the middle index is larger than the target, move the end index to the left of the middle index
            if(nums[mid] > target) end = mid-1;
            else {
                // If the element at the middle index is equal to the target, update the second position in the answer vector to the middle index
                if(nums[mid] == target) ans[1] = mid;
                // Move the start index to the right of the middle index
                start = mid+1;
            }
        }
        // Return the answer vector
        return ans;
    }
};
```

/*
The time complexity of this solution is O(log n), where n is the length of the array. This is because we use binary search twice on the array, which reduces the search space by 
half in each iteration.

The space complexity of this solution is O(1), because we only use constant extra space for the variables start, end, mid, and ans.
*/