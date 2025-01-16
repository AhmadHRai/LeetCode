class Solution {
public:
    // Function to compute the XOR of all numbers in nums1 and nums2 based on their frequencies
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        // Get lengths of arrays
        int len1 = nums1.size(); // Length of nums1
        int len2 = nums2.size(); // Length of nums2

        // Map to store frequency of each number
        unordered_map<int, long> freq; // Map to hold the frequency of each number

        // Add frequencies for nums1 elements
        // Each element appears len2 times in final result
        for (int num : nums1) {
            freq[num] += len2; // Increment frequency by the length of nums2
        }

        // Add frequencies for nums2 elements
        // Each element appears len1 times in final result
        for (int num : nums2) {
            freq[num] += len1; // Increment frequency by the length of nums1
        }

        // XOR numbers that appear an odd number of times
        int ans = 0; // Variable to accumulate the result
        for (auto& [num, count] : freq) {
            if (count % 2 == 1) { // Check if the count is odd
                ans ^= num; // XOR with the number if it appears an odd number of times
            }
        }

        return ans; // Return the final XOR result
    }
};

/*
Approach Summary:
The function calculates the XOR of all numbers from two input arrays, `nums1` and `nums2`, based on how many times each number would appear in the final result. Each element in `nums1` contributes to the final result as many times as there are elements in `nums2`, and vice versa. The function uses a frequency map to track how many times each number appears. Finally, it computes the XOR of all numbers that appear an odd number of times.

Complexity Analysis:
- Time Complexity: O(n + m), where n is the length of `nums1` and m is the length of `nums2`. The function iterates through both arrays to build the frequency map and then iterates through the map to compute the final XOR.
- Space Complexity: O(k), where k is the number of unique numbers in both arrays. This is due to storing frequencies in a hash map.
*/
