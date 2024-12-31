class Solution {
public:
    unordered_set<int> isTravelNeeded;
    
    int solve(vector<int>& dp, vector<int>& days, vector<int>& costs, int currDay) {
        // If we have iterated over travel days, return 0.
        if (currDay > days[days.size() - 1]) {
            return 0;
        }
        
        // If we don't need to travel on this day, move on to next day.
        if (isTravelNeeded.find(currDay) == isTravelNeeded.end()) {
            return solve(dp, days, costs, currDay + 1);
        }
        
        // If already calculated, return from here with the stored answer.
        if (dp[currDay] != -1) {
            return dp[currDay];
        }
        
        int oneDay = costs[0] + solve(dp, days, costs, currDay + 1);
        int sevenDay = costs[1] + solve(dp, days, costs, currDay + 7);
        int thirtyDay = costs[2] + solve(dp, days, costs, currDay + 30);
        
        // Store the cost with the minimum of the three options.
        return dp[currDay] = min(oneDay, min(sevenDay, thirtyDay));
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // The last day on which we need to travel.
        int lastDay = days[days.size() - 1];
        vector<int> dp(lastDay + 1, -1);
        
        // Mark the days on which we need to travel.
        for (int day : days) {
            isTravelNeeded.insert(day);
        }
        
        return solve(dp, days, costs, 1);
    }
};

/* 
Intuition

On each day, if we don't need to travel, then we don't need to buy another ticket; however, if we need to travel today and don't have a ticket from earlier, then we have three choices; we can choose one of the three tickets with different validity and cost. After this, we will move on to the next day and then repeat the process, i.e., if travel on this day is not required, then move on to the next day; otherwise, make one of the three choices among the tickets. In the end, we will return the cost corresponding to the choice that has the minimum cost. This way, we will iterate over every possibility for each day and return the minimum of all the choices.

For this recursive approach, what are the parameter(s) that we need to track? We only need to track the current day that we are iterating over. We define a function solve(currDay) that returns the answer to the problem if we were to start on currDay.

In the recursive function, we will start with currDay as 1. The base condition would be when we have covered all the days, which can be identified as currDay > days[days.length - 1]. Now we need to decide if we need to travel on this day or not; for this, we will check if the currDay is present in days. If not, then we don't need to buy a ticket, and hence we simply move on to the next day by returning solve(currDay + 1). To efficiently find if currDay is present in days or not, we will create a hash set isTravelNeeded which will have all the days on which we need to travel.

If we need to buy a ticket on this day, we have three choices:

    Buy a 1-day pass. We incur a cost of costs[0] and move on to the next day. The total cost is cost[0] + solve(currDay + 1).
    Buy a 7-day pass. We incur a cost of costs[1] and don't need to worry about the next seven days. The total cost is cost[1] + solve(currDay + 7).
    Buy a 30-day pass. We incur a cost of costs[2] and don't need to worry about the next thirty days. The total cost is cost[2] + solve(currDay + 30).

We find all 3 costs and return the minimum of these three options.
This approach, however, is not efficient as there could be three options that we need to iterate over for each of the K days (K can be 365 at max) that would imply the total operations of 3K, which is not efficient. If we observe the below figure, there are repeated subproblems. Notice the green nodes are repeated subproblems signifying that we have already solved these subproblems before. To avoid recalculating results for previously seen subproblems, we will cache the result for each subproblem. The next time we need to calculate the result for a currDay we have already calculated, we can look up the result in constant time instead of recalculating the result.

Algorithm

    Create a dp array with the size of the last day we need to travel plus 1. Initialize all the values to -1, denoting that the answer for this day has not been calculated yet. Also, create a hash set isTravelNeeded from days.
    Create a function solve that takes currDay as an argument:
        If currDay is greater than the last day we need to travel, we can just return 0 as all days have already been covered.
        Check if currDay is not present in isTravelNeeded if not, we can just move on to currDay + 1.
        If the answer for currDay in the array dp isn't -1, it implies that the answer has already been calculated; hence just return it.
        Find the cost for the three tickets we can take for this day, add the corresponding cost, and update dp[currDay] accordingly in the recursive call.
    Call solve passing currDay = 1 and return the answer.

Complexity Analysis

Here, K is the last day we need to travel, the last value in the array days.

    Time complexity: O(K).

    The size of array dp is K+1, and we need to find the answer for each of the K states. For each state, the time required is O(1) as there would be only three recursive calls for each state. Therefore, the time complexity would equal O(K).

    Space complexity: O(K).

    The size of array dp is K+1; also, there would be some stack space required. The maximum active recursion depth would be K, i.e., one for each day. The size of the set isTravelNeeded will be equal to the size of days, i.e. N, considering the integers in days will always be strictly increasing we can say N<=K. Hence, the space complexity would equal O(K).
 */