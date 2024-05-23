/*
Solution - IV (DP: Recursion + Memoization) [Accepted]

This solution uses dynamic programming (DP) with recursion and memoization to calculate the number of beautiful subsets. The function f(i) calculates the number of beautiful subsets starting from index i in the given array s. We memoize the function to avoid redundant calculations.

Time Complexity: O(n log n)
Space Complexity: O(n + k)
*/

class Solution {
private:
    // Recursive function with memoization to calculate the number of beautiful subsets
    int beautifulSubsets(vector<pair<int, int>>& s, int n, int k, int i, vector<int>& count) {
        // Base case: If we reach the end of the subset, return 1
        if (i == n) {
            return 1;
        }
        // If we have already calculated the result for this index, return it
        if (count[i] != -1) {
            return count[i];
        }
        // Calculate the number of subsets by skipping the current element
        int skip = beautifulSubsets(s, n, k, i + 1, count);
        // Calculate the number of subsets by taking the current element
        int take = (1 << s[i].second) - 1;
        if (i + 1 < n && s[i + 1].first - s[i].first == k) {
            take *= beautifulSubsets(s, n, k, i + 2, count);
        } else {
            take *= beautifulSubsets(s, n, k, i + 1, count);
        }
        // Memoize the result and return the total number of subsets
        return count[i] = skip + take;
    }

public:
    // Main function to calculate the total number of beautiful subsets
    int beautifulSubsets(vector<int>& nums, int k) {
        int result = 1;
        map<int, map<int, int>> freq;
        
        // Building the frequency map
        for (int& x : nums) {
            freq[x % k][x]++;
        }
        
        // Calculating beautiful subsets for each subset in the frequency map
        for (auto& fr : freq) {
            vector<pair<int, int>> s(fr.second.begin(), fr.second.end());
            vector<int> count(s.size(), -1); // Memoization array
            result *= beautifulSubsets(s, s.size(), k, 0, count);
        }
        
        // Subtracting 1 for the empty subset
        return result - 1;
    }
};
