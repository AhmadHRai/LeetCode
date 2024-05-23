/*
Solution - III (Recursion Optimized) [Accepted]

Explanation:
    In solution2, we are trying to make every possible subset. However, if there are no elements in the array 
    whose difference is k, we can directly return 2^n - 1 without going to every subset. This optimization can reduce 
    the number of operations.

    To implement this optimization, we can separate the given array into subsets such that there is no pair (x1, x2),
    x1 and x2 belonging to different subsets, and |x1 - x2| = k. We can make these subsets based on the remainder (mod k).
    Each subset will contain elements of the form [x, x + k, x + 2k, ..., x + λk].
    The number of beautiful subsets for each subset can be calculated independently, and the final answer is the product 
    of the counts of beautiful subsets for all subsets, minus 1 for the empty subset.

/*
Complexity Analysis:
    Time Complexity:
        Sorting the map takes O(nlogn) time.
        The recursion involves O(2^n) operations.
        Overall time complexity is dominated by the recursion O(n log n + 2^n) and remains O(2^n).

    Space Complexity:
        The space complexity includes the space used by the recursion stack and the map.
        Building the map takes O(n + k) space, where k is the number of different remainders.
        The recursion stack space is O(n).
        Overall space complexity is O(n + k).
*/


class Solution {
private:
    // Recursive function to calculate the number of beautiful subsets for a subset starting from index i
    int beautifulSubsets(vector<pair<int, int>>& s, int n, int k, int i) {
        if (i == n) {
            return 1;
        }
        int skip = beautifulSubsets(s, n, k, i + 1); // 1 * f(i + 1)
        int take = (1 << s[i].second) - 1; // take s[i]
        if (i + 1 < n && s[i + 1].first - s[i].first == k) { // next number is s[i] + k
            take *= beautifulSubsets(s, n, k, i + 2);
        } else {
            take *= beautifulSubsets(s, n, k, i + 1);
        }
        return skip + take;
    }

public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int result = 1;
        map<int, map<int, int>> freq; // {remainder : {num : frequency}}
        // Splitting subsets based on remainder and calculating frequency
        for (int& x: nums) {
            freq[x % k][x]++;
        }
        // Loop for calculating f(s1) * f(s2) * ...
        for (auto& fr: freq) {
            vector<pair<int, int>> s(fr.second.begin(), fr.second.end());
            result *= beautifulSubsets(s, s.size(), k, 0);
        }
        return result - 1; // -1 for empty subset
    }
};
