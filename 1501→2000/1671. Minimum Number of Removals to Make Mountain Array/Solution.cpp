class Solution {
public:
    // Function to determine the minimum number of removals to form a mountain array
    int minimumMountainRemovals(vector<int>& nums) {
        int N = nums.size(), ans = N; // N is the size of nums, initialize ans to N
        vector<int> a(N), b(N), v; // a: increasing subsequence lengths, b: decreasing subsequence lengths

        // Compute the lengths of the longest increasing subsequences ending at each index
        for (int i = 0; i < N; ++i) {
            int x = nums[i]; // Current number
            // Find the position to replace in vector v
            auto it = lower_bound(begin(v), end(v), x); // Binary search for the first element >= x
            a[i] = it - begin(v); // Length of increasing subsequence at index i
            // Update v with the current number
            if (it != end(v)) *it = x; // Replace the found position
            else v.push_back(x); // Append x if it is greater than all elements in v
        }

        v.clear(); // Clear v for the next calculation

        // Compute the lengths of the longest decreasing subsequences starting at each index
        for (int i = N - 1; i >= 0; --i) {
            int x = nums[i]; // Current number
            // Find the position to replace in vector v
            auto it = lower_bound(begin(v), end(v), x); // Binary search for the first element >= x
            b[i] = it - begin(v); // Length of decreasing subsequence at index i
            // Update v with the current number
            if (it != end(v)) *it = x; // Replace the found position
            else v.push_back(x); // Append x if it is greater than all elements in v
        }

        // Calculate the minimum number of removals needed to form a mountain array
        for (int i = 1; i < N; ++i) {
            // Check if both increasing and decreasing subsequences exist at index i
            if (a[i] && b[i]) 
                ans = min(ans, N - (a[i] + b[i] + 1)); // Update ans with the minimum removals
        }
        
        return ans; // Return the final result
    }
};

/*
Approach:

    The solution utilizes two passes to compute the lengths of the longest increasing and decreasing subsequences 
    using binary search. The first pass fills the `a` array with the lengths of increasing subsequences 
    ending at each index, while the second pass fills the `b` array with the lengths of decreasing subsequences 
    starting from each index. The answer is derived by checking the conditions for a mountain structure 
    and calculating the minimum removals needed.

Complexity:

    Time Complexity: O(N log N), where N is the length of the input array. Each pass involves a binary search 
    for updating the subsequences, resulting in a logarithmic factor.

    Space Complexity: O(N) for the auxiliary arrays `a`, `b`, and `v` used to store lengths of subsequences.

This approach efficiently determines the minimum number of removals required to create a mountain array structure 
while maintaining optimal performance.
*/
