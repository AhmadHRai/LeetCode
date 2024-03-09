class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        // Initialize two pointers at the beginning of both arrays
        int i = 0, j = 0;
        
        // Loop until one of the arrays is fully traversed
        while(i < nums1.size() && j < nums2.size() ){
            // If the current elements in both arrays are equal, return this element
            if(nums1[i] == nums2[j]) return nums1[i];
            
            // If the current element in nums1 is greater than the current element in nums2,
            // move the pointer in nums2 forward to find a match
            if(nums1[i] > nums2[j]) j++;
            
            // If the current element in nums1 is less than the current element in nums2,
            // move the pointer in nums1 forward to find a match
            else i++;
        }
        
        // If no common element is found, return -1
        return -1;
    }
};

/* 
Approach:

    The code initializes two pointers, i and j, at the beginning of the two input arrays nums1 and nums2.
    It then enters a loop that continues until one of the arrays is fully traversed.
    Inside the loop, it checks if the current elements in both arrays are equal. If they are, it returns this element as the smallest common value.
    If the current element in nums1 is greater than the current element in nums2, it moves the pointer j forward in nums2 to find a match.
    If the current element in nums1 is less than the current element in nums2, it moves the pointer i forward in nums1 to find a match.
    If the loop completes without finding a common element, it returns -1 to indicate that there is no common integer between the two arrays.

Complexity Analysis:

    Time Complexity: The time complexity is O(m + n), where m is the length of nums1 and n is the length of nums2. This is because each iteration of the while loop increments either i 
        or j, but never both at the same time, thus at most m + n iterations occur before the loop terminates.
    Space Complexity: The space complexity is O(1) because there are no additional data structures that grow with the input size. Only a fixed number of integer variables i, j, m, and 
        n are used regardless of the input size 3.


 */