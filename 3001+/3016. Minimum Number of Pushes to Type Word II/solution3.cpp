class Solution {
public:
    int minimumPushes(string word) {
        int frequency[26] = {};

        // Count the frequency of each letter.
        for (char c : word) {
            frequency[c - 'a']++;
        }

        // Partition frequencies into groups of 8 largest values.
        nth_element(frequency, frequency + 8, frequency + 26, greater<int>());
        nth_element(frequency + 8, frequency + 16, frequency + 26, greater<int>());
        nth_element(frequency + 16, frequency + 24, frequency + 26, greater<int>());
        // sort(frequency, frequency + 26, greater<int>());

        int totalPushes = 0;

        for (int i = 0; i < 26; i++) {
            int presses = i / 8 + 1;
            totalPushes += frequency[i] * presses;
        }

        return totalPushes;
    }
};
