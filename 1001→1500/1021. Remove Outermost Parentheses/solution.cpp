class Solution {
public:
    string removeOuterParentheses(string s) {
        int depth = 0;
        string res;
        for (auto c : s) {
            if (c == ')') {
                depth--;
            }
            if (depth) {
                res.push_back(c);
            }
            if (c == '(') {
                depth++;
            }
        }
        return res;
    }
};
