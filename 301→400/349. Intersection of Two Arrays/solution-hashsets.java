public class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        // Initialize two HashSets to store unique elements from nums1 and the intersection
        Set<Integer> set = new HashSet<>();
        Set<Integer> intersect = new HashSet<>();
        
        // Add all elements from nums1 to the set
        for (int i = 0; i < nums1.length; i++) {
            set.add(nums1[i]);
        }
        
        // Iterate through nums2 and add elements to intersect if they are in set
        for (int i = 0; i < nums2.length; i++) {
            if (set.contains(nums2[i])) {
                intersect.add(nums2[i]);
            }
        }
        
        // Convert the intersect set to an array and return it
        int[] result = new int[intersect.size()];
        int i = 0;
        for (Integer num : intersect) {
            result[i++] = num;
        }
        return result;
    }
}

/* 
Approach Summary:

    This solution uses two HashSets: one to store unique elements from nums1 and another to store the intersection of nums1 and nums2.
    It iterates through nums1 and adds each element to the first set.
    Then, it iterates through nums2 and checks if each element is in the first set. If it is, the element is added to the intersection set.
    Finally, it converts the intersection set to an array and returns it.

Complexity:

    Time Complexity: O(n + m), where n is the length of nums1 and m is the length of nums2. This is because it iterates through both arrays once.
    Space Complexity: O(n + m), as it stores all elements from both arrays in sets.
 */