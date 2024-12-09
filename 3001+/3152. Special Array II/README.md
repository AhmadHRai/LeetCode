# 3152. Special Array II

### Problem Statement

An array is considered **special** if every pair of its adjacent elements contains two numbers with different parity.

You are given an array of integer `nums` and a 2D integer matrix `queries`, where for `queries[i] = [from i>, to i]` your task is to check that subarray `nums[from i ..to i]` is **special** or not.

Return an array of booleans `answer` such that `answer[i]` is `true` if `nums[from i ..to i]` is special.

### Example 1:

> **Input:** nums = [3,4,1,2,6], queries = [[0,4]]
>
> **Output:** [false]
>
> **Explanation:**
>
> The subarray is `[3,4,1,2,6]`. 2 and 6 are both even.

### Example 2:

> Input: nums = [4,3,1,6], queries = [[0,2],[2,3]]
>
> Output: [false,true]
>
> Explanation:
>
> 1.  The subarray is `[4,3,1]`. 3 and 1 are both odd. So the answer to this query is `false`.
>
> 2.  The subarray is `[1,6]`. There is only one pair: `(1,6)` and it contains numbers with different parity. So the answer to this query is `true`.

### Constraints:

- `1 <= nums.length <= 105`
- `1 <= nums[i] <= 105`
- `1 <= queries.length <= 105`
- `queries[i].length == 2`
- `0 <= queries[i][0] <= queries[i][1] <= nums.length - 1`

---

### Overview

We are given an array of integers `nums` and a 2D array of queries `queries`, where each query `queries[i] = [from, to]` refers to the subarray `nums[from ... to]`. Our task is to determine if each subarray `nums[from ... to]` is special. A subarray is considered special if every pair of adjacent elements has different parity — that is, the subarray alternates between even and odd elements.

### **Approach 1: Binary Search**

#### Intuition:

A brute force solution would involve traversing the entire subarray for each query to check if its elements alternate between even and odd parity. However, this can be inefficient for large inputs. Instead, we can precompute violating indices and use binary search to quickly check if any subarray contains violating indices.

- **Precompute:** Identify all indices where adjacent elements have the same parity.
- **Query Processing:** For each query, perform a binary search to check if any violating indices exist within the range.

```cpp
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums,
                                vector<vector<int>>& queries) {
        vector<bool> ans(queries.size());
        vector<int> violatingIndices;

        for (int i = 1; i < nums.size(); i++) {
            // same parity, found violating index
            if (nums[i] % 2 == nums[i - 1] % 2) {
                violatingIndices.push_back(i);
            }
        }

        for (int i = 0; i < queries.size(); i++) {
            vector<int> query = queries[i];
            int start = query[0];
            int end = query[1];

            bool foundViolatingIndex =
                binarySearch(start + 1, end, violatingIndices);

            if (foundViolatingIndex) {
                ans[i] = false;
            } else {
                ans[i] = true;
            }
        }

        return ans;
    }

private:
    bool binarySearch(int start, int end, vector<int>& violatingIndices) {
        int left = 0;
        int right = violatingIndices.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int violatingIndex = violatingIndices[mid];

            if (violatingIndex < start) {
                // check right half
                left = mid + 1;
            } else if (violatingIndex > end) {
                // check left half
                right = mid - 1;
            } else {
                // violatingIndex falls in between start and end
                return true;
            }
        }

        return false;
    }
};
```

#### Time Complexity:

- **O(M + N \* log M)**, where M is the size of `nums` and N is the number of queries.
- **Space Complexity:** **O(M)** for storing the violating indices.

---

### **Approach 2: Prefix Sum**

#### Intuition:

Instead of storing all violating indices, we can create a prefix sum array to count how many violating indices exist up to each index. For each query, we can determine if the subarray is special by checking if there are no violating indices between the given range.

- **Precompute:** Create a prefix sum array to count violating indices up to each index.
- **Query Processing:** For each query, check if the number of violating indices between `start` and `end` is zero.

```cpp
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums,
                                vector<vector<int>>& queries) {
        vector<bool> ans(queries.size(), false);
        vector<int> prefix(nums.size(), 0);
        prefix[0] = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] % 2 == nums[i - 1] % 2) {
                // new violative index found
                prefix[i] = prefix[i - 1] + 1;
            } else {
                prefix[i] = prefix[i - 1];
            }
        }

        for (int i = 0; i < queries.size(); i++) {
            vector<int> query = queries[i];
            int start = query[0];
            int end = query[1];

            ans[i] = prefix[end] - prefix[start] == 0;
        }

        return ans;
    }
};
```

#### Time Complexity:

- **O(M + N)**, where M is the size of `nums` and N is the number of queries.
- **Space Complexity:** **O(M)** for the prefix array.

---

### **Approach 3: Sliding Window**

#### Intuition:

This approach uses a sliding window technique to compute the farthest index reachable from each index while maintaining alternating parity. This precomputed information allows for constant time query processing.

- **Precompute:** Calculate the farthest index reachable from each starting index while adhering to the parity condition.
- **Query Processing:** For each query, check if the `end` index is within the reach of the `start` index.

```cpp
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums,
                                vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> maxReach(n);
        int end = 0;

        // Step 1: Compute the maximum reachable index for each starting index
        for (int start = 0; start < n; start++) {
            // Ensure 'end' always starts from the current index or beyond
            end = max(end, start);

            // Expand 'end' as long as adjacent elements have different parity
            while (end < n - 1 && nums[end] % 2 != nums[end + 1] % 2) {
                ++end;
            }

            // Store the farthest index reachable from 'start'
            maxReach[start] = end;
        }

        vector<bool> ans(queries.size());

        // Step 2: Answer each query based on precomputed 'maxReach'
        for (int i = 0; i < queries.size(); i++) {
            vector<int> query = queries[i];
            int start = query[0];
            int end = query[1];

            // Check if the query range [start, end] lies within the max
            // reachable range
            ans[i] = end <= maxReach[start];
        }

        return ans;
    }
};
```

#### Time Complexity:

- **O(M + N)**, where M is the size of `nums` and N is the number of queries.
- **Space Complexity:** **O(M)** for the `maxReach` array.

---
