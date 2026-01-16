#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // 2^19 = 524,288 (> 2 * 180,901 for < 35% load factor)
    static constexpr int HASH_SIZE = 1 << 19;
    static constexpr int MASK = HASH_SIZE - 1;

public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        // Always build the hash table on the smaller fence list to minimize insertions
        if (hFences.size() > vFences.size()) {
            swap(hFences, vFences);
        }

        // Flat open-addressing hash table initialized to 0 (valid distances are >= 1)
        vector<int> table(HASH_SIZE, 0);

        const int hSize = hFences.size();
        for (int i = 0; i < hSize; ++i) {
            int fi = hFences[i];
            for (int j = i + 1; j < hSize; ++j) {
                int diff = hFences[j] - fi;
                // Multiplicative Fibonacci hashing
                int idx = (static_cast<uint32_t>(diff) * 2654435769u) & MASK;
                while (table[idx] != 0 && table[idx] != diff) {
                    idx = (idx + 1) & MASK;
                }
                table[idx] = diff;
            }
        }

        int max_side = 0;
        const int vSize = vFences.size();

        // Iterate from largest possible differences to smallest to maximize pruning
        for (int i = 0; i < vSize; ++i) {
            int vi = vFences[i];
            // Early break: if the max possible diff from 'i' is <= max_side, no later 'j' can beat it
            if (vFences.back() - vi <= max_side) {
                break;
            }
            for (int j = vSize - 1; j > i; --j) {
                int diff = vFences[j] - vi;
                if (diff <= max_side) {
                    break; // Since vFences is sorted, smaller 'j' will only yield smaller 'diff'
                }
                int idx = (static_cast<uint32_t>(diff) * 2654435769u) & MASK;
                while (table[idx] != 0) {
                    if (table[idx] == diff) {
                        max_side = diff;
                        break;
                    }
                    idx = (idx + 1) & MASK;
                }
            }
        }

        if (max_side == 0) return -1;
        return (1LL * max_side * max_side) % 1000000007;
    }
};
