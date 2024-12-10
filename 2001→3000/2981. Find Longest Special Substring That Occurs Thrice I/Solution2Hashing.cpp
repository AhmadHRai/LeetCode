class Solution {
public:
    int maximumLength(string s) {
        // Create a map with a pair (character, length of substring) as the key to store the frequency of substrings
        map<pair<char, int>, int> count;
        int substringLength = 0;
        
        // Iterate through each starting point of substrings
        for (int start = 0; start < s.length(); start++) {
            char character = s[start];
            substringLength = 0;
            
            // Iterate through each ending point of substrings starting at 'start'
            for (int end = start; end < s.length(); end++) {
                // If the current character matches the previous character, extend the current substring
                // Otherwise, break out of the loop
                if (character == s[end]) {
                    substringLength++;
                    count[{character, substringLength}]++;  // Store the substring's frequency in the map
                } else {
                    break;  // Break the loop if characters are not the same
                }
            }
        }

        // Variable to store the length of the longest valid substring with frequency at least 3
        int ans = 0;
        
        // Iterate over the map to find the longest substring with a count >= 3
        for (auto i : count) {
            int len = i.first.second;
            if (i.second >= 3 && len > ans) {
                ans = len;  // Update the answer if a longer valid substring is found
            }
        }
        
        // If no valid substring with frequency >= 3 is found, return -1
        if (ans == 0) return -1;
        
        // Return the length of the longest valid substring
        return ans;
    }
};

/*
Approach Summary:
This solution uses hashing (via a map) to store the frequencies of substrings, providing a more efficient approach compared to the brute force solution, where all substrings were explicitly generated.
- This solution uses hashing to track substrings of repeated characters, compared to the brute force approach that explicitly generates all substrings.
- A map is used where the key is a pair of (character, substring length), and the value is the frequency of that substring.
- For each starting point in the string, we extend the substring as long as the characters match, updating the map with the frequency of each substring.
- The function then finds the longest substring that appears at least 3 times.

Complexity Analysis:
- Time Complexity: O(n^2), where n is the length of the string `s`. We iterate over all starting and ending points for substrings, and for each substring, we update the map (constant time for each substring update).
- Space Complexity: O(n^2), due to the space used by the map to store substrings and their frequencies. The number of possible substrings can be as large as \(n^2\), and each key in the map stores both the character and the substring length.

*/
