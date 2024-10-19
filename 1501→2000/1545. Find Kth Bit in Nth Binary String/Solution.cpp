class Solution {
public:
    char findKthBit(int n, int k) {
        // Base case: When n = 1, the binary string is "0"
        if (n == 1) return '0';
        
        // Find the length of the current string Sn, which is 2^n - 1
        int length = (1 << n) - 1;
        
        // Find the middle position
        int mid = length / 2 + 1;
        
        // If k is the middle position, return '1'
        if (k == mid) return '1';
        
        // If k is in the first half, find the bit in Sn-1
        if (k < mid) return findKthBit(n - 1, k);
        
        // If k is in the second half, find the bit in Sn-1 and invert it
        return findKthBit(n - 1, length - k + 1) == '0' ? '1' : '0';
    }
};


/*
Approach:
1. Recursive Structure of Sn:
   - For each binary string `Sn`, the string is constructed as: Sn = Sn-1 + "1" + reverse(invert(Sn-1)).
   - This allows using recursion to break down the problem.

2. Base Case:
   - When n = 1, Sn = "0". Thus, the base case returns '0'.

3. Midpoint Logic:
   - The length of Sn is `2^n - 1`. The middle position (1-based) is `mid = length / 2 + 1`.
   - If k equals `mid`, the bit is '1' because it occupies the center of the pattern.

4. First or Second Half:
   - If k is in the first half (`k < mid`), recursively find the bit in Sn-1.
   - If k is in the second half (`k > mid`), the corresponding bit can be found in the mirrored position of Sn-1 and should be inverted.

Complexity Analysis:
- Time Complexity: O(n), as we recursively reduce n by 1 until reaching the base case.
- Space Complexity: O(n), for the recursion stack.
*/
