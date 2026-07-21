class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int cunt = count(s.begin(), s.end(), '1');

        int i = 0;
        int gain = 0;
        int prev = INT_MIN, curr = 0;

        while (i < n) {
            int start = i;
            while (i < n && s[i] == s[start])
                i++;

            if (s[start] == '0') {
                curr = i - start;
                gain = max(gain, prev + curr);
                prev = curr;
            }
        }

        return cunt + gain;
    }
};
