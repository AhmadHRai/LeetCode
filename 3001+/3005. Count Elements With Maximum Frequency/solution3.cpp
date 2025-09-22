class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        // Find the frequency of each element
        unordered_map<int, int> frequencies;
        for (int num : nums) {
            frequencies[num]++;
        }

        // Determine the maximum frequency
        int maxFrequency = 0;
        for (auto [num, frequency] : frequencies) {
            maxFrequency = max(maxFrequency, frequency);
        }

        // Calculate the total frequencies of elements with the maximum frequency
        int frequencyOfMaxFrequency = 0;
        for (auto [num, frequency] : frequencies) {
            if (frequency == maxFrequency) {
                frequencyOfMaxFrequency++;
            }
        }
        return frequencyOfMaxFrequency * maxFrequency;
    }
};