class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        // Priority queue to keep track of the smallest sums of subarrays
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mqueue;
        
        // Initialize the priority queue with sums of subarrays starting at each index
        for (int i = 0; i < n; i++) {
            mqueue.push({nums[i], i + 1}); // Push the initial sum (which is just nums[i]) and the ending index of the subarray
        }

        int ans = 0; // Variable to accumulate the sum of the required range
        int mod = 1e9 + 7; // Modulus value to handle large numbers and avoid overflow
        
        // Iterate to extract the smallest sums in the range from 'left' to 'right'
        for (int i = 1; i <= right; i++) {
            auto p = mqueue.top(); // Get the smallest sum from the priority queue
            mqueue.pop(); // Remove the smallest sum from the queue
            
            if (i >= left) {
                // If within the desired range, add the sum to the result
                ans = (ans + p.first) % mod;
            }
            
            if (p.second < n) {
                // If there are more elements in the current subarray, extend it and push the new sum back into the queue
                p.first += nums[p.second++]; // Update the sum and the end index of the subarray
                mqueue.push(p); // Push the updated sum and new end index back into the queue
            }
        }
        
        return ans; // Return the final accumulated sum
    }
};

/*
Approach:
- Use a priority queue to keep track of the smallest sums of subarrays.
- Initialize the priority queue with sums of all single-element subarrays.
- For each iteration up to the 'right' index:
  - Extract the smallest sum from the priority queue.
  - If the index is within the 'left' to 'right' range, add this sum to the result.
  - Extend the current subarray if possible and push the new sum back into the priority queue.
  
Complexity Analysis:
- Time Complexity: O(n log n), where n is the number of elements in `nums`. Each insertion and extraction operation from the priority queue takes O(log n) time, and there are at most n log n operations.
- Space Complexity: O(n), due to the space used by the priority queue which stores the sums of all possible subarrays.
*/
