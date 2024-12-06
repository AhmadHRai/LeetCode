class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        // Create a vector to mark allowed numbers, initialize all numbers as allowed (1)
        vector<int> allowed(10001, 1);
        
        // Mark banned numbers as not allowed (0)
        for (int b: banned) allowed[b] = 0;
        
        int ans = 0; // Variable to track the count of valid numbers added

        // Iterate through the range 1 to n and pick numbers that are allowed and fit within maxSum
        for (int i = 1; i <= n; ++i) {
            // Check if the number is allowed and if it fits within the remaining maxSum
            if (allowed[i] && maxSum >= i) {
                ++ans; // Increment the count of valid numbers
                maxSum -= i; // Deduct the current number from maxSum
                allowed[i] = 0; // Mark the number as used (no longer available)
            }
        }

        return ans; // Return the total count of valid numbers that fit within the maxSum
    }
};

/*
Approach:
1. Initialize a vector `allowed` of size 10001, where each element is initially set to 1, indicating that all numbers are allowed.
2. For each number in the banned list, set the corresponding index in the `allowed` vector to 0, marking it as not allowed.
3. Initialize a variable `ans` to count how many valid numbers can be added to the sum.
4. Iterate through the numbers from 1 to `n`:
   - If the number is allowed and can fit into the remaining `maxSum`, increment `ans`, subtract the number from `maxSum`, and mark that number as used.
5. Return the final count of valid numbers (`ans`).

This solution uses a simple greedy approach. It iterates through all numbers from 1 to `n`, checking whether the number is allowed and whether it fits within the remaining `maxSum`. If so, it adds it to the count and deducts it from the `maxSum`.

Complexity Analysis:
- Time Complexity: O(n + m), where `n` is the range of numbers (from 1 to `n`), and `m` is the size of the banned list. The time complexity is dominated by the iteration through the numbers from 1 to `n` and updating the allowed array.
- Space Complexity: O(n), as we store an array of size `10001` to mark allowed numbers. This array size is dependent on the range of numbers (up to 10000, assuming `n <= 10000`).
*/
