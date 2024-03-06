class Solution {
public:
    bool stoneGame(vector<int>& p) { // Function to determine if Alice can win the game
        vector<int> dp = p; // Initialize a DP array with the same values as the input array
        for (int d = 1; d < p.size(); d++) // Loop through the distance between stones
            for (int i = 0; i < p.size() - d; i++) // Loop through each stone
                dp[i] = max(p[i] - dp[i + 1], p[i + d] - dp[i]); // Calculate the maximum number of stones Alice can get
        return dp[0] > 0; // Return true if Alice can get more stones than 0, indicating she can win
    }
};

/* 
 Approach:

    The approach uses a 1D DP array dp to store the maximum number of stones Alice can get from each possible starting point.
    It iterates through each possible distance d between stones, starting from 1.
    For each distance d, it iterates through each stone i and calculates the maximum number of stones Alice can get by choosing the current stone (p[i]) and the best possible move for 
        the opponent (max(p[i] - dp[i + 1], p[i + d] - dp[i])).
    The calculation considers two scenarios: taking the current stone (p[i]) and the opponent's best move (dp[i + 1]), or taking the stone at the end of the current distance (p[i + d]) 
        and the opponent's best move (dp[i]).
    The final result is based on whether the maximum number of stones Alice can get from the first stone (dp[0]) is greater than 0.

 Analysis:

    Time Complexity: O(n^2), where n is the number of stones. This is because the algorithm uses two nested loops to iterate through each stone and each possible distance.
    Space Complexity: O(n), where n is the number of stones. This is because the DP array dp uses one entry for each stone.

 */