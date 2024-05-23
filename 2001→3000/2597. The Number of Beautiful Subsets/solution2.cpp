/*
Solution - II (Recursion + Backtracking) [Accepted]

Explanation:
    Since the time complexity is already O(2^n), sorting the array beforehand, for O(nlogn), will not change it.
    Also, if we know that before the current index i, there were no larger elements, then we have to check just for 
    the existence of nums[i] - k, and not for nums[i] + k. Therefore, we sort the array.

    Time/Space Complexities will be the same as before but LeetCode's Online Judge shows a difference of 1200ms and 800ms,
    so I thought to mention it too, as the number of operations will be less.

Complexity Analysis:
    Time Complexity: 
        Sorting the array takes O(nlogn) time. The time complexity of the recursive function remains O(2^n).
        Overall time complexity is dominated by the recursion and remains O(2^n).

    Space Complexity: 
        The recursion stack space and the frequency map still make the space complexity O(n).

*/

class Solution {
private:
    int _beautifulSubsets(vector<int>& nums, int k, unordered_map<int, int>& freq, int i) {
        if (i == nums.size()) { // base case
            return 1;
        }
        int result = _beautifulSubsets(nums, k, freq, i + 1); // nums[i] not taken
        if (!freq[nums[i] - k]) { // check if we can take nums[i]
            freq[nums[i]]++;
            result += _beautifulSubsets(nums, k, freq, i + 1); // nums[i] taken
            freq[nums[i]]--;
        }
        return result;
    }
    
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        sort(nums.begin(), nums.end());
        return _beautifulSubsets(nums, k, freq, 0) - 1; // -1 for empty subset
    }
};
