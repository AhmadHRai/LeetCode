class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {

        vector<int> maxScores(values.size()); // Array to store max left scores up to each index
        maxScores[0] = values[0]; // Initialize with the first value

        int res = 0; // Variable to store the maximum score
        for (int i = 1; i < values.size(); i++) {
            int currentR = values[i] - i; // Right score for the current sightseeing pair
            res = max(res, maxScores[i - 1] + currentR); // Update max score using best left score so far
            int currentL = values[i] + i; // Left score for the current sightseeing pair
            maxScores[i] = max(maxScores[i - 1], currentL); // Update max left score up to current index
        }

        return res; // Return the maximum score
    }
};

/*
- Intuition:
    Each element in the array `values` can contribute to a sightseeing pair score in two ways:
    1. As the left element: It adds `values[i] + i` to the score.
    2. As the right element: It adds `values[j] - j` to the score.

    To maximize the score, we need the best left score `values[i] + i` for every possible right score `values[j] - j`.
    Instead of recalculating left scores repeatedly, we can maintain the highest left score encountered so far.

- Algorithm:
    1. Initialize an array `maxScores` to keep track of the best left scores up to each index:
        - Set `maxScores[0]` to `values[0]` as the first left score is just the first value.
    2. Iterate through the array from index `1` to `n - 1`:
        - Compute the current right score for index `i` as `values[i] - i`.
        - Combine the best left score up to index `i-1` (`maxScores[i-1]`) with the current right score to update the maximum score.
        - Compute the current left score for index `i` as `values[i] + i`.
        - Update `maxScores[i]` with the maximum of `maxScores[i-1]` and the current left score.
    3. Return the maximum score after completing the iteration.

- Complexity:
    Time Complexity: O(n)
        - We iterate through the array once, performing constant-time operations at each step.
    Space Complexity: O(n)
        - We use an additional array `maxScores` of size `n` to store the left scores.
*/
