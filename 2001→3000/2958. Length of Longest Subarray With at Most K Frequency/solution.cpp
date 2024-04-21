class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> cnt; // Hash map to keep track of frequencies
        int ans = 0; // Initialize the maximum length of a "good" subarray
        int j = 0; // Start of the current subarray (sliding window's left edge)

        for (int i = 0; i < nums.size(); i++) {
            cnt[nums[i]]++; // Increment the frequency of the current element

            // If the frequency of the current element exceeds k, shrink the window from the left
            while (cnt[nums[i]] > k) {
                cnt[nums[j]]--; // Decrement the frequency of the element at the start of the window
                j++; // Move the start of the window to the right
            }

            // Update the maximum length of a "good" subarray
            ans = max(ans, i - j + 1);
        }

        return ans;
    }
};

/*
Intuition and Approach:

    We start by initializing an empty hash map cnt to keep track of the frequency of each element in the current window.
    We iterate over the array nums with two pointers, i and j, where i represents the current position (the right edge of the sliding window), and j represents the start of the current subarray (the left edge of the sliding window).
    For each element nums[i], we increment its frequency in the hash map.
    If the frequency of nums[i] exceeds k, we shrink the window from the left by incrementing j and decrementing the frequency of nums[j] in the hash map until the frequency of nums[i] is k or less.
    After each iteration, we update ans with the maximum length of a "good" subarray found so far.

Time Complexity:

The time complexity of this approach is O(n), where n is the length of the input array nums. This is because we perform a single pass over the array, and each operation inside the loop (incrementing a frequency, decrementing a frequency, and updating the maximum length) takes constant time.

Space Complexity:

The space complexity is O(n), where n is the number of unique elements in the array. This is because in the worst case, all elements in the array are unique, and we need to store their frequencies in the hash map. The space for the variables ans and j is negligible compared to the space used by the hash map.
*/