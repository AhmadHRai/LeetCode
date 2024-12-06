class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        // Create a set to store banned numbers for efficient lookup
        unordered_set<int> bannedSet(banned.begin(), banned.end());
        
        long long sum = 0; // Variable to track the cumulative sum of numbers considered
        int count = 0;     // Variable to track the count of valid numbers added to the sum

        // Iterate through numbers from 1 to n to find how many can be added without exceeding maxSum
        for (int i = 1; i <= n; i++) {
            if (bannedSet.count(i)) continue; // Skip the number if it is banned
            sum += i; // Add the current number to the cumulative sum
            if (sum > maxSum) break; // If the cumulative sum exceeds maxSum, stop
            count++; // Increment the count of valid numbers
        }

        return count; // Return the total number of valid numbers that can be added
    }
};

/*
Approach:
1. Use an unordered set to store the banned numbers for efficient checking. This ensures that we can quickly determine whether a number is banned.
2. Initialize two variables: `sum` to track the cumulative sum of valid numbers, and `count` to count the number of valid numbers added.
3. Iterate through all integers from 1 to n:
   - Skip any number that is in the banned set.
   - Add the current valid number to the sum and check if the sum exceeds `maxSum`.
   - Stop the iteration if the cumulative sum exceeds `maxSum`.
4. Return the count of valid numbers that can be added without exceeding the `maxSum`.

This solution uses an unordered set to efficiently check for banned numbers and uses a greedy approach to add valid numbers until the cumulative sum exceeds the maximum allowed sum.

Complexity Analysis:
- Time Complexity: O(n + m), where n is the size of the range (1 to n) and m is the size of the banned list. The time complexity is dominated by the iteration over the numbers 1 to n and the set operations, which are O(1) on average.
- Space Complexity: O(m), where m is the size of the banned list. The unordered set stores the banned numbers, which takes up space proportional to the number of banned elements.
*/
