class Solution {
public:
    bool checkOnesSegment(string& s) {
        const int n = s.size();
        int i0 = 0;
        while (s[i0] == '1')
            i0++;
        if (i0 == n)
            return 1;
        int i1 = n - 1;
        while (s[i1] == '0')
            i1--;
        return i0 > i1;
    }
};
