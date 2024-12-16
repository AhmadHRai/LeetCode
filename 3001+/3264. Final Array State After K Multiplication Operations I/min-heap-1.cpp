class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        const int n = nums.size(); 
        vector<pair<int, int>> heap(n);  // Create a heap to store the elements along with their original indices

        // Populate the heap with pairs of (value, index)
        for (int i = 0; i < n; i++) {
            heap[i] = {nums[i], i};  // Store value and index as a pair
        }

        // Build a min-heap based on the values (using 'greater' for min-heap)
        make_heap(heap.begin(), heap.end(), greater<>{});

        // Perform k iterations of modifying the smallest element in the heap
        for (int i = 0; i < k; i++) {
            pop_heap(heap.begin(), heap.end(), greater<>{});  // Remove the smallest element (min-heap root)
            heap.back().first *= multiplier;
            push_heap(heap.begin(), heap.end(), greater<>{});  // Reorganize the heap to maintain the heap property
        }
        
        // After k operations, restore the modified values back into the original array
        for (auto& [x, i] : heap)
            nums[i] = x;  // Use the original index to place the modified value back in nums

        return nums;
    }
};

/*
    Time Complexity: O(N+k⋅logN)
        The approach uses a heap (priority queue) to efficiently find and update the smallest element in the nums list. Initially, building the heap takes O(N) time.
        Each of the k iterations involves removing the smallest element from the heap and then reinserting the updated element. Both the removal and insertion operations take O(logN) time.
        Therefore, the total time complexity for k iterations is O(k⋅logN), resulting in a total time complexity of O(N+k⋅logN).

    Space Complexity: O(N)
        The approach uses a heap to store the elements of the nums list along with their indices. The heap requires additional space proportional to the number of elements in the nums list.
        Therefore, the space complexity is O(N).
*/
