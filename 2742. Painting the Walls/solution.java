class Solution {
    int cache[][], n; 
    public int paintWalls(int[] cost, int[] time) {
        n = cost.length;
        cache = new int[n][2 * n + 1];
        for (int[] row : cache) Arrays.fill(row, -1);
        return dp(cost, time, 0, 0);
    }
    private int dp(int[] cost, int[] time, int i, int t) {
        if (i == n) return (t >= 0) ? 0 : (int) 1e9;
        if (cache[i][t + n] != -1) return cache[i][t + n];
        return cache[i][t + n] = Math.min(dp(cost, time, i + 1, t - 1),
                        cost[i] + dp(cost, time, i + 1, Math.min(t + time[i], n)));
    }
}

/* 
Approach

Each dp state will cache the total time to complete existing walls where we used a paid painter and the index.
In java and c++ solutions we add an extra n to t when caching t because t can also be negative

    We track total time it'll take for the existing walls where a paid painter is working
    When this time is positive it means we can have an unpaid painter, paint any wall free of cost in 1 unit of time
    If at the end of the recursion total time to complete walls is negative it means we used too many unpaid painters
    dp(i + 1, t - 1) is the case where we used a free painter for ith wall
    dp(i + 1, min(t + time[i], len(cost))) is the case where we used a paid painter. We can limit this to len(cost) because if it is greater than len(cost), time can not be negative now even if we use an unpaid painter for the rest of the walls. Remember, time can only be negative if we use too many unpaid painters. The minimum value of time can be -len(cost), the case where we use all unpaid painters.

Complexity

    Time complexity: O(n * n)
    Space complexity: O(n * n)

 */