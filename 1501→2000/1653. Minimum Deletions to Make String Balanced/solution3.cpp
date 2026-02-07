class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        int bcount = 0;
        int deletion = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'b') {
                bcount++;
            } else { // if s[i]=='a'
                deletion = min(deletion + 1, bcount);
            }
        }
        return deletion;
    }
};
