class Solution {
public:
    // Function to compute the XOR of all numbers in nums1 and nums2 based on their lengths
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        // Initialize XOR results for both arrays
        int xor1 = 0; // Result for nums1
        int xor2 = 0; // Result for nums2

        // Get lengths of both arrays
        int len1 = nums1.size(); // Length of nums1
        int len2 = nums2.size(); // Length of nums2

        // If nums2 length is odd, each element in nums1 appears odd times in final result
        if (len2 % 2 != 0) {
            for (int num : nums1) {
                xor1 ^= num; // XOR all elements in nums1
            }
        }

        // If nums1 length is odd, each element in nums2 appears odd times in final result
        if (len1 % 2 != 0) {
            for (int num : nums2) {
                xor2 ^= num; // XOR all elements in nums2
            }
        }

        // Return XOR of both results
        return xor1 ^ xor2; // Combine the results from both arrays
    }
};

/*
Approach Summary:
The function calculates the XOR of all numbers from two input arrays, `nums1` and `nums2`, but only includes elements based on the parity of their lengths. If the length of `nums2` is odd, all elements from `nums1` are included in the final XOR calculation. Similarly, if the length of `nums1` is odd, all elements from `nums2` are included. The final result is obtained by XORing the results from both arrays.

Complexity Analysis:
- Time Complexity: O(n + m), where n is the length of `nums1` and m is the length of `nums2`. The function iterates through each array at most once.
- Space Complexity: O(1), as only a fixed number of integer variables are used regardless of input size.
*/
