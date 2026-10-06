class Solution {
public:
    int minAddToMakeValid(string s) {
        int brackets = 0;

        int min = 0;
        for (char c : s) {
            if (c == '(') {
                brackets++;
            } else {
                brackets > 0 ? brackets-- : min++;
            }
        }

        return min + brackets;
    }
};
