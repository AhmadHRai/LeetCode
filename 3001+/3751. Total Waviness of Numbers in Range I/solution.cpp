class Solution {
private:
    static constexpr int MAX = 100001;
    static inline int dp[MAX], pref[MAX];

    static inline bool init = []() {
        for (int i = 100; i < MAX; i++) {
            int r = i % 10;
            int m = (i / 10) % 10;
            int l = (i / 100) % 10;

            bool isWave = (m > max(l, r)) | (m < min(l, r));
            dp[i] = dp[i / 10] + isWave;
            pref[i] = pref[i - 1] + dp[i];
        }
        return 0;
    }();

public:
    int totalWaviness(int A, int B) { return pref[B] - pref[A - 1]; }
};
