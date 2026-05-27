class Solution {
public:
    int numberOfSpecialChars(string word) {
        array<int, 52> count{};
        count.fill(-1);
        int result = 0;

        for (int i = 0; i < word.size(); ++i) {
            if (word[i] < 'a') {
                if (count[word[i] - 'A'] == -1) {
                    count[word[i] - 'A'] = i; 
                }
            } else {
                count[word[i] - 'a' + 26] = i;
            }
        }

        for (int i = 0; i < 26; ++i) {
            if (count[i] != -1 && count[i + 26] != -1 && count[i + 26] < count[i]) {
                ++result;
            }
        }

        return result;
    }
};
