#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

class Solution {
public:
    std::vector<int> smallestRange(std::vector<std::vector<int>>& nums) {
        // Min-Heap: stores (value, list index, element index) for each element across lists
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, std::greater<std::vector<int>>> minHeap;
        int curMax = std::numeric_limits<int>::min();  // Track the current maximum value across the lists

        // Initialize the heap with the first element from each list
        for (int i = 0; i < nums.size(); i++) {
            minHeap.push({nums[i][0], i, 0});          // Push (value, list index, element index) to heap
            curMax = std::max(curMax, nums[i][0]);     // Update current maximum
        }

        // Track the smallest range found so far
        std::vector<int> smallRange = {0, std::numeric_limits<int>::max()};

        // Continue until the heap is empty
        while (!minHeap.empty()) {
            // Get the minimum element from the heap
            std::vector<int> curr = minHeap.top();
            minHeap.pop();
            int curMin = curr[0], listIdx = curr[1], elemIdx = curr[2];

            // Update the smallest range if a new smaller range is found
            if ((curMax - curMin < smallRange[1] - smallRange[0]) ||
                (curMax - curMin == smallRange[1] - smallRange[0] && curMin < smallRange[0])) {
                smallRange[0] = curMin;
                smallRange[1] = curMax;
            }

            // Move to the next element in the current list
            if (elemIdx + 1 < nums[listIdx].size()) {
                int nextVal = nums[listIdx][elemIdx + 1];
                minHeap.push({nextVal, listIdx, elemIdx + 1});  // Push next element in the same list to heap
                curMax = std::max(curMax, nextVal);              // Update current maximum with the next element
            } else {
                // Stop if any list is exhausted, as we cannot cover all lists
                break;
            }
        }

        return smallRange;  // Return the smallest range found
    }
};

/*
Approach:
1. Extract the First Element from Each List:
   - Initialize a min-heap to store the first element of each list as (value, list index, element index). Track the maximum value encountered so far across these first elements.

2. Traverse to Find the Smallest Range:
   - Continue until we can no longer cover all lists (i.e., until a list is exhausted).
   - Extract the minimum element from the min-heap to get the current range minimum. Calculate the range as the difference between the current maximum and this minimum.
   - Update `smallRange` if a smaller or lexicographically smaller range is found.
   - Push the next element from the same list into the heap and update the current maximum if needed.

3. Stop When a List is Exhausted:
   - If any list runs out of elements, break out of the loop since we can no longer cover all lists.

Complexity Analysis:
- Time Complexity: O(n * log k), where `n` is the total number of elements in `nums` and `k` is the number of lists. Each insertion and extraction from the heap takes O(log k).
- Space Complexity: O(k), where `k` is the number of lists, as the heap stores one element from each list at a time.
*/
