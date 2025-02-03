class Solution {
    public:
        int longestMonotonicSubarray(vector<int>& nums) {
            int current = 1; // Current length of the monotonic subarray
            int result = 1; // Maximum length found so far
    
            int modifier = 0; // Tracks the direction of the subarray (1 for increasing, -1 for decreasing, 0 for equal)
    
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i - 1] < nums[i]) {
                    // Increasing sequence
                    if (modifier > 0) { // If already increasing, extend the current subarray
                        current++;
                    } else { // If not increasing, start a new increasing subarray
                        current = 2;
                        modifier = 1;
                    }
                } else if (nums[i - 1] > nums[i]) {
                    // Decreasing sequence
                    if (modifier < 0) { // If already decreasing, extend the current subarray
                        current++;
                    } else { // If not decreasing, start a new decreasing subarray
                        current = 2;
                        modifier = -1;
                    }
                } else {
                    // Same value, reset the subarray
                    current = 1;
                    modifier = 0;
                }
                // Update the maximum length found so far
                result = max(result, current);
            }
    
            return result;
        }
    }
    /*
    Approach Summary:
    This solution iterates through the array, maintaining a current length of the monotonic subarray and updating it based on whether the sequence is increasing, decreasing, or constant. It keeps track of the maximum length encountered.
    
    Complexity Analysis:
    - Time Complexity: O(N), where N is the number of elements in the array, because each element is visited once.
    - Space Complexity: O(1), as only a constant amount of space is used.
    
    For naming the approach file, you could use something like:
    "Approach 1: Iterative Monotonic Check" or "Approach 1: Single Pass Monotonic Subarray".
    */
    