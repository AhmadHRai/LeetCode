class Solution {
public:
    int longestCommonSubsequence(string_view text1, string_view text2) {
        if (text2.length() < text1.length()) swap(text1, text2); // save space
        unsigned n = text1.length();
        unsigned m = text2.length();
        do { // not a loop - just a way to quickly exit out of context
            const char minc = 'a';
            const char maxc = 'z';
            const unsigned numc = maxc - minc + 1;
            if (n < numc*2) // too short string, too much setup overhead
                break;
            array<unsigned, numc> cnt1;
            cnt1.fill(0); // O(numc)
            for (auto c: text1) ++cnt1[c - minc]; // O(n)
            array<unsigned, numc> last;
            // ^^ points to position one after last index of c in arr
            last.fill(0); // O(numc) 
            unsigned N = 0; // N is sum of count of each character of text1
            // that is also present in text2 (including duplicates)
            unsigned l = 0;
            for (auto c: text2) {
                c -= minc;
                N += cnt1[c];
                if (last[c] == 0) {
                    l += cnt1[c];
                    last[c] = l;
                }
            } // O(m)
            if (N == 0) // no common characters
                return 0;
            assert(l <= n);
            // this approach takes O(N log n) time and O(n) space;
            // it can be faster or slower than usual O(mn) time, O(n) space algorithm;
            // decide which we prefer
            const unsigned logn = 8*sizeof(n) - __builtin_clz(n);
            // worst case: N = m*n ("abaaaaa" "aaaaaaba")
            if (N*logn > n*m) // prefer simple O(mn) approach
                break;
            // up to this point, we consumed O(n + m + numc) time and O(numc) space
            //cout << "fast" << endl;
            vector<unsigned> arr(l);
            // fill indexes of each character in text1 in reverse order,
            // they will be stored at arr[last[c]-cnt1[c]:last[c]]
            for (unsigned i = 0; i < n; i++) {
                auto c = text1[i] - minc;
                if (last[c] == 0)
                    continue;
                arr[--last[c]] = i;
            } // O(n)
            // from here on, last[c] points to *first* index for c in arr
            // Now, usual longest increasing subsequence
            vector<unsigned> minh;
            minh.reserve(n); // lcs cannot be longer than n
            for (auto c: text2) {
                c -= minc;
                const auto pos = last[c];
                const auto cnt1c = cnt1[c];
                for (unsigned i = 0; i < cnt1c; i++) {
                    auto h = arr[pos + i]; // generate expanded arr on the fly
                    auto lb = lower_bound(minh.begin(), minh.end(), h);
                    if (lb == minh.end())
                        minh.push_back(h);
                    else
                        *lb = h; // arr[i] <= *lb
                }
            } // O(N log n)
            unsigned lis = minh.size();
            return lis;
            // time = O(n + m + k + N log n), space = O(n + k)
        } while(false);
        // space = O(min(n, m)); time = O(n*m)
        vector<unsigned> dp(n);
        for (unsigned i = 0; i < m; i++) {
            unsigned dpi1j1 = 0; // dp[i - 1][j - 1]
            unsigned dpij1 = 0; // dp[i][j - 1]
            const auto c2 = text2[i];
            for (unsigned j = 0; j < n; j++) {
                auto &dpi1j_dpij = dp[j]; // dp[i - 1][j]
                dpij1 = (c2 == text1[j]) ? dpi1j1 + 1:
                    max(dpi1j_dpij, dpij1); // dpi1j
                dpi1j1 = dpi1j_dpij;
                dpi1j_dpij = dpij1; // dpij
            }
        }
        return dp.back();
    }
};