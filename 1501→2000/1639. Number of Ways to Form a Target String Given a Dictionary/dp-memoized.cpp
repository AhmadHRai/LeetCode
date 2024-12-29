class Solution {
public:
    int numWays(vector<string>& words, string target) {
        vector<vector<int>> dp(words[0].size(), vector<int>(target.size(), -1));
        vector<vector<int>> charFrequency(words[0].size(), vector<int>(26, 0));

        // Store the frequency of every character at every index.
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[0].size(); j++) {
                int character = words[i][j] - 'a';
                charFrequency[j][character]++;
            }
        }
        return getWords(words, target, 0, 0, dp, charFrequency);
    }

private:
    long getWords(vector<string>& words, string& target, int wordsIndex,
                  int targetIndex, vector<vector<int>>& dp,
                  vector<vector<int>>& charFrequency) {
        if (targetIndex == target.size()) return 1;  // Base case: all characters of target matched
        if (wordsIndex == words[0].size() ||
            words[0].size() - wordsIndex < target.size() - targetIndex)
            return 0;  // Base case: no more characters to match

        if (dp[wordsIndex][targetIndex] != -1)
            return dp[wordsIndex][targetIndex];  // Return the memoized result

        long countWays = 0;
        int curPos = target[targetIndex] - 'a';
        
        // Option 1: Skip current word, continue with the same targetIndex
        countWays += getWords(words, target, wordsIndex + 1, targetIndex, dp, charFrequency);

        // Option 2: Match the current character of target with a character at words[wordsIndex]
        countWays += charFrequency[wordsIndex][curPos] *
                     getWords(words, target, wordsIndex + 1, targetIndex + 1, dp, charFrequency);

        return dp[wordsIndex][targetIndex] = countWays % 1000000007;  // Store result in dp table
    }
};

/*
Approach

    The problem is solved using a top-down dynamic programming approach, where we recursively calculate the number of ways to match the target string using the words matrix.
    - We use a recursive function to explore two options at each step:
      1. Skip the current word and proceed to the next word.
      2. Match the current target character with the character from the current word and move both indices forward.
    - Memoization is used to store intermediate results in the dp table to avoid redundant calculations, reducing time complexity.

Complexity

    Time Complexity: O(wordLength * targetLength + wordLength * totalWords)
    - The first part (O(wordLength * totalWords)) represents the time spent on constructing the character frequency matrix.
    - The second part (O(wordLength * targetLength)) is the time complexity of the recursive function with memoization, where each state is visited only once.

    Space Complexity: O(wordLength * targetLength)
    - The space complexity is primarily determined by the memoization table (dp) and the character frequency matrix (charFrequency).
    - The dp table has dimensions of wordLength x targetLength, and the charFrequency matrix has dimensions of wordLength x 26 (for each character), resulting in a combined space complexity of O(wordLength * targetLength).
 */
