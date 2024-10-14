#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    static long long maxKelements(vector<int>& nums, int k) {
        // Initialize a max-heap with all elements in nums
        priority_queue<int> pq(nums.begin(), nums.end());
        
        long long score = 0;  // Initialize score to accumulate the results
        
        // Iterate k times to add the top elements to the score
        for (int i = 0; i < k; i++) {
            int x = pq.top();   // Get the maximum element from the heap
            score += x;         // Add this element to the score
            
            // Early termination if the maximum element is 1
            if (x == 1) {
                score += (k - 1 - i);  // Add remaining iterations to score
                break;
            }
            
            pq.pop();           // Remove the maximum element
            pq.push((x + 2) / 3);  // Push the next transformed value to heap
        }
        
        return score;  // Return the accumulated score
    }
};

// Faster I/O setup
auto init = []() { 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

/*
Approach:
1. Initialize a Max-Heap:
   - Use a max-heap (priority_queue in descending order) initialized with all elements from `nums`.
   - This allows efficient access to the largest element for each of `k` iterations.

2. Accumulate the Score for k Elements:
   - For each iteration, retrieve the maximum element `x` from the heap, add it to `score`, then transform `x` as `(x + 2) / 3` to push back into the heap.
   - This transformation represents diminishing returns as `x` decreases gradually with each addition to `score`.
   - If `x` is `1`, perform early termination by adding the remaining iterations to `score`, as further transformations would only yield `1`.

3. Return the Accumulated Score:
   - After `k` iterations (or early termination), return the total score accumulated from the largest elements.

Complexity Analysis:
- Time Complexity: O(k * log n), where `n` is the number of elements in `nums` and `k` is the number of iterations. Each heap operation (push/pop) is O(log n).
- Space Complexity: O(n), for storing the elements in the max-heap.
*/
