class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        // Sort the tokens array in ascending order to facilitate the strategy of playing tokens in order.
        sort(tokens.begin(), tokens.end());
        // Initialize variables: 'res' for the maximum score, 'points' for the current score,
        // 'i' and 'j' as pointers to the start and end of the tokens array.
        int res = 0, points = 0, i = 0, j = tokens.size() - 1;
        // Continue the loop as long as 'i' is less than or equal to 'j'.
        while (i <= j) {
            // If the current power 'P' is greater than or equal to the value of the token at index 'i',
            // play the token by subtracting its value from 'P' and incrementing 'points'.
            if (P >= tokens[i]) {
                P -= tokens[i++];
                res = max(res, ++points);
            } else if (points > 0) {
                // If the current power 'P' is less than the value of the token at index 'i' and there are points,
                // gain power by playing a token with a higher value (from the end of the array) and decrement 'points'.
                points--;
                P += tokens[j--];
            } else {
                // If there are no more points and the current power 'P' is insufficient, break the loop.
                break;
            }
        }
        // Return the maximum score achieved.
        return res;
    }
};

/* 
Approach:

    1. The solution uses a greedy strategy to maximize the score by playing tokens optimally.
    2. It first sorts the tokens array in ascending order. This allows for a more predictable strategy, playing tokens in ascending order of their values.
    3. The algorithm uses two pointers, i and j, to traverse the tokens array. i starts at the beginning, and j starts at the end.
    4. The algorithm tries to play the smallest token possible first (from i) if it can, because playing smaller tokens early can help accumulate more points and potentially 
        play larger tokens later.
    5. If playing a smaller token is not possible due to insufficient power, the algorithm looks for a larger token to play (from j) if there are points available. This 
        helps in regaining power to play smaller tokens later.
    6. The loop continues until i is greater than j, which means all tokens have been considered.
    7. The maximum score achieved is returned.

Complexity Analysis:

    Time Complexity:    The time complexity is O(n log n) due to the sorting of the tokens array. The subsequent loop through the array is O(n), but the sorting dominates 
    the time complexity.
    
    Space Complexity:   The space complexity is O(1) because the solution only uses a constant amount of extra space for variables and does not depend on the size of the 
    input array.

 */