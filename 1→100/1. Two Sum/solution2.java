// Define a public class that contains a function to find two numbers in an array that add up to a target value
class Solution {
    // Define a public function that takes an array of integers and a target value as parameters
    public int[] twoSum(int[] nums, int target) {
        // Create a hash map to store the numbers and their indices in the array
        HashMap<Integer, Integer> map = new HashMap<>();
        // Loop through the array from the first element to the last element
        for (int i = 0; i < nums.length; i++) {
            // If the map contains the complement of the current element and the target value
            if (map.containsKey(target - nums[i])) {
                // Return an array of the index of the complement and the current index
                return new int[] { map.get(target - nums[i]), i };
            }
            // Otherwise, put the current element and its index into the map
            map.put(nums[i], i);
        }
        // If no such pair of indices exists, return an array of -1 values
        return new int[]{-1, -1};
    }
}

/* 
The time complexity of this solution is O(n), where n is the length of the array. This is because we use one loop to iterate through the array, and each lookup and insertion in the 
hash map takes O(1) time.

The space complexity of this solution is O(n), because we use a hash map to store n elements and their indices in the worst case.
 */