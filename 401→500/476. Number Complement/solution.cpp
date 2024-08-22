class Solution {
public:
    int findComplement(int num) {
        // Create a mask with all bits set to 1
        unsigned mask = ~0;
        
        // Shift the mask left until it becomes larger than num
        while (num & mask) {
            mask <<= 1;
        }
        
        // The complement is obtained by inverting num and masking with ~mask
        return ~mask & ~num;
    }
};

/*
Approach Summary:
- To find the complement of a number `num`, we need to flip all bits of its binary representation.
- Start with a mask initialized to all bits set (i.e., `~0`).
- Shift the mask left until it becomes larger than `num`. This effectively creates a mask with the same number of bits as `num`, all set to 1.
- Compute the complement of `num` by inverting `num` and masking it with `~mask`.

Time Complexity:
- O(1), as the operations performed (bitwise shifts and logical operations) are constant time operations.

Space Complexity:
- O(1), as the space used does not depend on the size of the input but only on a few integer variables.
*/
