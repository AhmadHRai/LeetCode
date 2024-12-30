class Solution {
    // Use dp[i] to record to number of good strings of length i.
    int[] dp;
    int mod = 1_000_000_007;
    
    // Find the number of good strings of length `end`.
    private int dfs(int end, int zero, int one) {
        if (dp[end] != -1)
            return dp[end];
        int count = 0;
        if (end >= one) {
            count += dfs(end - one, zero, one);
        }
        if (end >= zero) {
            count += dfs(end - zero, zero, one);
        }
        dp[end] = count % mod;
        return dp[end];
    }
    
    public int countGoodStrings(int low, int high, int zero, int one) {
        dp = new int[high + 1];
        Arrays.fill(dp, -1);
        dp[0] = 1;
        
        // Add up the number of strings with each valid length [low ~ high].
        int answer = 0;
        for (int end = low; end <= high; ++end) {
            answer += dfs(end, zero, one);
            answer %= mod;
        }
        return answer;
    }
}

/* 
Intuition

    We will implement the same algorithm in approach 1 using a recursive method. Let dfs(end) be the number of good strings of length end.

    The trick is as described before, each time a recursive function calls itself, it reduces the given problem dfs(end) into subproblems dfs(end - zero) and dfs(end - one). The recursion call continues until it reaches a point where the subproblem can be solved without further recursion, that is dfs(0) = 1.

    Similarly, we will also build an auxiliary array dp to avoid repeated computation. Initially, we set every value dp[i] (except dp[0]) as -1, which also implies that dp[i] is not visited. During the recursion, if dp[end] != -1, it means we have already calculated dfs(end) previously, so just return dp[end].

Algorithm

    Create an array dp of size 1 + high. Initialize dp[0] = 1 and the value of all the rest cells as -1.

    Define a recursive function dfs(end), if dp[end] != -1, return dp[end], otherwise:
        Set answer = 0.
        If end >= zero, increment answer by dfs(end - zero).
        If end >= one, increment answer by dfs(end - one).
        Update dp[end] as answer.

    Once the iteration ends, add up the numbers in dp[low ~ high].

Complexity Analysis

    Time complexity: O(high)

        Similarly, it takes O(high) time to fill dp recursively.

    Space complexity: O(high)
        We build an array dp of length high + 1 which takes O(high) space.
        During the recursion steps, there are at most high self calls in the stack, this also takes O(high) space.

 */