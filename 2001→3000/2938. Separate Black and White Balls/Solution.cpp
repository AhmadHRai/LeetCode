#include <string>
using namespace std;

class Solution {
public:
    long long minimumSteps(string s) {
        int white = 0;           // Counter for the number of '1's encountered
        long long res = 0;       // Store the total minimum steps required
        int n = s.length();      // Length of the input string
        
        // Traverse the string character by character
        for (int j = 0; j < n; ++j) {
            if (s[j] == '0') {
                res += white;    // If current character is '0', add the count of '1's to result
            } else if (s[j] == '1') {
                white++;         // Increment '1' count for each occurrence of '1'
            }
        }
        
        return res;              // Return the accumulated result
    }
};

/*
Approach:
1. Traverse Through Each Character:
   - Iterate through the string `s`, counting occurrences of '1's encountered so far in `white`.
   - For each '0' encountered, add the current count of `white` to the result `res`, as this represents the number of steps required to move each '1' before this '0' to its left.

2. Maintain Running Totals:
   - By accumulating the count of '1's encountered before each '0' in `res`, we obtain the minimum number of swaps required to move all '1's to the right of '0's.

Complexity Analysis:
- Time Complexity: O(n), where `n` is the length of the string `s`, since we traverse each character once.
- Space Complexity: O(1), as only a few variables are used for counting and accumulation.
*/
