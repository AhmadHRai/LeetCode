public class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        // Initialize a HashSet to store the intersection
        Set<Integer> set = new HashSet<>();
        
        // Sort nums2 for binary search
        Arrays.sort(nums2);
        
        // Iterate through nums1 and use binary search on nums2
        for (Integer num : nums1) {
            if (binarySearch(nums2, num)) {
                set.add(num);
            }
        }
        
        // Convert the set to an array and return it
        int[] result = new int[set.size()];
        int i = 0;
        for (Integer num : set) {
            result[i++] = num;
        }
        return result;
    }
    
    public boolean binarySearch(int[] nums, int target) {
        int low = 0;
        int high = nums.length - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return true;
            }
            if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return false;
    }
}

/* 
Approach Summary:

    This solution sorts nums2 and then uses binary search to find common elements in nums1.
    It iterates through nums1 and for each element, it performs a binary search on nums2.
    If the binary search finds the element, it is added to the set.
    Finally, it converts the set to an array and returns it.

Complexity:

    Time Complexity: O(nlogm + mlogm), where n is the length of nums1 and m is the length of nums2. This accounts for the sorting of nums2 and the binary search for each element in 
        nums1.
    Space Complexity: O(n + m), as it stores all elements from both arrays in a set.
 */