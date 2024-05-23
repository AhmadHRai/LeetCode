/*
Solution - V (Iterative DP) [Accepted]

Changing recursion to iteration. To calculate f(i), we need to know f(i+1) and f(i+2). So DP should be filled right to left.
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
            int n = fr.second.size(); // Get the number of unique numbers with the current remainder
            vector<pair<int, int>> s(fr.second.begin(), fr.second.end()); // Convert the map to a vector of pairs for easier access
            vector<int> count(n + 1); // Initialize a vector to store the DP values for each index
            count[n] = 1; // Base case: the last index of count is 1, as there's only one way to end the subset
            for (int i = n - 1; i >= 0; i--) { // Iterate from right to left to fill the DP array
                int skip = count[i + 1]; // Number of beautiful subsets if the current number is skipped
                int take = (1 << s[i].second) - 1; // Number of beautiful subsets if the current number is taken
                if (i + 1 < n && s[i + 1].first - s[i].first == k) { // If the next number has the same remainder and is consecutive
                    take *= count[i + 2]; // Multiply by the number of beautiful subsets starting from the next consecutive number
                } else {
                    take *= count[i + 1]; // Multiply by the number of beautiful subsets starting from the next number
                }
                count[i] = skip + take; // Update the DP value for the current index
            }
            result *= count[0]; // Multiply the result by the number of beautiful subsets starting from the first index
        }
        return result - 1; // Subtract 1 to exclude the empty subset
    }
};

/*
Explanation:

    This solution utilizes an iterative dynamic programming (DP) approach to calculate the number of beautiful subsets.
    It iterates through the given numbers, calculates the frequency of remainders, and stores them in a frequency map.
    Then, for each remainder and its associated numbers, it fills a DP array from right to left to compute the number of beautiful subsets.
    The DP array stores the number of beautiful subsets starting from each index, considering both the cases of taking and skipping the current number.
    By multiplying the counts of beautiful subsets for each remainder, the total number of beautiful subsets is computed.
    Finally, 1 is subtracted from the result to exclude the empty subset.

Time Complexity: 
    O(nlog⁡n), where n is the number of elements in the input array. The time complexity is dominated by sorting the numbers based on remainders.

Space Complexity:
    O(n+k), where n is the number of elements in the input array and k is the number of unique remainders. The space complexity is determined by the frequency map and the DP array.
*/
