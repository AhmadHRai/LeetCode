class Solution {
    public int countGoodStrings(int low, int high, int zero, int one) {
        // Use dp[i] to record to number of good strings of length i.
        int[] dp = new int[high + 1];
        dp[0] = 1;
        int mod = 1_000_000_007;
        
        // Iterate over each length `end`.
        for (int end = 1; end <= high; ++end) {
            // check if the current string can be made by append zero `0`s or one `1`s.
            if (end >= zero) {
                dp[end] += dp[end - zero];
            }
            if (end >= one) {
                dp[end] += dp[end - one];
            }
            dp[end] %= mod;
        }
        
        // Add up the number of strings with each valid length [low ~ high].
        int answer = 0;
        for (int i = low; i <= high; ++i) {
            answer += dp[i];
            answer %= mod;
        }
        return answer;
    }
}

/* 
Intuition

We can build an array dp to record the number of good strings with each length. 
Let dp[i] be the number of good strings with length i. 
Set dp[0] = 1 before filling the rest of dp as the empty string is the only good string with length 0.
Then we try to find the relation between each problem dp[i] with smaller subproblems.
If a good string of length 5 ends with 0, it means that every good string of length 4 can be turned into a good string of length 5 by appending 0. Thus we increment dp[5] by dp[4], which in the general case is dp[end] += dp[end - zero].
Note that it is suggested to check if end >= zero before we increment dp[end], and only apply the increase if end >= zero.
Similarly, if the string ends with 11, it means that every good string of length 3 can be turned into a good string of length 5 by appending 11. Thus we increment dp[5] by dp[3].
Now we have found both the base case dp[0] = 1 and the recurrence relations, it's time to fill the array and find the number of good strings of each length in the range [low ~ high].

Algorithm

    Create an array dp of size 1 + high. Initialize dp[0] = 1.

    Iterate over each length end:
        If end >= zero, increment dp[end] by dp[end - zero].
        If end >= one, increment dp[end] by dp[end - one].

    Once the iteration ends, add up the numbers in dp[low ~ high].

Complexity Analysis

    Time complexity: O(high)
        We filled the array dp iteratively, each step includes at most two summation steps which takes constant time.

    Space complexity: O(high)
        We build an array dp of length high + 1.

 */