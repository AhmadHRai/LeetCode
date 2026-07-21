constexpr int MAXN = 100001;
int zeroRunLength[MAXN];

class Solution {
public:
    static int maxActiveSectionsAfterTrade(string& s) {
        int ones = 0;
        int zeroRunCount = 0;
        char previous = '#';

        for (char ch : s) {
            if (ch == '1') {
                ++ones;
            } else {
                if (previous != '0')
                    ++zeroRunCount;
                ++zeroRunLength[zeroRunCount];
            }
            previous = ch;
        }

        int maxMergedZeros = 0;
        for (int run = 1; run < zeroRunCount; ++run) {
            maxMergedZeros = max(maxMergedZeros,
                                 zeroRunLength[run] + zeroRunLength[run + 1]);
        }

        memset(zeroRunLength, 0, (zeroRunCount + 1) * sizeof(int));

        return ones + maxMergedZeros;
    }
};
