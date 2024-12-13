class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();  // Get the size of the input array
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;  // Min-heap to store (value, index) pairs

        // Build the min-heap with (value, index) pairs
        for (int i = 0; i < n; i++) {
            minHeap.push({nums[i], i});  // Push each element into the heap
        }

        long long score = 0;  // Initialize score to 0

        // Process elements in min-heap
        while (!minHeap.empty()) {
            auto curr = minHeap.top();  // Get the top element (smallest value)
            minHeap.pop();  // Remove it from the heap
            int num = curr.first;  // Get the value of the current element
            int idx = curr.second;  // Get the index of the current element

            if (nums[idx] != -1) {  // Process only if the element is not already marked
                score += num;  // Add the element's value to score
                nums[idx] = -1;  // Mark the current element
                if (idx > 0 && nums[idx - 1] != -1) {
                    nums[idx - 1] = -1;  // Mark the left neighbor if it exists
                }
                if (idx < n - 1 && nums[idx + 1] != -1) {
                    nums[idx + 1] = -1;  // Mark the right neighbor if it exists
                }
            }
        }

        return score;  // Return the computed score
    }
};

/* 
Approach Summary:

    This solution uses a min-heap to keep the elements sorted by value, allowing for efficient retrieval of the smallest unmarked element. After processing each element, the element and its neighbors are marked, and the heap is updated accordingly.

Time Complexity:

    Time Complexity: O(n log n), where n is the size of the array. Building the heap takes O(n log n) and extracting elements from the heap is also O(log n).
    Space Complexity: O(n) due to the heap storing the elements.
*/