class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n > 0 && (n & (n - 1)) == 0) {
            int zero_count = 0;
            while (n > 1) {
                zero_count++;
                n >>= 1;
            }
            return zero_count % 2 == 0;
        }
        return false;
    }
};

/* 
Approach:
    Power of Two Check: Before checking if a number is a power of four, it is essential to ensure it's a power of two. Why? Because every power of four is a power of two, 
    but not vice versa. This can be checked by the expression nnn AND (n−1)(n-1)(n−1) which must be zero. This is because powers of two in binary form have only one set bit, 
    and subtracting one from them inverts all the bits after the rightmost set bit.

    Count Zeros: Since not all powers of two are powers of four, we need to further discern them by checking the position of the set bit. Powers of four have their only set 
    bit at odd positions in binary form. We count the number of trailing zeros, and if the count is even, then it's a power of four.


Time complexity: O(log⁡n)
    The while loop will run for as many bits as there are in the number, which is logarithmic in nature.
Space complexity: O(1)
    Only a constant amount of extra space is used.
 */