class Solution {
public:
    string reverseParentheses(string s) {
        vector<int> opened;
        string res;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(')
                opened.push_back(res.length());
            else if (s[i] == ')') {
                int j = opened.back();
                opened.pop_back();
                reverse(res.begin() + j, res.end());
            } else {
                res += s[i];
            }
        }
        return res;
    }
};
