/*
Solution - VII (Iterative DP: Forward) [Accepted]

In previous approaches, we were calculating in reverse direction (right to left) of s. Due to this, we needed to convert sorted map to array first. It can be avoided if we 
traverse left to right.
*/

class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int result = 1; // Initialize the result variable to keep track of the total number of beautiful subsets
        map<int, map<int, int>> freq; // Map to store the frequency of remainders and their corresponding numbers
        for (int& x : nums) { // Iterate through the input numbers
            freq[x % k][x]++; // Update the frequency map with the remainder and the number
        }
        for (auto& fr : freq) { // Iterate through each remainder and its associated numbers
            int prevNum = -k, prev2, prev1 = 1, curr; // Initialize variables to store the previous numbers and the current DP value
            for (auto& [num, f] : fr.second) { // Iterate through each number and its frequency
                int skip = prev1; // Number of beautiful subsets if the current number is skipped
                int take = ((1 << f) - 1) * (num - prevNum == k ? prev2 : prev1); // Number of beautiful subsets if the current number is taken
                curr = skip + take; // Calculate the current DP value
                prev2 = prev1; // Update prev2 to the previous value of prev1
                prev1 = curr; // Update prev1 to the current DP value
                prevNum = num; // Update prevNum to the current number
            }
            result *= curr; // Multiply the result by the current DP value
        }
        return result - 1; // Subtract 1 to exclude the empty subset
    }
};

/*
Time Complexity: O(nlog⁡n), where n is the number of elements in the input array. The time complexity is dominated by sorting the numbers based on remainders.

Space Complexity: O(n+k), where n is the number of elements in the input array and k is the number of unique remainders. The space complexity is determined by the frequency 
map and a few additional variables used for DP.
*/
