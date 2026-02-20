class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<vector<string>> stack;
        stack.push_back({});

        for (char c : s) {
            if (c == '1') {
                stack.push_back({});
            } else {
                vector<string> inner = stack.back();
                stack.pop_back();

                sort(inner.begin(), inner.end(), greater<string>());

                string combined = "1";
                for (auto& str : inner)
                    combined += str;
                combined += "0";

                stack.back().push_back(combined);
            }
        }

        auto& top = stack.back();
        sort(top.begin(), top.end(), greater<string>());

        string result;
        for (auto& str : top)
            result += str;

        return result;
    }
};
