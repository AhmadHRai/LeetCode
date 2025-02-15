#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // Helper function to check if it's possible to partition the square number into a valid sum.
    bool valid(int root, int p) {
        string s = to_string(p);

        // Lambda function to check the validity of the partition
        auto go = [&](auto&& go, int i, int sum, int curr) -> bool {
            // If we've processed all digits in the string
            if(i >= s.size()) {
                return sum == root; // Return true if sum matches the root number
            }

            int x = s[i] - '0';  // Get the current digit

            // Try both possibilities:
            // 1. Add the digit to the current number
            // 2. Start a new number with the current digit
            return go(go, i + 1, sum - curr + 10 * curr + x, 10 * curr + x) || 
                   go(go, i + 1, sum + x, x);
        };

        return go(go, 0, 0, 0);  // Start the recursion
    }

    // Array to store the cumulative punishment values
    int punishment[1001];

    // Initialization function to precompute the punishment values for all numbers from 1 to 1000
    Solution() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        // Calculate punishment values for all numbers from 1 to 1000
        for(int i = 1; i <= 1000; i++) {
            int square = i * i;
            if(valid(i, square)) {
                punishment[i] = square;  // If valid, store the square as punishment
            } else {
                punishment[i] = 0;  // Otherwise, no punishment
            }
        }

        // Compute the cumulative punishment sum for each number from 1 to 1000
        for(int i = 1; i <= 1000; i++) {
            punishment[i] += punishment[i - 1];
        }
    }

    // Function to return the punishment number for a given n
    int punishmentNumber(int n) {
        return punishment[n];
    }
};


/* 
Approach Summary:
    This solution precomputes the punishment values for all numbers from 1 to 1000 by checking if each square can be partitioned into a sum equal to the number itself. It uses a recursive lambda function to explore all possible partitions and stores the cumulative sum of punishments for efficient lookup.

Complexity Analysis:
    Time Complexity:

        Initialization: O(N), where N is the number of elements (up to 1000).

        punishmentNumber: O(1), because it simply looks up a precomputed value.

    Space Complexity: O(N), for storing the precomputed punishment values.
*/