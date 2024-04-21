class Solution:
    def paintWalls(self, cost, time):        
        @cache
        def dp(i, t):
            if i == len(cost): return 0 if t >= 0 else inf
            return min(dp(i + 1, t - 1), cost[i] + dp(i + 1, min(t + time[i], len(cost))))
        return dp(0, 0)

""" 
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
 """
 