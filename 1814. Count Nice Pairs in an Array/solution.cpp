// The class definition for the solution
class Solution {
public:
    // The function that takes an array of integers as input and returns the number of nice pairs in the array
    int countNicePairs(vector<int>& nums) {
        // A constant value that represents the modulo operation
        constexpr int M = 1e9 + 7;
        // A map that stores the count of each difference between an element and its reverse
        unordered_map<int, int> cnt;
        // A variable that stores the result, initialized to zero
        int res = 0;
        // A loop that iterates over the array elements
        for (int n : nums) {
            // A variable that stores the reverse of the current element
            int rv = 0;
            // A loop that reverses the digits of the current element
            for (int k = n; k > 0; k /= 10) {
                rv = (rv * 10) + k % 10;
            }
            // A variable that stores the difference between the current element and its reverse
            int diff = n - rv;
            // A pointer that points to the map entry with the same difference
            auto it = cnt.find(diff);
            // If the difference is not found in the map, insert it with a count of one
            if (it == end(cnt)) {
                cnt.emplace(diff, 1);
            // Otherwise, increment the count of the difference and add it to the result
            } else {
                res = (res + it->second++) % M;
            }
        }
        // Return the result
        return res;
    }
};

/* 
The time complexity of this solution is O(n), where n is the size of the input array. This is because we need to iterate over the array elements once and perform constant time 
operations on each element. 
The space complexity is O(n), where n is the size of the input array. This is because we need to store the count of each difference in a map, which takes O(n) space in the worst 
case.
 */