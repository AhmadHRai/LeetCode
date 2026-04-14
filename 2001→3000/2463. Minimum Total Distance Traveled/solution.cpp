// #pragma GCC optimize("Ofast,unroll-loops,inline")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

// static const int _ = []() {
//     std::ios_base::sync_with_stdio(false);
//     std::cin.tie(NULL);
//     return 0;
// }();

static long long dp[105];
static long long next_dp[105];
static long long pref[105];
static pair<long long, int> q[105];

class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot,
                                   vector<vector<int>>& factory) {
        int n = robot.size();
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        for (int i = 1; i <= n; ++i)
            dp[i] = 1e16;
        dp[0] = 0;

        for (auto& f : factory) {
            if (f[1] == 0)
                continue;
            long long f_pos = f[0];
            int limit = f[1];

            for (int i = 0; i < n; ++i) {
                pref[i + 1] = pref[i] + std::abs((long long)robot[i] - f_pos);
            }

            int head = 0, tail = 0;
            q[tail++] = {dp[0], 0};

            for (int j = 1; j <= n; ++j) {
                if (head < tail && q[head].second < j - limit)
                    head++;

                next_dp[j] = dp[j];
                if (head < tail) {
                    long long val = q[head].first + pref[j];
                    if (val < next_dp[j])
                        next_dp[j] = val;
                }

                if (dp[j] != 1e16) {
                    long long target = dp[j] - pref[j];
                    while (head < tail && q[tail - 1].first >= target)
                        tail--;
                    q[tail++] = {target, j};
                }
            }
            for (int j = 1; j <= n; ++j)
                dp[j] = next_dp[j];
        }

        return dp[n];
    }
};
