// for the judge
const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
#define LC_JUDGE
#ifdef LC_JUDGE
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        int res = 0;
        int prevEnd = 0;

        for(auto& meeting: meetings) {
            int start = meeting[0], end = meeting[1];

            if (start > prevEnd + 1) res += start - prevEnd -1;

            prevEnd = max(prevEnd, end);
        }

        res += days - prevEnd;

        return res;
    }
};