using ll = long long;
constexpr int N = 1e5;
static ll Len[N] = {0};

class Solution {
public:
    static char processStr(string& s, long long k) {
        const int n = s.size();
        ll L = 0;
        int i = 0;
        for (char c : s) {
            L += (c >= 97) - ((L > 0) & (c == 42));
            L <<= (c == 35);
            Len[i++] = L;
        }
        if (L - 1 < k)
            return '.';

        bool flag = 0;
        for (; --i >= 0 && !flag;) {
            const char c = s[i];
            L = Len[i] >> (c == 35);
            k = (-(ll)(c == 37) & (L - 1 - k)) + (-(ll)(c != 37) & k);
            k -= (-(ll)((c == 35) & (k >= L)) & L);
            flag = ((c >= 97) & (k == L - 1));
        }
        return !flag ? '.' : s[++i];
    }
};
