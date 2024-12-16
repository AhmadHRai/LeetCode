class Solution {
public:
    static vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        const int n = nums.size();

        // Populate the priority queue with pairs (value, index)
        for (int i = 0; i < n; i++) {
            pq.emplace(nums[i], i);
        }

        // Perform k operations on the smallest element in the priority queue
        for (int i = 0; i < k; i++) {
            auto [x, j] = pq.top();  // Get the smallest element (value, index)
            pq.pop();
            pq.emplace(multiplier * x, j);  // Update the value and push it back into the priority queue
        }

        // Restore the updated values back to nums array
        while (!pq.empty()) {
            auto [x, i] = pq.top();  // Get the modified value and its original index
            pq.pop();
            nums[i] = x;  // Update the value at the original index in nums
        }

        return nums;
    }
};

/*
    Time Complexity: O(N + k * log N)
        - Building the priority queue: O(N), where N is the size of the input array `nums`.
        - Each of the k operations involves popping and pushing an element from the priority queue, which takes O(log N) time.
        - Therefore, the total time complexity for k operations is O(k * log N).
        - Restoring the updated values back into the `nums` array takes O(N) time since we iterate through all the elements of the priority queue once.

    Space Complexity: O(N)
        - The space complexity is dominated by the priority queue that stores the pairs (value, index) for each element in the `nums` array.
        - Therefore, the space complexity is O(N), where N is the size of the `nums` array.
*/
