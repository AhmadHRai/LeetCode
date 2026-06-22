class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int freq[26] = {};

        for (char ch : text)
            ++freq[ch - 'a'];

        return min({
            freq['b' - 'a'],
            freq['a' - 'a'],
            freq['l' - 'a'] / 2,
            freq['o' - 'a'] / 2,
            freq['n' - 'a']
        });
    }
};
