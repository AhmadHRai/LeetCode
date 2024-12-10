class Solution {
public:
    // Function to find the maximum length of a substring that appears at least 3 times
    int maximumLength(string s) {
        // Create a map to store the count of all substrings
        map<string, int> count;
        
        // Iterate through each starting point of substrings
        for (int start = 0; start < s.length(); start++) {
            string currString;
            
            // Iterate through each ending point of substrings starting at 'start'
            for (int end = start; end < s.length(); end++) {
                // If the substring is empty or the current character is the same as the last added one
                // we add it to the map. Otherwise, we break out of the loop
                if (currString.empty() || currString.back() == s[end]) {
                    currString.push_back(s[end]);
                    count[currString]++;
                } else {
                    break;
                }
            }
        }
    
        // Variable to store the length of the longest valid substring with frequency at least 3
        int ans = 0;
        
        // Iterate over the map to find the longest substring with a count >= 3
        for (auto i : count) {
            string str = i.first;
            if (i.second >= 3 && str.length() > ans) {
                ans = str.length();  // Update the answer if a longer valid substring is found
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
- This solution uses a brute force approach to generate all possible substrings of the input string `s`.
- For each substring, it checks if the substring can be extended by matching the current character with the last one, and it stores its frequency in a map.
- After processing all substrings, it finds the longest substring that appears at least 3 times.

    This is a brute force approach as it generates all substrings and checks their frequencies. A more efficient solution could avoid generating all substrings explicitly.

Complexity Analysis:
- Time Complexity: O(n^3), where n is the length of the string `s`. The algorithm generates all substrings using two nested loops, and for each substring, it updates its frequency in the map, which takes O(n) time.
- Space Complexity: O(n^2), due to the space used by the map to store all possible substrings and the space used by the temporary string `currString` to hold each substring.

*/
