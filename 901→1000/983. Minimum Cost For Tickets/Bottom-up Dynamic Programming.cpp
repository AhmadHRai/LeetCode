class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int lastDay = days[days.size() - 1];
        vector<int> dp(lastDay + 1, 0);
        
        int i = 0;
        for (int day = 1; day <= lastDay; day++) {
            if (day < days[i]) {
                dp[day] = dp[day - 1];
            } else {
                i++;
                dp[day] = min({dp[day - 1] + costs[0],
                               dp[max(0, day - 7)] + costs[1],
                               dp[max(0, day - 30)] + costs[2]});
            }
        }
     
        return dp[lastDay];
    }
};

/* 
Intuition

In the previous approach, the recursive calls incurred stack space. This can be avoided by applying the same approach iteratively, which is generally faster than the top-down approach. We will follow a similar approach as the previous one, just in a reverse manner.

We will start with the previous approach's base case and build up the answers for the remaining states using the recursive equation. In this approach, dp[day] represents the minimum cost to travel until day. For each value of day, we got here in one of three ways:

    We bought a one-day ticket on day - 1 with cost costs[0].
    We bought a seven-day ticket on day - 7 with cost costs[1].
    We bought a thirty-day ticket on day - 30 with costs costs[2].

The minimum cost would be the minimum cost of the above three options, i.e.
    dp[day] = Min(dp[day - 1] + costs[0], dp[day - 7] + costs[1], dp[day - 30] + costs[2];

This is the recursive equation that would be required, but as we will iterate over every day from 1 to the last day in the array days we need a way to ignore the days where we don't need to travel. For this, we will keep one variable, i, that would denote the index of the next day in the array days for which we need to travel. If the day we are iterating over now is less than days[i] that would imply that we don't need to travel on this day. Hence, the cost for this day would be the same as the previous day.

Algorithm

    Create a dp array with a size of the last day we need to travel plus 1. Initialize all the values to 0.
    Initialize i = 0; this index represents the index in the array days for which we must buy the ticket.
    Iterate over the days from 1 to the last day in the array days, and for each day:
        If the current day is less than days[i], the cost for dp[day] would be the same as dp[day - 1] as we don't need to travel on this day.
        Otherwise, store the minimum of three options per the recursive equation in the array as dp[day]. Also, increment the variable i as we have bought the ticket for this index and now need to focus on the next index.
    Return dp[lastDay]; lastDay is the last value in the array days.

Complexity Analysis

Here, K is the last day that we need to travel, the last value in the array days.

    Time complexity: O(K).

    The size of array dp is K, and we need to iterate over each of the K days. For each day, the work required is O(1). Therefore, the time complexity would equal O(K).

    Space complexity: O(K).

    The size of array dp is K. Hence, the space complexity would equal O(K).
 */