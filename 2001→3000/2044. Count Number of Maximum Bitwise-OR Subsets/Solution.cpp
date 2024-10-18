#include <vector>
using namespace std;

class Solution
{
public:
    // Backtracking function to count subsets that achieve the maximum OR value
    void backtrack(const vector<int> &nums, int index, int currentOR, int maxOR, int &count)
    {
        // If the current OR equals maxOR, increment the count of valid subsets
        if (currentOR == maxOR)
        {
            count++;
        }

        // Explore further subsets starting from the current index
        for (int i = index; i < nums.size(); ++i)
        {
            // Recursively include nums[i] in the current OR and move to the next index
            backtrack(nums, i + 1, currentOR | nums[i], maxOR, count);
        }
    }

    int countMaxOrSubsets(vector<int> &nums)
    {
        int maxOR = 0;

        // Step 1: Compute the maximum OR value achievable with the elements in nums
        for (int num : nums)
        {
            maxOR |= num;
        }

        int count = 0;
        // Step 2: Use backtracking to count subsets that achieve the max OR value
        backtrack(nums, 0, 0, maxOR, count);

        return count;
    }
};

/*
Approach:
1. Calculate the Maximum OR Value:
   - Traverse through all elements in `nums` to calculate the maximum OR value (`maxOR`) possible by OR-ing all elements together. This represents the highest OR value any subset can achieve.

2. Backtracking to Count Subsets:
   - Using a backtracking approach, explore all possible subsets of `nums`:
     - If a subset’s OR result matches `maxOR`, increment the `count`.
     - Recursively continue adding elements from `nums` to form new subsets and update the OR result.

3. Return the Final Count of Subsets with Maximum OR.

Complexity Analysis:
- Time Complexity: O(2^n), where n is the number of elements in `nums`. This is due to the subset exploration, which involves visiting all subsets.
- Space Complexity: O(n), where n is the depth of the recursion stack in the worst case.
*/
