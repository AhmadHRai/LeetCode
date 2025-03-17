class Solution {
public:
    bool divideArray(vector<int>& nums) {
        // Count frequency of each number
        unordered_map<int, int> frequency;
        for (int num : nums) {
            frequency[num]++;
        }

        // Check if each number appears an even number of times
        for (auto& entry : frequency) {
            if (entry.second % 2 != 0) {
                return false;
            }
        }

        // All numbers can be paired
        return true;
    }
};