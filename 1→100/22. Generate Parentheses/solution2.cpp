class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s(2 * n, ' ');

        auto search = [&](auto&& self, int i, int open) {
            if (open > 2 * n - i) {
                return;
            }
            if (i == 2 * n) {
                res.push_back(s);
                return;
            }
            if (open > 0) {
                s[i] = ')';
                self(self, i + 1, open - 1);
            }
            s[i] = '(';
            self(self, i + 1, open + 1);
        };

        search(search, 0, 0);
        return res;
    }
};
