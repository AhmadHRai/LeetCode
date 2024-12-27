class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxLeftScore = values[0]; // Initialize the best left score with the first value
        int maxScore = 0; // Variable to store the maximum score

        for (int i = 1; i < values.size(); i++) {
            int currentRightScore = values[i] - i; // Right score for the current sightseeing pair
            maxScore = max(maxScore, maxLeftScore + currentRightScore); // Update max score

            int currentLeftScore = values[i] + i; // Left score for the current sightseeing pair
            maxLeftScore = max(maxLeftScore, currentLeftScore); // Update max left score
        }

        return maxScore; // Return the maximum score
    }
};

/*
- Intuition:
    In the dynamic programming approach, we used an array to store the best left scores up to each index.
    However, since each index only depends on the previous one, the array is unnecessary.
    We can replace it with a single variable (`maxLeftScore`) to store the best left score so far, saving memory.

- Algorithm:
    1. Initialize `maxLeftScore` to `values[0]`, representing the best left score at the start.
    2. Initialize `maxScore` to `0`, which will store the maximum sightseeing pair score.
    3. Iterate through the array from index `1` to `n - 1`:
        - Compute the current right score as `values[i] - i`.
        - Update `maxScore` using the best left score so far and the current right score.
        - Compute the current left score as `values[i] + i`.
        - Update `maxLeftScore` to be the maximum of itself and the current left score.
    4. Return `maxScore`, which contains the maximum sightseeing pair score.

- Complexity:
    Time Complexity: O(n)
        - We loop through the array once, performing constant-time operations at each step.
    Space Complexity: O(1)
        - The algorithm uses a fixed number of variables, requiring constant extra space.

- Comparison:
    - This approach is a space-optimized version of the previous one.
    - It achieves the same time complexity (O(n)) while reducing space usage from O(n) to O(1).
*/
