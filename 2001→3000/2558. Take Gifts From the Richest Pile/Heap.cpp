// Max-Heap Approach
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        // Create a max-heap from the 'gifts' array (using a priority_queue)
        priority_queue<int> giftsHeap(gifts.begin(), gifts.end());

        // Perform the operation 'k' times
        for (int i = 0; i < k; i++) {
            // Get the maximum element from the heap (top element)
            int maxElement = giftsHeap.top();
            giftsHeap.pop();

            // Insert the floor of the square root of the maximum element back into the heap
            giftsHeap.push(sqrt(maxElement));
        }

        // Accumulate the sum of the elements in the heap
        long long numberOfRemainingGifts = 0;
        while (!giftsHeap.empty()) {
            numberOfRemainingGifts += giftsHeap.top();
            giftsHeap.pop();
        }
        return numberOfRemainingGifts;
    }
};

/*
Approach:
1. The algorithm uses a **max-heap** (priority queue) to efficiently find and update the maximum element.
2. We create a max-heap from the `gifts` array, where the largest gift is always at the top.
3. For each of the `k` iterations, the largest element is removed (using `pop()`), its square root is calculated, and the result is pushed back into the heap (using `push()`).
4. After `k` iterations, the heap contains the modified gifts. The remaining elements in the heap are summed up to return the final result.

Complexity Analysis:
- **Time Complexity**: O(n + k * log n)
  - The heap initialization takes **O(n)** time, where `n` is the size of the `gifts` array.
  - In each of the `k` iterations, we perform two heap operations (pop and push), both of which take **O(log n)** time. So the operations contribute **O(k * log n)**.
  - Finally, summing the elements in the heap takes **O(n)** time, as we process all elements once.
  - Thus, the overall time complexity is **O(n + k * log n)**.
  
- **Space Complexity**: O(n)
  - The space complexity is **O(n)** because we store all `n` elements in the `priority_queue` at once, which requires **O(n)** additional space.

*/
