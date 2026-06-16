class Solution {
public:
    string processStr(string s) {
        string result = "";
        for (char& ch : s) {
            if (ch == '*') {
                if (result.length() > 0)
                    result.pop_back();
            } else if (ch == '#') {
                result += result;
            } else if (ch == '%') {
                reverse(begin(result), end(result));
            } else {
                result += ch;
            }
        }
        return result;
    }
};
