class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> partitions; // Store all valid partitions
        vector<string> currentPartition;   // Temporary storage for current partition
        partitionHelper(s, 0, currentPartition, partitions); // Start partitioning from index 0
        return partitions;
    }
    
private: 
    // Helper function for partitioning
    void partitionHelper(string& s, int start, vector<string>& currentPartition, vector<vector<string>>& partitions) {
        int n = s.length();
        // Base case: if the start index reaches the end of the string, we have found a valid partition
        if (start == n) {
            partitions.push_back(currentPartition); // Add the current partition to the list of partitions
        } else {
            // Iterate over all possible substrings starting from the current start index
            for (int i = start; i < n; i++) {
                // Check if the substring from start index to current index is a palindrome
                if (isPalindrome(s, start, i)) {
                    currentPartition.push_back(s.substr(start, i - start + 1)); // Add the palindrome substring to the current partition
                    partitionHelper(s, i + 1, currentPartition, partitions);    // Recur for the remaining string starting from i + 1
                    currentPartition.pop_back(); // Backtrack: remove the last added substring to explore other possibilities
                }
            }
        }
    }
    
    // Function to check if a substring is a palindrome
    bool isPalindrome(string& s, int left, int right) {
        // Iterate from both ends towards the middle
        while (left < right) {
            // If characters at left and right indices don't match, it's not a palindrome
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        // If the loop completes without returning false, the substring is a palindrome
        return true;
    }
};

/*
Explanation:

    This solution utilizes backtracking to generate all possible partitions of the given string s where each partition contains only palindromic substrings.
    The partition function serves as a wrapper function that initializes necessary variables and calls the recursive helper function partitionHelper to perform the actual 
    partitioning.
    
    In the partitionHelper function:
        We start with a base case: if the start index reaches the end of the string s, we have found a valid partition, so we add the current partition to the list of 
            partitions.
        Otherwise, we iterate over all possible substrings starting from the start index.
        For each substring, we check if it's a palindrome using the isPalindrome function. If it is, we add it to the current partition, recurse for the remaining string, 
            and backtrack by removing the last added substring to explore other possibilities.
    The isPalindrome function checks if a given substring of s is a palindrome by comparing characters from both ends towards the middle.

Complexity Analysis:
    Time Complexity:
        The time complexity of this solution depends on the number of partitions generated.
        In the worst case, if there are no palindromic substrings, the algorithm will generate all possible partitions, which is O(2^N), where NN is the length of the input string.
        However, due to backtracking, not all possible partitions are explored, resulting in a lower time complexity in practical cases.
        Checking if a substring is a palindrome takes O(N) time, where N is the length of the substring.

    Space Complexity:
        The space complexity is dominated by the recursion stack.
        In the worst case, the recursion stack can grow up to O(N), where NN is the length of the input string.
        Additionally, the space complexity includes the space used by the partitions vector, which can hold up to O(2^N) partitions.
        Overall, the space complexity is O(N⋅2^N).
*/