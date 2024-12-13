class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score = 0;  // Initialize score to 0
        set<pair<int, int>> st;  // Set to store elements as pairs (value, index), automatically sorted

        // Insert all elements along with their indices into the set
        for (int i = 0; i < nums.size(); ++i) {
            st.insert({nums[i], i});
        }

        // Iterate over the set and process elements
        for (auto s : st) {
            if (nums[s.second] == 0) continue;  // Skip the already marked elements
            score += s.first;  // Add the value to score
            nums[s.second] = 0;  // Mark the current element
            if (s.second - 1 >= 0) nums[s.second - 1] = 0;  // Mark the left neighbor
            if (s.second + 1 < nums.size()) nums[s.second + 1] = 0;  // Mark the right neighbor
        }

        return score;  // Return the computed score
    }
};

/* 
Approach Summary:
    This approach uses a sorted set to store elements and process them in ascending order. For each element, it adds its value to the score and marks it and its neighbors as "processed" (set to 0).

Time Complexity:

    Time Complexity: O(n log n), due to the operations on the set (insertion and removal), which take O(log n) time for each element.
    Space Complexity: O(n), due to the storage in the set.
 */