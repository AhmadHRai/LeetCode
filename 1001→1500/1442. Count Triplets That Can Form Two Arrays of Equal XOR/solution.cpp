/**
 * Counts the number of triplets (i, j, k) such that 0 ≤ i < j < k < arr.size() and
 * arr[i] ^ arr[i+1] ^ ... ^ arr[k] == 0.
 *
 * @param arr A vector of integers.
 * @return The number of valid triplets.
 */
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int size = arr.size();
        int count = 0;
        int prefix = 0;

        // Maps to store counts and totals of XOR values encountered
        unordered_map<int, int> countMap = {{0, 1}}, totalMap;

        // Iterating through the array
        for (int i = 0; i < size; ++i) {
            // Calculating XOR prefix
            prefix ^= arr[i];

            // Calculating contribution of current element to the result
            count += countMap[prefix]++ * i - totalMap[prefix];

            // Updating total count of current XOR value
            totalMap[prefix] += i + 1;
        }

        return count;
    }
};

/* 
One Pass Prefix XOR

Intuition:
    This approach is a slight variation of the previous one. The main difference is that it combines 
    the prefix XOR computation and result calculation in a single pass through the array, whereas 
    the third approach performs these steps separately.
    
    Here we eliminate the need for a separate prefix XOR precomputation step. Instead, we maintain 
    a running prefix variable that stores the XOR of elements up to the current index. We update 
    this prefix variable as we iterate through the array by XORing it with the current element: 
    prefix ^= arr[i].
    
    By maintaining this running prefix, we can calculate the contribution of the current XOR value 
    (prefix) to the result on the fly, without the need for precomputed prefix XOR values.
    
    The formula for calculating the contribution remains the same as in the third approach: 
    count += countMap[prefix] * i - totalSum[prefix]. 
    The difference is that we use the running prefix value instead of a precomputed prefix XOR array.
    
Algorithm:
    - Initialize count with 0 to store the count of valid triplets.
    - Initialize prefix with 0 to store the running XOR value.
    - Initialize countMap with {0: 1} to store the count of occurrences of each XOR value, initialized with 0 count as 1.
    - Initialize totalMap as an empty map to store the sum of indices where each XOR value has occurred.
    - Iterate over arr:
        - Update prefix by XORing it with arr[i] (the running XOR value).
        - Calculate the contribution of prefix to count using countMap[prefix] and totalMap[prefix] (based on the count and sum of indices for the current XOR value).
        - Update count with the contribution.
        - Increment countMap[prefix] by updating the count of the current XOR value.
        - Update totalMap[prefix] by adding i + 1 to update the sum of indices for the current XOR value.
    - Return the final count of valid triplets count.

Complexity Analysis:
    - Time complexity: O(n)
      There is only a single loop iterating over the array, resulting in a time complexity of O(n).
      
    - Space complexity: O(n)
      In the worst case, each element in the array can have a unique XOR value, requiring O(n) space 
      to store the counts and totals in the maps.
 */
