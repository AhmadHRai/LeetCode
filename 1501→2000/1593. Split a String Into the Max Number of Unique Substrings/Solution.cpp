class Solution {
public:
    // Function to find the maximum number of unique splits in the string
    int maxUniqueSplit(string s) {
        unordered_set<string> seen; // Set to track unique substrings
        return backtrack(0, s, seen); // Start backtracking from index 0
    }

private:
    // Backtracking function to explore all possible splits
    int backtrack(int start, const string& s, unordered_set<string>& seen) {
        // Base case: If we've reached the end of the string
        if (start == s.size()) {
            return 0; // No more splits possible
        }
        
        int maxSplits = 0; // Variable to track the maximum splits found

        // Explore all possible end indices for the current substring
        for (int end = start + 1; end <= s.size(); ++end) {
            string substring = s.substr(start, end - start); // Extract the substring

            // Check if the substring is unique (not seen before)
            if (seen.find(substring) == seen.end()) {
                seen.insert(substring); // Mark substring as seen
                
                // Recursively backtrack and calculate splits for the remaining string
                maxSplits = max(maxSplits, 1 + backtrack(end, s, seen));
                
                seen.erase(substring); // Backtrack: unmark the substring
            }
        }

        return maxSplits; // Return the maximum number of splits found
    }
};

/* 
Explanation:

    maxUniqueSplit function: This is the main function that initializes the process. It uses an unordered set to keep track of the substrings that have been seen.

    backtrack function: This is a recursive function that explores all possible ways to split the string into unique substrings.
        Base Case: When the starting index equals the string length, it returns 0, indicating no further splits can be made.
        For Loop: It generates substrings by iterating through potential ending indices, checking if they are unique and using recursion to explore further splits.
        Backtracking: After exploring a path, it removes the substring from the set to allow other combinations to be checked.

Complexity Analysis:

    Time Complexity: The worst-case scenario can be exponential due to the exploration of all possible substrings.
    Space Complexity: O(n) in the worst case for the recursive stack and the unordered set holding the substrings.
 */