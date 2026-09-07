class Solution {
public:
    int distinctSubseqII(string S) {
        int res = 0, added = 0, mod = 1e9 + 7, endsWith[26] = {};
        for (char c : S) {
            added = (res - endsWith[c - 'a'] + 1) % mod;
            res = (res + added) % mod;
            endsWith[c - 'a'] = (endsWith[c - 'a'] + added) % mod;
        }
        return (res + mod) % mod;
    }
};
