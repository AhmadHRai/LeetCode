class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        vector<vector<vector<int>>> storeQueries(heights.size());
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            maxIndex;
        vector<int> result(queries.size(), -1);

        // Store the mappings for all queries in storeQueries.
        for (int currQuery = 0; currQuery < queries.size(); currQuery++) {
            int a = queries[currQuery][0], b = queries[currQuery][1];
            if (a < b && heights[a] < heights[b]) {
                result[currQuery] = b;
            } else if (a > b && heights[a] > heights[b]) {
                result[currQuery] = a;
            } else if (a == b) {
                result[currQuery] = a;
            } else {
                storeQueries[max(a, b)].push_back(
                    {max(heights[a], heights[b]), currQuery});
            }
        }

        for (int index = 0; index < heights.size(); index++) {
            // If the priority queue's minimum pair value is less than the
            // current index of height, it is an answer to the query.
            while (!maxIndex.empty() && maxIndex.top()[0] < heights[index]) {
                result[maxIndex.top()[1]] = index;
                maxIndex.pop();
            }
            // Push the with their maximum index as the current index in the
            // priority queue.
            for (auto& element : storeQueries[index]) {
                maxIndex.push(element);
            }
        }
        return result;
    }
};

/*
Approach:
1. **Initial Setup**: 
   - We use a `storeQueries` array to store each query that involves a particular index of the buildings. Each query stores the maximum of the two building heights and the query index.
   - We use a priority queue (`maxIndex`) to maintain queries ordered by the maximum building height between the two queried buildings. This helps in efficiently finding answers to queries as we process each building index.
   - We initialize the `result` vector with `-1` to represent queries whose answers haven't been found yet.

2. **Processing the Queries**:
   - We process each query by comparing the heights of the two queried buildings:
     - If building `a` is shorter than building `b` and `a` is to the left of `b`, then the answer for this query is building `b`.
     - If building `a` is taller than building `b` and `a` is to the right of `b`, then the answer for this query is building `a`.
     - If buildings `a` and `b` are the same, then the answer is just building `a`.
     - Otherwise, the query will be stored in `storeQueries` for further processing.

3. **Processing Building Heights**:
   - We iterate through each building index from left to right.
   - For each building, we check if there are any queries in the priority queue that are now satisfied because the current building is tall enough.
   - If the current building height is taller than the value stored in the priority queue, the query can be answered with the current building index.
   - We push the queries associated with the current building index into the priority queue, ensuring that they are processed when their conditions are met.

4. **Final Result**:
   - The `result` vector contains the leftmost building index for each query.

Complexity Analysis:
    - **Time complexity**: O(n + m log m), where `n` is the number of buildings and `m` is the number of queries. The loop over the buildings and the use of the priority queue ensures that each query is processed in logarithmic time relative to the number of queries.
    - **Space complexity**: O(m + n), where `n` is the number of buildings and `m` is the number of queries, to store the queries and the priority queue.
*/
