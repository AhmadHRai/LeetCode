class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        for (int num : nums)
            k ^= num;
        return __builtin_popcount(k);
    }
};

/* 
Approach:

This solution uses bitwise XOR operations to find the minimum number of operations required to make the array XOR equal to `k`. The approach involves XORing all elements 
in the array with `k` and then counting the number of set bits in the result. The number of set bits represents the number of operations needed to make the array XOR 
equal to `k`.

Complexity:

    Time Complexity: O(n), where n is the number of elements in the array. This is because each element in the array is processed once during the XOR operation.
    Space Complexity: O(1), as the algorithm does not use any additional space that scales with the input size.

*/

class Solution2 {
public:
    int minOperations(vector<int>& n, unsigned int k) {
        return popcount(reduce(begin(n), end(n), k, bit_xor<>()));
    }
};

/* 
Approach:

This solution also uses bitwise XOR operations to find the minimum number of operations required to make the array XOR equal to `k`. However, it employs the `reduce` 
function from the C++ Standard Library to XOR all elements in the array with `k` in a more concise manner. The `popcount` function is then used to count the number of 
set bits in the result, which represents the number of operations needed.

Complexity:

Time Complexity: O(n), where n is the number of elements in the array. This is because the `reduce` function processes each element in the array once.

Space Complexity: O(1), as the algorithm does not use any additional space that scales with the input size.




Both solutions aim to find the minimum number of operations required to make the array XOR equal to k by XORing all elements in the array with k and counting the number of set bits in the result. The main difference lies in the implementation details, with the second solution utilizing more modern C++ features for a more concise and readable approach. The first one is just flexing.
*/