class Solution {
public:
    int numberOfSubstrings(string s) {
        int res = 0;
        vector<int> lastPos = {-1, -1, -1};

        for(int pos = 0; pos < s.length(); pos++) {
            lastPos[s[pos]-'a'] = pos;
            res = res + 1 + min({lastPos[0],lastPos[1],lastPos[2]});
        }

        return res;
    }
};