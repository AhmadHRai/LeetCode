class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();

        while (k--) {
            // Find the index of the smallest element in the array
            int minIndex = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] < nums[minIndex]) {
                    minIndex = i;
                }
            }

            // Multiply the smallest element by the multiplier
            nums[minIndex] *= multiplier;
        }

        return nums;
    }
};

/*
Complexity: 
    Time Complexity: O(k * n)

        The inner loop runs in O(n), and the outer loop runs k times, so the total complexity is O(k * n).

    Space Complexity: O(1)

        We use a constant amount of extra space, since the array is modified in place.
 */