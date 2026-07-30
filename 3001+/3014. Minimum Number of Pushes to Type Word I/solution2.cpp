class Solution {
public:
    int minimumPushes(string word) {
        int r = word.size() % 8;
        int c = (word.size() - r) / 8;
        return (4 * c + r) * (c + 1);
    }
};
