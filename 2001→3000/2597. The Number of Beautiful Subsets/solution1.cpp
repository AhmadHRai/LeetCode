/*
Solution - I (Recursion + Backtracking) [Accepted]

Explanation:
    Let's say we have to decide to take or not take the element at index i. We can recursively make two calls,
    one for not taking it and another for taking it. Since the question specifies that the subset should be non-empty, 
    1 is subtracted from the final result.

    To take the element at index i, the elements nums[i] ± k should not be taken in the subset before.
    A frequency map can be made to keep track of elements taken till now.

Complexity Analysis:
    Time Complexity: 
        Since the maximum number of subsets can be 2^n, where n is the size of the input nums array,
        the time complexity will be O(2^n).

    Space Complexity: 
        The recursion stack space and the frequency map will make the space complexity O(n).

Reference:
    https://leetcode.com/problems/the-number-of-beautiful-subsets/solutions/3363862/c-java-python-evolve-brute-force-to-dp-explained-7-approaches
*/

class Solution {
private:
    int _beautifulSubsets(vector<int>& nums, int k, unordered_map<int, int>& freq, int i) {
        if (i == nums.size()) { // base case
            return 1;
        }
        int result = _beautifulSubsets(nums, k, freq, i + 1); // nums[i] not taken
        if (!freq[nums[i] - k] && !freq[nums[i] + k]) { // check if we can take nums[i]
            freq[nums[i]]++;
            result += _beautifulSubsets(nums, k, freq, i + 1); // nums[i] taken
            freq[nums[i]]--;
        }
        return result;
    }
    
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        return _beautifulSubsets(nums, k, freq, 0) - 1; // -1 for empty subset
    }
};
