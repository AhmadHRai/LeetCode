// Define a public class that contains a function to find two numbers in an array that add up to a target value
class Solution {
    // Define a public function that takes an array of integers and a target value as parameters
    public int[] twoSum(int[] nums, int target) {
        // Loop through the array from the first element to the last element
        for (int i = 0; i < nums.length; i++) {
            // Loop through the array again from the first element to the last element
            for (int j = 0; j < nums.length; j++) {
                // If the indices are not the same and the sum of the elements at those indices is equal to the target value
                if (i != j && nums[i] + nums[j] == target) {
                    // Return an array of those indices
                    return new int[]{i, j};
                }
            }
        }
        // If no such pair of indices exists, return an array of -1 values
        return new int[]{-1, -1};
    }
}

/* 
The time complexity of this solution is O(n^2), where n is the length of the array. This is because we use two nested loops to iterate through the array, which results in n * n iterations in the worst case.

The space complexity of this solution is O(1), because we only use constant extra space for the variables i and j.
 */