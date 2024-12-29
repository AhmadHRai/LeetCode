class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int wordLength = words[0].size();
        int targetLength = target.size();
        const int MOD = 1000000007;

        // Step 1: Calculate frequency of each character at every index in
        // "words".
        vector<vector<int>> charFrequency(wordLength, vector<int>(26, 0));
        for (const string& word : words) {
            for (int j = 0; j < wordLength; ++j) {
                charFrequency[j][word[j] - 'a']++;
            }
        }

        // Step 2: Initialize a DP table.
        vector<vector<long>> dp(wordLength + 1,
                                vector<long>(targetLength + 1, 0));

        // Base case: There is one way to form an empty target string.
        for (int currWord = 0; currWord <= wordLength; ++currWord) {
            dp[currWord][0] = 1;
        }

        // Step 3: Fill the DP table.
        for (int currWord = 1; currWord <= wordLength; ++currWord) {
            for (int currTarget = 1; currTarget <= targetLength; ++currTarget) {
                // Carry over the previous value (not using this index of
                // "words").
                dp[currWord][currTarget] = dp[currWord - 1][currTarget];

                // Add ways using the current index of "words" if the characters
                // match.
                int curPos = target[currTarget - 1] - 'a';
                dp[currWord][currTarget] +=
                    (charFrequency[currWord - 1][curPos] *
                     dp[currWord - 1][currTarget - 1]) %
                    MOD;
                dp[currWord][currTarget] %= MOD;
            }
        }

        // Step 4: The result is in dp[wordLength][targetLength].
        return dp[wordLength][targetLength];
    }
};

/*
Approach

    This solution uses a bottom-up dynamic programming approach to iteratively compute the number of ways to form the target string using the words matrix.
    - We calculate the frequency of each character at each index across all words in the matrix.
    - A DP table is used to store the number of ways to form the target string at each word index and target index combination.
    - The table is filled iteratively, considering two possibilities for each position:
      1. Skip the current word index.
      2. Use the current word index if the characters match the target.
    - Finally, the result is found at dp[wordLength][targetLength].

Complexity

    Time Complexity: O(wordLength * targetLength + wordLength * totalWords)
    - The first part (O(wordLength * totalWords)) represents the time spent on constructing the character frequency matrix.
    - The second part (O(wordLength * targetLength)) comes from filling the DP table, where each state is computed once and involves constant-time operations.

    Space Complexity: O(wordLength * targetLength)
    - The space complexity is dominated by the DP table (dp) and the character frequency matrix (charFrequency).
    - The dp table stores intermediate results for each combination of word index and target index, so its space complexity is O(wordLength * targetLength).
    - The charFrequency matrix has dimensions wordLength x 26 (for each character), leading to a space complexity of O(wordLength).
    - Combining both, the overall space complexity is O(wordLength * targetLength).
 */
