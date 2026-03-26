
class Solution
{
public:
    bool canPartitionGrid(vector<vector<int>> &grid)
    {
        static constexpr int max_n = 1e5 + 1;

        long long total = 0;
        array<int, max_n> cnt{};
        for (const auto &row : grid)
        {
            for (int x : row)
            {
                total += x;
                ++cnt[x];
            }
        }

        auto check = [&](auto f, int m, int n)
        {
            array<int, max_n> pre_cnt{};
            auto can_delete = [&](long long x, int lo, int hi, auto... tag)
            {
                if (x >= max_n)
                {
                    return false;
                }
                if (hi - lo == 1 || n == 1)
                {
                    return f(lo, 0) == x || f(lo, n - 1) == x || f(hi - 1, 0) == x || f(hi - 1, n - 1) == x;
                }
                if (sizeof...(tag) == 0)
                {
                    return pre_cnt[x] > 0;
                }
                else
                {
                    return cnt[x] > pre_cnt[x];
                }
            };
            long long sum = 0;
            for (int i = 0; i < m - 1; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    int x = f(i, j);
                    sum += x;
                    ++pre_cnt[x];
                }
                if (auto sum2 = total - sum; sum == sum2)
                {
                    return true;
                }
                else if (sum < sum2)
                {
                    if (can_delete(sum2 - sum, i + 1, m, 0))
                    {
                        return true;
                    }
                }
                else if (can_delete(sum - sum2, 0, i + 1))
                {
                    return true;
                }
            }
            return false;
        };

        auto f1 = [&](int i, int j)
        { return grid[i][j]; };
        auto f2 = [&](int i, int j)
        { return grid[j][i]; };
        const int m = grid.size();
        const int n = grid[0].size();

        return check(f1, m, n) || check(f2, n, m);
    }
};
