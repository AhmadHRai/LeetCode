/*
Solution - VI (Iterative DP Space Optimized) [Accepted]

To calculate f(i), we only need f(i+1) and f(i+2). Storing f(i+3) onwards is useless.

    curr = f(i)
    next1 = f(i+1)
    next2 = f(i+2)
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
            int n = fr.second.size(), curr, next1 = 1, next2; // Initialize variables to store the current, next1, and next2 DP values
            vector<pair<int, int>> s(fr.second.begin(), fr.second.end()); // Convert the map to a vector of pairs for easier access
            for (int i = n - 1; i >= 0; i--) { // Iterate from right to left to calculate the DP values
                int skip = next1; // Number of beautiful subsets if the current number is skipped
                int take = (1 << s[i].second) - 1; // Number of beautiful subsets if the current number is taken
                if (i + 1 < n && s[i + 1].first - s[i].first == k) { // If the next number has the same remainder and is consecutive
                    take *= next2; // Multiply by the number of beautiful subsets starting from the next consecutive number
                } else {
                    take *= next1; // Multiply by the number of beautiful subsets starting from the next number
                }
                curr = skip + take; // Update the current DP value
                next2 = next1; // Update next2 to the previous value of next1
                next1 = curr; // Update next1 to the current DP value
            }
            result *= curr; // Multiply the result by the current DP value
        }
        return result - 1; // Subtract 1 to exclude the empty subset
    }
};

/*
Time Complexity: O(nlog⁡n), where n is the number of elements in the input array. The time complexity is dominated by sorting the numbers based on remainders.

Space Complexity: O(n+k), where n is the number of elements in the input array and k is the number of unique remainders. The space complexity is determined by the frequency map and a few additional variables used for DP.
*/
