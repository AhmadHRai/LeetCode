class Solution {
public:
    bool isValid(const string& s) {
        int balance = 0;

        for (char c : s) {
            if (c == '(') {
                ++balance;
            }
            else if (c == ')') {
                if (--balance < 0)
                    return false;
            }
        }

        return balance == 0;
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;

        unordered_set<string> visited;
        queue<string> q;

        q.push(s);
        visited.insert(s);

        while (!q.empty()) {
            int levelSize = q.size();
            bool found = false;

            while (levelSize--) {
                string cur = q.front();
                q.pop();

                if (isValid(cur)) {
                    ans.push_back(cur);
                    found = true;
                    continue;
                }

                // Don't generate states from this level if a valid
                // answer has already been found at this level.
                if (found)
                    continue;

                for (int i = 0; i < (int)cur.size(); ++i) {
                    if (cur[i] != '(' && cur[i] != ')')
                        continue;

                    // Removing one of consecutive identical parentheses
                    // produces the same string.
                    if (i > 0 && cur[i] == cur[i - 1])
                        continue;

                    string next = cur.substr(0, i) + cur.substr(i + 1);

                    if (visited.insert(next).second) {
                        q.push(next);
                    }
                }
            }

            // Every string in this level has the same number of
            // removals. Therefore, once we find valid strings,
            // they are guaranteed to use the minimum removals.
            if (found)
                break;
        }

        return ans;
    }
};
