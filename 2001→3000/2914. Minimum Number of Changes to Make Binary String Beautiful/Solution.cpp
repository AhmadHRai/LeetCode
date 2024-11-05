class Solution {
public:
    // Function to calculate the minimum number of changes required
    // to make the string alternating (characters at even and odd positions are different)
    int minChanges(string &s) {
        // Get the length of the string
        const int n = s.size();

        // Initialize the count of changes required to 0
        int count = 0;

        // Loop through the string with step size 2 (to compare consecutive pairs)
        for (int i = 0; i < n; i += 2) {
            // If the current character and the next character are not equal, increment the count
            count += (s[i] != s[i + 1]);
        }

        // Return the total count of changes required
        return count;
    }
};

/*
// One liner
int minChanges(string& s) {
    return accumulate(s.begin(), s.end(), 0, [&, i=-1](int sum, auto _) mutable{
        return sum+=((++i&1))?(s[i]!=s[i-1]):0;
    });
}

class Solution {
public:
    // reading 16-bit data 2 chars once
    int minChanges(string& s) {
        const int n=s.size();
        uint16_t* t=(uint16_t*) s.data();
        int cnt=0;
        for(int i=0; i<n/2; i++)
            cnt+=(1&((t[i]>>8)^t[i]));
        return cnt;
    }
};
*/

/*
Approach Summary:
- The problem requires us to transform the input string into a pattern where characters at even and odd positions are different.
- To do this, we iterate through the string in steps of 2 (i.e., comparing pairs of consecutive characters at even positions and their succeeding odd positions).
- For each pair, if the characters are not equal, we increment the change counter.
- At the end of the loop, the value of the counter is the number of changes needed to make the string alternating.

Complexity Analysis:
- Time Complexity: O(n), where n is the length of the string. We iterate through the string in steps of 2, so the loop runs n/2 times, which still results in O(n) time complexity.
- Space Complexity: O(1), since we only use a constant amount of extra space (variables `count`, `n`, and `i`).
*/
