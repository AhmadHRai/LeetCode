struct Item {
    int price;
    int beauty;

    // Define the operator< to sort Items by price in ascending order.
    bool operator<(const Item& other) const {
        return price < other.price;
    }
};

struct Query {
    int threshold;
    int index;

    // Define the operator< to sort Queries by threshold in ascending order.
    bool operator<(const Query& other) const {
        return threshold < other.threshold;
    }
};

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        // Convert the `items` into a vector of `Item` structs
        vector<Item> all;
        for (const vector<int>& item : items) {
            all.push_back({.price = item[0], .beauty = item[1]});
        }
        sort(all.begin(), all.end());  // Sort items by price in ascending order

        // Convert the `queries` into a vector of `Query` structs with an additional index to retain original order
        vector<Query> qs;
        for (int i = 0; i < queries.size(); ++i) {
            qs.push_back({.threshold = queries[i], .index = i});
        }
        sort(qs.begin(), qs.end());  // Sort queries by threshold in ascending order

        // Vector to store the result for each query
        vector<int> answer(queries.size());

        int index = 0;  // Index to iterate through the `all` array
        int max_beauty = 0;  // Variable to track the maximum beauty found so far

        // Iterate over each query
        for (const Query& q : qs) {
            // Add all items whose price is less than or equal to the current query threshold
            while (index < all.size() && all[index].price <= q.threshold) {
                max_beauty = max(max_beauty, all[index].beauty);  // Update max beauty
                ++index;  // Move to the next item
            }
            answer[q.index] = max_beauty;  // Store the result for this query at its original index
        }

        return answer;  // Return the final results for all queries
    }
};

/*
Approach:
1. Convert `items` into `Item` structs, and sort them by price.
2. Convert `queries` into `Query` structs, keeping track of original indices, and sort by threshold.
3. Iterate through `queries`, for each query, update `max_beauty` with the best item price that is less than or equal to the threshold.
4. Store the result in the corresponding index of `answer`.

Complexity Analysis:
- Time Complexity: O(m log m + n log n), where `m` is the number of items and `n` is the number of queries.
  - Sorting `items` takes O(m log m).
  - Sorting `queries` takes O(n log n).
  - Iterating over `items` and `queries` is linear, O(m + n).
- Space Complexity: O(m + n) for the `Item` and `Query` arrays and the `answer` vector.
*/
