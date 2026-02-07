class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        stack<char> stk;
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!stk.empty() && stk.top() == 'b' && s[i] == 'a') {
                stk.pop();
                count++;
            } else {
                stk.push(s[i]);
            }
        }

        return count;
    }
};
