class Solution {
    typedef long long ll;

public:
    char processStr(string s, ll k) {
        int n = s.size();
        vector<ll> lens;
        ll len = 0;

        for (auto& ch : s) {
            if (ch == '*')
                len = max(len - 1, 0LL);
            else if (ch == '#')
                len *= 2;
            else if (ch != '%')
                len++;

            lens.push_back(len);
        }

        if (k >= len)
            return '.';

        for (int i = n - 1;; i--) {
            switch (s[i]) {
            case '*':
                break;
            case '#':
                if (k >= lens[i] / 2)
                    k -= lens[i] / 2;
                break;
            case '%':
                k = lens[i] - 1 - k;
                break;
            default:
                if (lens[i] == k + 1)
                    return s[i];
            }
        }
    }
};
