class Solution {
public:
    int longestSubarray(vector<int>& A, int limit) {
        // Deques to maintain max and min values within the sliding window
        deque<int> maxd, mind;
        int i = 0, j; // Two pointers i (start of the window) and j (end of the window)

        for (j = 0; j < A.size(); ++j) {
            // Maintain the deque maxd with decreasing order of elements
            while (!maxd.empty() && A[j] > maxd.back()) maxd.pop_back();
            // Maintain the deque mind with increasing order of elements
            while (!mind.empty() && A[j] < mind.back()) mind.pop_back();
            // Add current element to both deques
            maxd.push_back(A[j]);
            mind.push_back(A[j]);

            // If the difference between the maximum and minimum element in the window exceeds 'limit'
            if (maxd.front() - mind.front() > limit) {
                // If the element going out of the window is the maximum, remove it from maxd
                if (maxd.front() == A[i]) maxd.pop_front();
                // If the element going out of the window is the minimum, remove it from mind
                if (mind.front() == A[i]) mind.pop_front();
                ++i; // Move the start of the window forward
            }
        }

        // Length of the longest subarray with maximum difference <= limit
        return j - i;
    }
};

/*
Approach:
- Use two deques (maxd and mind) to maintain the maximum and minimum values within the sliding window.
- Iterate through the array with two pointers, i (start of the window) and j (end of the window).
- For each element A[j], update the deques maxd and mind by maintaining elements in decreasing and increasing order respectively.
- Check if the difference between the maximum and minimum elements in the current window exceeds 'limit'.
- If it exceeds, move the start of the window forward (i++) until the difference is <= limit.
- Calculate and return the length of the longest subarray with maximum difference between its elements <= limit.

Complexity Analysis:
- Time Complexity: O(n), where n is the size of the array A.
  - Each element is processed and added/removed from the deques at most once.
  - Operations on deques (push_back, pop_back, pop_front) are O(1) on average.
- Space Complexity: O(n), due to the space used by the deques maxd and mind.
  - The space required is proportional to the size of the sliding window, which can grow up to the size of the array A.
*/  
