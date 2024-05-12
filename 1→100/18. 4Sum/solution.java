class Solution {
    // The fourSum function is the entry point for solving the 4Sum problem.
    // It sorts the input array and then calls the kSum function with k=4 and the target sum.
    public List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums); // Sorting the array is crucial for the two-pointer technique to work.
        return kSum(nums, 0, 4, target); // Starting the recursive process to find 4 numbers that sum up to the target.
    }

    // The kSum function is a recursive function that finds k numbers in the array that sum up to the target.
    // It uses a divide-and-conquer approach, where it first tries to find 2 numbers that sum up to the target,
    // then recursively finds k-2 numbers that sum up to the target - the sum of the first 2 numbers.
    public List<List<Integer>> kSum(int[] nums, int start, int k, long target) {
        List<List<Integer>> res = new ArrayList<>(); // List to store the result.
        int len = nums.length;
        if(start >= len) {
            return res; // Base case: if the start index is out of bounds, return an empty list.
        }
        if(k==2){
            // Special case: when k=2, use the two-pointer technique to find 2 numbers that sum up to the target.
            int left = start, right = len-1;
            while(left < right){
                long sum = nums[left] + nums[right];
                if(sum == target){
                    // Found 2 numbers that sum up to the target.
                    List<Integer> path = new ArrayList<>();
                    path.add(nums[left]);
                    path.add(nums[right]);
                    res.add(path);
                    // Skip duplicates on both ends to avoid duplicates in the result.
                    while(left < right && nums[left] == nums[left+1]) left++;
                    while(left < right && nums[right] == nums[right-1]) right--;
                    left++;
                    right--;
                }else if(sum < target){
                    // If the sum is less than the target, move the left pointer to the right.
                    left++;
                }else{
                    // If the sum is greater than the target, move the right pointer to the left.
                    right--;
                }
            }
        } else {
            // General case: recursively find k numbers that sum up to the target.
            for(int i=start; i < len - (k-1); i++){
                // Skip duplicates to avoid duplicates in the result.
                if(i > start && nums[i] == nums[i-1]) continue;

                List<List<Integer>> temp = kSum(nums, i+1, k-1, target - nums[i]);
                // Add the current number to each of the k-1 numbers found by the recursive call.
                for(List<Integer> t : temp){
                    t.add(0, nums[i]);
                }
                res.addAll(temp);
            }
        }
        return res; // Return the result.
    }
}

/* 
Time Complexity Analysis:
    The time complexity of the fourSum function is O(n^3) because for each element, it potentially calls kSum with k=3, which has a time complexity of O(n^2).
    The kSum function with k=2 has a time complexity of O(n^2) due to the two-pointer technique used to find two numbers that sum up to the target.
    The space complexity is O(n) for the recursive call stack in the worst case, where n is the length of the input array.

Space Complexity Analysis:
    The space complexity is primarily determined by the recursive call stack, which in the worst case can go up to n levels deep, where n is the length of the input array. 
    This is because for each element, the function makes a recursive call.
    The space used by the result list res is O(n) in the worst case, as it stores all possible combinations of k numbers that sum up to the target.
 */