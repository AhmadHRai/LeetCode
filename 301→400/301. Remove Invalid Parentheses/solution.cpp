class Solution {
    unordered_set<string> ans;
    string s;

    void dfs(int pos,
             int left,
             int right,
             int leftRem,
             int rightRem,
             string& path) {

        if (pos == s.size()) {
            if (leftRem == 0 && rightRem == 0 && left == right) {
                ans.insert(path);
            }
            return;
        }

        char c = s[pos];

        // Remove current parenthesis.
        if (c == '(' && leftRem > 0) {
            dfs(pos + 1,
                left,
                right,
                leftRem - 1,
                rightRem,
                path);
        }

        if (c == ')' && rightRem > 0) {
            dfs(pos + 1,
                left,
                right,
                leftRem,
                rightRem - 1,
                path);
        }

        // Keep current character.
        if (c != '(' && c != ')') {
            path.push_back(c);

            dfs(pos + 1,
                left,
                right,
                leftRem,
                rightRem,
                path);

            path.pop_back();
        }
        else if (c == '(') {
            path.push_back(c);

            dfs(pos + 1,
                left + 1,
                right,
                leftRem,
                rightRem,
                path);

            path.pop_back();
        }
        else {
            // Never allow ')' to make balance negative.
            if (right < left) {
                path.push_back(c);

                dfs(pos + 1,
                    left,
                    right + 1,
                    leftRem,
                    rightRem,
                    path);

                path.pop_back();
            }
        }
    }

public:
    vector<string> removeInvalidParentheses(string str) {
        s = str;
        ans.clear();

        int leftRem = 0;
        int rightRem = 0;

        // Calculate the exact number of '(' and ')' that must be removed.
        for (char c : s) {
            if (c == '(') {
                ++leftRem;
            }
            else if (c == ')') {
                if (leftRem > 0) {
                    --leftRem;
                }
                else {
                    ++rightRem;
                }
            }
        }

        string path;
        path.reserve(s.size());

        dfs(0, 0, 0, leftRem, rightRem, path);

        return vector<string>(ans.begin(), ans.end());
    }
};
