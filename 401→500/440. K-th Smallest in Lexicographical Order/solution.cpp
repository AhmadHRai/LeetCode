class Solution {
public:
    // Method to find the k-th smallest number in lexicographical order from 1 to n
    int findKthNumber(long n, int k) {
        // Lambda function to calculate the gap between two numbers in the lexicographical order
        auto getGap = [&n](long a, long b) {
            long gap = 0; // Initialize the gap counter
            while (a <= n) {
                gap += min(n + 1, b) - a; // Count numbers between a and b (exclusive)
                a *= 10; // Move to the next level (10 * a)
                b *= 10; // Move to the next level (10 * b)
            }
            return gap; // Return the total gap
        };

        long currNum = 1; // Start with the smallest number in lexicographical order

        // Iterate until we find the k-th number
        for (int i = 1; i < k;) {
            long gap = getGap(currNum, currNum + 1); // Calculate the gap from currNum to currNum + 1
            if (i + gap <= k) { // If the gap plus current count is less than or equal to k
                i += gap; // Move the count forward by the gap
                ++currNum; // Move to the next number in lexicographical order
            } else { // If k lies within the gap
                ++i; // Increment the count
                currNum *= 10; // Go deeper (move to the next prefix)
            }
        }

        return currNum; // Return the k-th smallest number
    }
};

/*
Approach:
1. Use a lambda function `getGap` to compute how many numbers exist between two lexicographical numbers `a` and `b` (exclusive) while ensuring they are within the limit `n`.
2. Start with the smallest number (1) and iterate until reaching the k-th number:
   - If the gap from the current number to the next is sufficient to reach k, increment the current count and move to the next number.
   - If k lies within the gap, go deeper by multiplying the current number by 10 (to explore the next level).
3. Return the current number when the loop completes.

Time Complexity:
- O(log n), where `n` is the upper limit. The while loop inside `getGap` can execute at most 10 times for each call due to the nature of the prefix structure.

Space Complexity:
- O(1), as the solution uses a constant amount of space regardless of input size.
*/
