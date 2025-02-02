class Solution {
    public:
        // Checks if the array can be rotated to form a non-decreasing sequence
        bool check(vector<int>& nums) {
            int n = nums.size();
            int count = 1;
    
            // Base case: Single-element array is always non-decreasing
            if (n == 1) return true;
    
            // Check all rotations of the array
            for (int i = 1; i < n * 2; i++) {
                // Compare adjacent elements in the rotated array
                if (nums[(i - 1) % n] <= nums[i % n]) {
                    // If elements are in non-decreasing order, increment the count
                    count++;
                } else {
                    // Reset count if non-decreasing order is broken
                    count = 1;
                }
                
                // If a rotation forms a non-decreasing sequence of length n, return true
                if (count == n) return true;
            }
            // If no rotation forms a non-decreasing sequence, return false
            return false;
        }
    }
    /*
    Approach Summary:
    This solution checks all rotations of the input array to see if any rotation can form a non-decreasing sequence. It iterates through each rotation, comparing adjacent elements and resetting a counter whenever the sequence is broken.
    
    Complexity Analysis:
    - Time Complexity: O(N), where N is the number of elements in the array, because each element is visited twice (once in each rotation).
    - Space Complexity: O(1), as only a constant amount of space is used.
    */
    