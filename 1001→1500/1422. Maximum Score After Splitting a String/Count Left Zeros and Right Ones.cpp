class Solution {
public:
    int maxScore(string s) {
        int ones = count(s.begin(), s.end(), '1');
        
        int ans = 0;
        int zeros = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '1') {
                ones--;
            } else {
                zeros++;
            }
            
            ans = max(ans, zeros + ones);
        }
        
        return ans;
    }
};

/* 
We start by counting how many times 1 occurs in s. Let's store this value in a variable ones. We will also have a variable zeros that represents how many 0 are in the left part. Initially, our variables ones and zeros are set as if the left part is empty and the right part is the entire string.

Now, we iterate i in the same manner as the previous approach: each index i represents the final index of the left part. At each iteration i, we remove s[i] from the right part and add it to the left part.

example

There are two possibilities for each index i:

    If s[i] == '1': this 1 was in the right part, but it is now joining the left part. Thus, we lose 1 score since the right part is losing a 1. Decrement ones.
    If s[i] == '0', this 0 was in the right part, but it is now joining the left part. Thus, we gain 1 score since the left part is gaining a 0. Increment zeros.

We update the answer with zeros + ones at each iteration if it is larger.

Algorithm

    Initialize ones as the number of times 1 occurs in s.
    Initialize zeros = 0 and the answer ans = 0.
    Iterate i from 0 until s.length - 1:
        If s[i] == '1', decrement ones.
        Otherwise, increment zeros.
        Update ans with zeros + ones if it is larger.
    Return ans.

Complexity Analysis

Given n as the length of nums,

    Time complexity: O(n)

    We start by finding the frequency of 1, which costs O(n). Next, we iterate over the string once, performing O(1) work at each iteration. Thus, our time complexity is O(2n)=O(n).

    Space complexity: O(1)

    We aren't using any extra space other than a few integers.



 */