public class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        // Initialize a HashSet to store the intersection
        Set<Integer> set = new HashSet<>();
        
        // Sort both arrays
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        
        // Initialize two pointers for nums1 and nums2
        int i = 0, j = 0;
        
        // Use two pointers to find common elements
        while (i < nums1.length && j < nums2.length) {
            if (nums1[i] < nums2[j]) {
                i++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                set.add(nums1[i]);
                i++;
                j++;
            }
        }
        
        // Convert the set to an array and return it
        int[] result = new int[set.size()];
        int k = 0;
        for (Integer num : set) {
            result[k++] = num;
        }
        return result;
    }
}

/* 
Approach Summary:

    This solution sorts both input arrays and then uses two pointers to find common elements.
    It iterates through both arrays simultaneously, moving the pointers forward based on the comparison of the current elements.
    When a common element is found, it is added to the set.
    Finally, it converts the set to an array and returns it.

Complexity:
    Time Complexity: O(nlogn + mlogm + min(n, m)), where n is the length of nums1 and m is the length of nums2. This accounts for the sorting of both arrays and the time to find the 
        intersection.
    Space Complexity: O(n + m), as it stores all elements from both arrays in a set.
 */