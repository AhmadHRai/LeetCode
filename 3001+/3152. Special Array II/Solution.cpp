class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> maxR(n);   // Stores the maximum reachable index from each start index
        int R = 0;             // Keeps track of the farthest reachable index

        // Step 1: Calculate the farthest index reachable from each index
        for(int L = 0; L < n; L++) {
            // Ensure that R is at least L
            R = max(R, L);
            // Expand the range as long as adjacent elements have different parity
            while(R < (n - 1) && nums[R] % 2 != nums[R + 1] % 2) {
                ++R;
            }
            maxR[L] = R;  // Store the farthest reachable index from 'L'
        }

        vector<bool> res(queries.size());  // Result array for the queries
        
        // Step 2: Answer each query
        for(int i = 0, qn = queries.size(); i < qn; i++) {
            res[i] = queries[i][1] <= maxR[queries[i][0]];  // Check if the subarray is special
        }

        // Step 3: Return the result for all queries
        return res;
    }
};

/*
Approach:
1. Precompute the maximum reachable index for each starting index (L):
   - For each index `L`, we calculate how far we can go while maintaining alternating parity between adjacent elements (odd/even).
   - We store this maximum reachable index in the `maxR` array.
   
2. Answering queries:
   - For each query `[from i, to i]`, we simply check if the subarray `nums[from i..to i]` is special. This is true if `to i` is less than or equal to `maxR[from i]` (i.e., the farthest reachable index from `fromi` includes `toi`).

3. Return the result:
   - We return a vector of booleans, one for each query, where `true` indicates the subarray is special and `false` otherwise.

Complexity Analysis:
- Time Complexity: O(N + Q), where N is the length of the `nums` array, and Q is the number of queries.
  - Calculating the maximum reachable index for each index in `nums` takes O(N).
  - Answering each query takes O(1) per query, so for Q queries, this takes O(Q).
  
- Space Complexity: O(N + Q)
  - We use O(N) space for the `maxR` array to store the farthest reachable indices.
  - We use O(Q) space for the result array to store the boolean answers for each query.
*/
