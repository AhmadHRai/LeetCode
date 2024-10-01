#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        // If the array size is odd, we can't form pairs
        if (arr.size() & 1) return false;
        
        unordered_map<int, int> m; // Map to store the count of remainders
        // Calculate remainders and count their occurrences
        for (auto x : arr) {
            m[(x % k + k) % k]++; // Store the count of remainders in a map
        }
        
        // Check conditions for pairing
        for (auto x : arr) {
            int rem = (x % k + k) % k; // Calculate the remainder
            
            // If remainder is 0, ensure there are an even count of such numbers
            if (rem == 0) {
                if (m[rem] & 1) return false; // Odd count can't form pairs
            } 
            // For other remainders, check counts of rem and k-rem
            else if (m[rem] != m[k - rem]) return false; // Counts must match for pairing
        }
        return true; // All checks passed, pairs can be formed
    }
};

/*
 * Approach:
 * The goal is to determine if we can arrange the integers in the array 
 * such that for every integer x, there is a corresponding integer y = -x
 * such that (x + y) is divisible by k.
 * 
 * Steps:
 * 1. Check if the array size is odd. If so, return false immediately 
 *    because pairs can't be formed.
 * 2. Use a hashmap to count the occurrences of each remainder when 
 *    elements are divided by k. The expression `(x % k + k) % k` ensures 
 *    we handle negative integers correctly by always returning a 
 *    non-negative remainder.
 * 3. Iterate through the array again:
 *    - If the remainder is 0, ensure the count is even (since they can only pair among themselves).
 *    - For any other remainder `rem`, check if the count of `rem` matches the count of `k - rem`.
 * 4. If all conditions are satisfied, return true.
 * 
 * Complexity Analysis:
 * - Time Complexity: O(N), where N is the number of elements in the array.
 *   We traverse the array twice: once for counting remainders and once for checks.
 * - Space Complexity: O(k), where k is the divisor, as we are storing counts for each possible remainder.
 */
