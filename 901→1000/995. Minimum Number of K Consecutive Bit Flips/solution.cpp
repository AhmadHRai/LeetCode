class Solution {
public:
    int minKBitFlips(vector<int>& nums, int K) {
        int ans = 0;  // Initialize a counter to track the number of flips needed
        int size = nums.size();  // Get the size of the nums array
        queue<int> record;  // Initialize a queue to record the indices where flips occur

        // Traverse through the nums array
        for (int i = 0; i < size; i++) {
            // Determine the current pivot value based on whether the index is in an odd or even segment of flips
            int pivot = record.size() % 2 == 0 ? nums[i] : 1 - nums[i];

            // If the current element needs to be flipped (pivot == 0)
            if (pivot == 0) {
                ans++;  // Increment the flip count
                record.push(i + K - 1);  // Push the index where the flip will end (i + K - 1) to the queue
            }

            // Check if the front of the queue matches the current index, if so, pop it
            if (!record.empty() && i == record.front()) {
                record.pop();  // Remove the index from the front of the queue
            }
        }

        // If the queue is empty, return the total number of flips needed (ans)
        // Otherwise, return -1, indicating it's impossible to flip the array as required
        return record.empty() ? ans : -1;
    }
};

/*
Approach:

    Sliding Window with Queue:
        Use a queue (record) to track indices where flips are active. The queue stores indices that represent the end of the flip segment.
        Traverse through the nums array and determine the current state (pivot) based on whether the current index is within an odd or even segment of flips.
        For each element in nums, if it needs to be flipped (i.e., pivot == 0), increment the flip count (ans) and push the index where the flip ends (i + K - 1) into the queue.
        Remove indices from the front of the queue (record) that are no longer relevant (i.e., have passed their flip duration).
        After processing all elements, if the queue is empty, return ans, indicating the minimum flips required. If the queue is not empty, return -1, indicating it's impossible to flip the array as required.

Complexity Analysis:

    Time Complexity: O(n), where n is the size of the nums array.
        Each element in nums is processed at most twice (once when determining pivot and once when checking if it matches the front of record).
        Operations on the queue (push, pop, front) are all O(1).
    Space Complexity: O(K), where K is the size of the queue at its maximum.
        The queue record can hold up to K indices, corresponding to the maximum number of active flips at any point in time.
        Additional space usage is constant.
*/