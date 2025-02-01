class Solution {
    public:
        bool isArraySpecial(vector<int>& nums) {
            // Iterate through indexes 0 to n - 1
            for (int i = 0; i < nums.size() - 1; i++) {
                // Compare the parities of the current and next number
                if ((nums[i] & 1) ^ (nums[i + 1] & 1) == 0) {
                    // If the two adjacent numbers have the same parity, return
                    // false
                    return false;
                }
            }
    
            // Return true if no pair of adjacent numbers with the same parity are
            // found
            return true;
        }
    };

/* 
Algorithm

    Iterate through nums from index 0 to n - 1, where n is the length of nums:
        For each index i, compare the parities of numbers nums[i] and nums[i + 1]
            If nums[i] & 1 ^ nums[i + 1] & 1 equals 0, there are two adjacent numbers that have the same parity, so it returns false
    If the loop completes without finding two adjacent numbers with the same parity, return true, indicating the array is special.

Complexity Analysis
    Let n be the length of string s.

    Time complexity: O(n)

        In the best case, we find a pair of adjacent numbers with the same parity on the first iteration of the loop, which would take only O(1) time.
        In the worst case, the program has to iterate n−1 times to return a result if no adjacent numbers with the same parity are found, taking O(n−1) time.
        As a result, this leads to an overall time complexity of O(n−1), which can be simplified to O(n).

    Space complexity: O(1)

        The space required does not depend on the size of the input array or any data structures that require additional space, so only constant O(1) space is used.

*/