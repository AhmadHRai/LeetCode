// Heap-based Approach using STL functions
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        // Convert the 'gifts' array into a max-heap using make_heap
        make_heap(begin(gifts), end(gifts));

        // Perform the operation 'k' times
        while(k--) {
            // Pop the largest element (max) from the heap
            pop_heap(begin(gifts), end(gifts));

            // Replace the largest element with the square root of itself
            gifts.back() = sqrt(gifts.back());

            // Re-adjust the heap after the modification
            push_heap(begin(gifts), end(gifts));
        }

        // Sum up all the remaining elements in the heap
        return accumulate(begin(gifts), end(gifts), 0LL);
    }
};

/*
Approach:
1. The algorithm uses the C++ Standard Library functions (`make_heap`, `pop_heap`, and `push_heap`) to manage the max-heap.
2. Initially, we convert the `gifts` array into a max-heap using `make_heap`.
3. For each of the `k` iterations:
   - The largest element (top element) is removed from the heap using `pop_heap`.
   - The square root of this element is calculated, and it replaces the removed element.
   - The modified element is reinserted into the heap using `push_heap`.
4. After completing the `k` operations, the heap contains the modified values. The sum of these values is computed and returned.

Complexity Analysis:
- **Time Complexity**: O(n + k * log n)
  - **O(n)** for the initial heap construction using `make_heap`.
  - For each of the `k` iterations:
    - **O(log n)** for the `pop_heap` operation.
    - **O(log n)** for the `push_heap` operation.
  - Finally, **O(n)** for summing the elements using `accumulate`.
  - Thus, the overall time complexity is **O(n + k * log n)**.
  
- **Space Complexity**: O(n)
  - The space complexity is **O(n)** as the algorithm modifies the `gifts` array in-place using heap operations, requiring no additional storage beyond the input array.

*/
