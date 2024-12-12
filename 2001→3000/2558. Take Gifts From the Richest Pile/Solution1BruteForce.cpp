// Brute Force Approach
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n = gifts.size();  // Get the size of the 'gifts' array

        // Perform the operation k times
        for (int i = 0; i < k; i++) {
            // Initialize the index of the richest pile (maximum element)
            int richestPileIndex = 0;

            // Iterate through the array to find the index of the maximum element
            for (int currentPileIndex = 0; currentPileIndex < n; currentPileIndex++) {
                // If we find a new maximum, update the index
                if (gifts[richestPileIndex] < gifts[currentPileIndex]) {
                    richestPileIndex = currentPileIndex;
                }
            }

            // Replace the richest pile with the floor of its square root
            gifts[richestPileIndex] = sqrt(gifts[richestPileIndex]);
        }

        // Calculate the sum of the remaining gifts in the array
        long long int numberOfRemainingGifts = accumulate(gifts.begin(), gifts.end(), 0LL);

        return numberOfRemainingGifts;
    }
};

/*
Approach:
1. The algorithm iterates `k` times, where in each iteration, it identifies the index of the richest pile (the maximum element in the `gifts` array).
2. Once the maximum element is found, its value is updated to the floor of its square root.
3. After performing the operation `k` times, the function calculates and returns the sum of the remaining gifts in the array.

Complexity Analysis:
- Time Complexity: O(k * n), where `n` is the size of the `gifts` array and `k` is the number of iterations. In each iteration, we scan the entire array (`O(n)`) to find the richest pile.
- Space Complexity: O(1), as the algorithm only uses a few extra variables (e.g., `richestPileIndex`) and operates directly on the `gifts` array.
*/
