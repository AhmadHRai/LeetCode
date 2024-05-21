class Solution {
public:
    /**
     * This function generates all possible subsets of a given vector of integers.
     * 
     * @param nums A vector of integers.
     * @return A vector of vectors containing all subsets of nums.
     */
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs; // Vector to store all subsets
        vector<int> sub; // Vector to store the current subset
        subsets(nums, 0, sub, subs); // Helper function to generate subsets
        return subs; // Return the vector containing all subsets
    }

private:
    /**
     * This helper function uses recursion to generate all possible subsets of a given vector of integers.
     * 
     * @param nums A vector of integers.
     * @param i The current index in nums being processed.
     * @param sub The current subset being built.
     * @param subs A vector of vectors to store all subsets.
     */
    void subsets(vector<int>& nums, int i, vector<int>& sub, vector<vector<int>>& subs) {
        subs.push_back(sub); // Add the current subset to the list of subsets
        for (int j = i; j < nums.size(); j++) { // Iterate through the remaining elements
            sub.push_back(nums[j]); // Include nums[j] in the current subset
            subsets(nums, j + 1, sub, subs); // Recurse to generate all subsets including nums[j]
            sub.pop_back(); // Backtrack to generate subsets without nums[j]
        }
    }
};

/*
Intuition

The problem is to generate all possible subsets of a given vector of integers. We can use a backtracking approach to explore all subsets. For each element in the input vector, we have two choices: either include the element in the current subset or exclude it. We recursively apply this decision for all elements to generate all possible subsets.

Algorithm

1. Define a function `subsets` that takes a vector of integers `nums` and returns a vector of vectors containing all subsets of `nums`.
2. Initialize a vector `subs` to store all subsets and a vector `sub` to store the current subset.
3. Call a helper function `subsets` with the initial index 0, the current subset, and the vector to store all subsets.
4. The helper function works as follows:
   - Add the current subset to the list of subsets.
   - Iterate through the remaining elements starting from the current index:
     - Include the current element in the subset.
     - Recursively generate all subsets including the current element.
     - Backtrack by removing the current element from the subset to generate subsets without it.
5. Return the vector containing all subsets.

Complexity Analysis

Let n be the number of elements in the input vector.

Time complexity: O(n * 2^n)
- There are 2^n possible subsets. For each subset, we spend O(n) time copying elements to the result vector. Thus, the overall time complexity is O(n * 2^n).

Space complexity: O(n)
- The space complexity is O(n) for the recursion stack and the current subset being built.

This solution uses backtracking to explore all possible subsets of a given vector of integers. It recursively includes or excludes each element and adds the resulting subsets to the output list. The time complexity is O(n * 2^n) due to the exponential number of subsets, and the space complexity is O(n) for the recursion stack.
*/
