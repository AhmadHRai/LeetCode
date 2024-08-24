class Solution {
public:
    // Function to find the nearest palindrome to the given number as a string
    string nearestPalindromic(string n) {
        // Special case: if the number has only one digit, return the previous digit
        if (n.length() == 1) return to_string(stoi(n) - 1);

        int digits = n.length(); // Get the number of digits in the number
        vector<long> candidates; // Vector to store potential palindrome candidates
        
        // Case 1: Palindrome with all 9s (e.g., 999 for 1000)
        candidates.push_back(pow(10, digits - 1) - 1);
        // Case 2: Palindrome with a leading 1 and trailing 1 (e.g., 1001 for 999)
        candidates.push_back(pow(10, digits) + 1);
        
        int mid = (digits + 1) / 2; // Calculate the middle index for creating palindromes
        long prefix = stol(n.substr(0, mid)); // Extract the prefix of the number
        
        // Case 3: Generate palindromes by modifying the prefix
        vector<long> v = {prefix, prefix + 1, prefix - 1};
        for (long i : v) {
            string postfix = to_string(i);
            if (digits % 2 != 0) postfix.pop_back(); // If the total length is odd, remove the middle digit
            reverse(postfix.begin(), postfix.end()); // Reverse the postfix to form a palindrome
            string c = to_string(i) + postfix; // Form the complete palindrome
            candidates.push_back(stol(c)); // Add the palindrome to candidates
        }
        
        long mindiff = LONG_MAX; // Initialize the minimum difference to a large value
        long result; // Variable to store the result
        long num = stol(n); // Convert the input number to long for comparison
        
        // Evaluate each candidate and select the nearest one
        for (int i = 0; i < candidates.size(); i++) {
            if (candidates[i] != num && abs(candidates[i] - num) < mindiff) { // Exclude the original number and check for minimum difference
                mindiff = abs(candidates[i] - num);
                result = candidates[i];
            } else if (abs(candidates[i] - num) == mindiff) { // If the difference is the same, choose the smaller number
                result = min(result, candidates[i]);
            }
        }
        
        return to_string(result); // Return the result as a string
    }
};

/*
Approach Summary:
- Handle the special case of single-digit numbers separately.
- Generate potential palindromes by:
  - Creating palindromes with all digits as 9 (e.g., 999 for 1000).
  - Creating palindromes with a leading 1 and trailing 1 (e.g., 1001 for 999).
  - Modifying the prefix of the input number to generate other possible palindromes.
- Compare all generated palindromes to find the one with the smallest difference from the input number, excluding the input number itself.

Time Complexity:
- O(n), where n is the number of digits in the input number. The operations performed are linear with respect to the length of the number.

Space Complexity:
- O(n), where n is the number of digits in the input number. This space is used for storing the palindrome candidates and intermediate strings.
*/
