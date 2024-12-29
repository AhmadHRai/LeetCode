class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int wordLength = words[0].size();
        int targetLength = target.size();
        const int MOD = 1000000007;

        // Step 1: Calculate frequency of each character at every index in "words".
        vector<vector<int>> charFrequency(wordLength, vector<int>(26, 0));
        for (const string& word : words) {
            for (int j = 0; j < wordLength; ++j) {
                charFrequency[j][word[j] - 'a']++;
            }
        }

        // Step 2: Initialize two DP arrays: prev and curr.
        vector<long> prevCount(targetLength + 1, 0);
        vector<long> currCount(targetLength + 1, 0);

        // Base case: There is one way to form an empty target string.
        prevCount[0] = 1;

        // Step 3: Fill the DP arrays.
        for (int currWord = 1; currWord <= wordLength; ++currWord) {
            // Copy the previous row into the current row for DP.
            currCount = prevCount;
            for (int currTarget = 1; currTarget <= targetLength; ++currTarget) {
                // If characters match, add the number of ways.
                int curPos = target[currTarget - 1] - 'a';
                currCount[currTarget] += (charFrequency[currWord - 1][curPos] *
                                          prevCount[currTarget - 1]) %
                                         MOD;
                currCount[currTarget] %= MOD;
            }
            // Move current row to previous row for the next iteration.
            prevCount = currCount;
        }

        // Step 4: The result is in prev[targetLength].
        return currCount[targetLength];
    }
};

 /*
    Approach: Optimized Bottom-up Dynamic Programming
    
    In this approach, we optimize the dynamic programming solution from a 2D DP table to a 1D array, reducing
    space complexity. The key observation is that the value of dp[currWord][currTarget] depends only on
    dp[currWord-1][currTarget] and dp[currWord-1][currTarget-1]. Using this observation, we maintain two 
    1D arrays (`prevCount` and `currCount`) instead of a 2D DP table.

    The algorithm works as follows:
    1. Calculate the frequency of each character at every index in the `words` matrix.
    2. Initialize two 1D DP arrays: `prevCount` (to store the previous row) and `currCount` (to store the current row).
    3. For each word and each target character, update the `currCount` based on previous values and character frequencies.
    4. Return the result stored in `currCount[targetLength]`, which gives the number of ways to form the target string.

    Time Complexity:
    - The time complexity is O(wordLength * targetLength + wordLength * totalWords).
    - O(wordLength * totalWords) to calculate the frequency of characters.
    - O(wordLength * targetLength) to fill the `prevCount` and `currCount` arrays.

    Space Complexity:
    - The space complexity is O(wordLength * targetLength).
    - The `prevCount` and `currCount` arrays each take O(targetLength) space.
    - The `charFrequency` matrix takes O(wordLength * 26) space.
    - Overall space complexity is O(wordLength * targetLength).
*/