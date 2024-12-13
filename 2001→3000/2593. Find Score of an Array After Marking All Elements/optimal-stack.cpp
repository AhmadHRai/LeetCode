class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score = 0; // Initialize the score to 0
        int n = nums.size();  // Get the size of the input array
        deque<int> q;  // Deque (double-ended queue) to process elements in a controlled order

        // Traverse through the array
        for (int i = 0; i < n; i++) {
            // If queue is not empty and the current number is greater than or equal to the last in queue
            if (!q.empty() && nums[i] >= q.back()) {
                bool skip = false;
                // Process the elements in the queue
                while (!q.empty()) {
                    int add = q.back();  // Get the last element from the deque
                    q.pop_back();  // Remove the element from the deque
                    if (!skip) {
                        score += add;  // Add the value to score (only if we aren't skipping it)
                    }
                    skip = !skip;  // Toggle the skip flag (this alternates between skipping and adding)
                }
                continue;  // Continue to the next element
            }

            // Add current element to the queue
            q.push_back(nums[i]);
        }

        // Final processing of remaining elements in the queue
        bool skip = false;
        while (!q.empty()) {
            int add = q.back();  // Get the last element
            q.pop_back();  // Remove it from the deque
            if (!skip) {
                score += add;  // Add value to score if not skipped
            }
            skip = !skip;  // Toggle skip
        }

        return score;  // Return the computed score
    }
};

/* 
Approach Summary:

    This approach uses a stack-like deque to store the elements and processes them based on their relative order. It alternates adding and skipping elements in the queue while 
    maintaining the order of processing.
    
Time Complexity:

    Time Complexity: O(n), where n is the length of the array. Each element is processed exactly once.
    Space Complexity: O(n) due to the deque used to store the elements.
*/
