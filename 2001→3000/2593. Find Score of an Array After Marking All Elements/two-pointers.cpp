class Solution {
public:
    long long findScore(vector<int>& nums) {
        const int n = nums.size();  // Get the size of the input array
        long long sum = 0;  // Initialize sum (score) to 0

        // Step through the array with a two-pointer strategy
        for (int l, r = 0; r < n; r += 2) {  // Skip every other element (r increments by 2)
            l = r;  // Start at the current index

            // Move the right pointer to find a local minimum
            while (r + 1 < n && nums[r] > nums[r + 1]) {
                r++;  // Move right pointer to the smaller value
            }

            // Add all values from the local minimum to the left pointer
            for (int i = r; i >= l; i -= 2) {
                sum += nums[i];  // Add each element to sum (score)
            }
        }

        return sum;  // Return the computed score
    }
};

/* 
Approach Summary:

    This approach uses a two-pointer strategy to find local minima and maxima. It processes the elements in pairs, skipping the alternate elements after marking the local minimum values.
    
Time Complexity:

    Time Complexity: O(n), as each element is processed a constant number of times (twice in the worst case).
    Space Complexity: O(1), since the solution uses only a few variables.
 */