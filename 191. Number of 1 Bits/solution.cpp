class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0; // initialize a variable to store the number of 1 bits
        
        while (n) { // loop until n becomes zero
            n &= (n - 1); // use bitwise AND operation to clear the least significant 1 bit of n
            count++; // increment the count by one
        }
        
        return count; // return the final count
    }
};

/* 
    Approach

    This approach is based on an observation that n & (n - 1) always flips the least significant 1 bit of n to 0, and keeps all other bits unchanged. For example, if n = 101100, then n - 1 = 101011, and n & (n - 1) = 101000. This way, you can reduce the number of 1 bits by one in each iteration, until n becomes zero.

    Complexity Analysis:

    The time complexity of this solution is O(k), where k is the number of 1 bits in n. This is because you only need to perform k iterations to clear all the 1 bits. 
    The space complexity is O(1), as you only use a constant amount of extra space.

 */