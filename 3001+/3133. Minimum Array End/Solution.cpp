class Solution {
public:
    long long minEnd(int n, int x) {
        // Initialize `a` to `x`, which will store the minimum possible endpoint
        long long a = x;
        
        // `b` is used as a mask to check each bit in `x`
        long long b;
        
        // Reduce `n` by 1, as we need `n - 1` transformations
        n--;

        // Iterate through powers of 2 (bits)
        for (b = 1; n > 0; b <<= 1) {
            // If the current bit in `x` is 0
            if ((b & x) == 0) {
                // Set this bit in `a` if the least significant bit of `n` is 1
                a |= (n & 1) * b;

                // Right shift `n` to process the next bit
                n >>= 1;
            }
        }
        
        // Return the minimum endpoint value
        return a;
    }
};

/*
Approach:
1. Initialize `a` to `x` as the starting point for the minimum endpoint.
2. For each power of 2 (`b`), check if the corresponding bit in `x` is set:
   - If it's not set, check the least significant bit of `n`.
   - If the least significant bit of `n` is 1, set this bit in `a`.
   - Shift `n` right by one to process the next bit.
3. Continue this process until all bits in `n` are processed, yielding the minimum endpoint `a`.

Complexity Analysis:
- Time Complexity: O(log n), as we iterate through each bit in `n`.
- Space Complexity: O(1), as we use only a few extra variables.
*/
