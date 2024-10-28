class Solution {
public:
    // Function to find the longest square streak in the given nums vector
    int longestSquareStreak(vector<int>& nums) {
        // Create a set to store unique numbers from nums for fast lookup
        unordered_set<int> inNums(nums.begin(), nums.end());
        int maxCount = -1; // Initialize the maximum count of the streak

        // Iterate through potential square roots starting from 2
        for (int i = 2; i * i <= 100000; ++i) {
            // Check if the current square root is in the set
            if (inNums.find(i) == inNums.end()) continue; // Skip if not found
            inNums.erase(i); // Remove the current square root from the set
            int count = 1; // Initialize the count of the current streak
            long long t = i * i; // Calculate the square of the current number

            // While the square value is within bounds and exists in the set
            while (t <= 100000 && inNums.find(t) != inNums.end()) {
                inNums.erase(t); // Remove the square from the set
                ++count; // Increment the count of the streak
                t *= t; // Calculate the next square (t^2)
            }

            // Update the maximum count if the current streak is greater than 1
            if (count > 1 && count > maxCount) maxCount = count; 
        }
        
        return maxCount; // Return the longest square streak found
    }
};

/*
Approach:

    The solution employs an unordered set to keep track of unique numbers from the input vector `nums`. 
    It iterates through potential square roots starting from 2, checking if the root exists in the set. 
    If found, it calculates the square and checks for further squares (i.e., `i^2, (i^2)^2, ...`) while they exist in the set. 
    The count of valid squares is maintained for each streak. The maximum count of squares found in any streak is tracked and returned.

Complexity:

    Time Complexity: O(n + k), where n is the size of the input vector and k is the number of potential square roots (bounded by 317 for the square root of 100,000). 
    Each number in `nums` is processed at most once due to the set's operations.
    
    Space Complexity: O(n) for storing the unique numbers in the unordered set.

This approach efficiently finds the longest streak of square numbers, leveraging set operations for quick lookups.
*/
