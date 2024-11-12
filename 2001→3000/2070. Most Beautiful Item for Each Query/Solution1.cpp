class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        // Initialize `maxI` with INT_MAX as a placeholder for price limits in `res`
        int maxI = INT_MAX;
        
        // Initialize `res` with a starting beauty of 0 at price 0 and max limit for the third column
        vector<vector<int>> res = {{0, 0, maxI}};

        // Sort the items by price in ascending order
        sort(items.begin(), items.end());

        // Build `res` with unique prices and maximum beauty for each price
        for (const auto& item : items) {
            int price = item[0];
            int beauty = item[1];
            
            // Only add this item if it has a higher beauty than the last entry in `res`
            if (beauty > res.back()[1]) {
                res.back()[2] = price;  // Update the previous max limit to current price
                res.push_back({price, beauty, maxI});  // Add new entry with updated beauty and max limit
            }
        }

        // Initialize `ans` to store results for each query
        vector<int> ans;

        // For each query, find the maximum beauty that can be achieved within the budget `x`
        for (int x : queries) {
            // Traverse `res` from the end to find the last entry with price <= `x`
            for (int i = res.size() - 1; i >= 0; i--) {
                if (res[i][0] <= x) {
                    ans.push_back(res[i][1]);  // Add the corresponding beauty to `ans`
                    break;
                }
            }
        }

        return ans;  // Return the results for all queries
    }
};

/*
Approach:
1. Sort `items` by price. Initialize `res` to hold the maximum beauty for each price level.
2. For each item, if its beauty exceeds the last recorded maximum in `res`, add this new max beauty at its price.
3. For each query, traverse `res` from the end to find the maximum beauty for the query's budget.
4. Add the result for each query to the `ans` vector.

Complexity Analysis:
- Time Complexity: O(m log m + n log n), where `m` is the number of `items` and `n` is the number of `queries`.
  - Sorting `items` takes O(m log m).
  - For each query, traversing `res` backwards to find the maximum beauty is O(log m) on average.
- Space Complexity: O(m) for the `res` array that stores the max beauty for each price level.
*/
