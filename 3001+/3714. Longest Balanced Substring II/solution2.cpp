#include <string>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <cstring>

using namespace std;

// Static buffers allocated once in BSS segment across all test cases:
// Zero heap allocation overhead per test case!
static constexpr int MAXN = 100005;
static int first_pos[2 * MAXN];
static int seen_ver[2 * MAXN];
static int current_ver = 0;

// Flat open-addressing hash table for Case 3 (2^18 = 262,144 slots > 2 * 10^5)
static constexpr int HT_SIZE = 1 << 18;
static constexpr int HT_MASK = HT_SIZE - 1;
static uint64_t ht_keys[HT_SIZE];
static int ht_vals[HT_SIZE];
static int ht_ver[HT_SIZE];

class Solution {
    // Case 2 helper: O(N) time with direct array indexing & O(1) resets
    void solve2(const char* s, int n, char x, char y, int& maxi) {
        current_ver++;
        int ver = current_ver;
        int sum = n; // Offset by n so range [-n, n] maps to [0, 2n]

        seen_ver[sum] = ver;
        first_pos[sum] = -1;

        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c == x) {
                sum++;
            } else if (c == y) {
                sum--;
            } else {
                // O(1) clear! Just advance the version tag
                ver = ++current_ver;
                sum = n;
                seen_ver[sum] = ver;
                first_pos[sum] = i;
                continue;
            }

            if (seen_ver[sum] == ver) {
                maxi = max(maxi, i - first_pos[sum]);
            } else {
                seen_ver[sum] = ver;
                first_pos[sum] = i;
            }
        }
    }

public:
    int longestBalanced(string s) {
        const int n = s.size();
        const char* str = s.data();
        int maxi = 1;

        // ---------------------------------------------------------
        // Case 1 & Case 3 Combined in a Single Pass!
        // ---------------------------------------------------------
        int run_len = 1;
        int c0 = 0, c1 = 0, c2 = 0;

        int ver = ++current_ver;

        // Pack pair (0, 0) shifted by +n into a single 64-bit key
        uint64_t init_key = (uint64_t(n) << 32) | uint64_t(n);
        uint32_t h = (init_key ^ (init_key >> 27)) * 0xBF58476D1CE4E5B9ULL;
        int idx = h & HT_MASK;
        ht_ver[idx] = ver;
        ht_keys[idx] = init_key;
        ht_vals[idx] = -1;

        for (int i = 0; i < n; i++) {
            // Case 1: Longest contiguous run of 1 distinct character
            if (i > 0) {
                if (str[i] == str[i - 1]) {
                    run_len++;
                    if (run_len > maxi) maxi = run_len;
                } else {
                    run_len = 1;
                }
            }

            // Case 3: All 3 characters have equal frequency
            // Note: If a valid 1-char or 2-char balanced substring also has count=0
            // for the missing char(s), it is only still valid if ALL 3 are equal (which is only 0=0=0, empty).
            // Actually, wait: in Case 3, if one char never appears (count=0) and the other two appear >0 times,
            // their counts can't equal the 0-count char! So Case 3 strictly requires count[a] == count[b] == count[c].
            c0 += (str[i] == 'a');
            c1 += (str[i] == 'b');
            c2 += (str[i] == 'c');

            uint64_t d1 = (c0 - c1) + n;
            uint64_t d2 = (c0 - c2) + n;
            uint64_t key = (d1 << 32) | d2;

            // Fast MurmurHash3-style mixer + linear probing
            uint32_t hash = (key ^ (key >> 27)) * 0xBF58476D1CE4E5B9ULL;
            int slot = hash & HT_MASK;
            while (ht_ver[slot] == ver && ht_keys[slot] != key) {
                slot = (slot + 1) & HT_MASK;
            }

            if (ht_ver[slot] == ver) {
                maxi = max(maxi, i - ht_vals[slot]);
            } else {
                ht_ver[slot] = ver;
                ht_keys[slot] = key;
                ht_vals[slot] = i;
            }
        }

        // ---------------------------------------------------------
        // Case 2: Exactly 2 distinct characters
        // ---------------------------------------------------------
        solve2(str, n, 'a', 'b', maxi);
        solve2(str, n, 'b', 'c', maxi);
        solve2(str, n, 'a', 'c', maxi);

        return maxi;
    }
};
