class Solution {
public:
    int maxScore(string s) {
        int ones = 0;
        int zeros = 0;
        int best = INT_MIN;

        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '1') {
                ones++;
            } else {
                zeros++;
            }
            
            best = max(best, zeros - ones);
        }
        
        if (s[s.size() - 1] == '1') {
            ones++;
        }
        
        return best + ones;
    }
};

/* 
Intuition

In the previous approach (Count Left Zeros and Right Ones), we used two passes over the input string: once to calculate ones, and another time to calculate ans. We can further optimize the algorithm to only use one pass!

The answer to our problem is the maximum score for all valid splits, as represented by the following equation:

score=ZL​+OR​, where ZL​ is the number of zeros in the left substring and OR​ is the number of ones in the right substring.

We can express OR​ as OT​−OL​, where OT​ is the total number of ones in s, and OL​ is the number of ones in the left substring.

Using the above expression, our first equation can be represented as:

score=ZL​+OT​−OL​

In the above equation, OT​ is a constant, we need to find the maximum value of ZL​−OL​ for all valid splits. Notice that both of these values depend solely on the left substring. Therefore, we don't need to consider the right substring, which saves the need for the first traversal in the previous solution.

In the code, we will use the variable zeros to represent ZL​ and the variables ones to represent OL​. As zeros - ones may be negative, we initialize an integer best to a very small value, like negative infinity. Here, best represents the largest value of zeros - ones we have seen so far.

We now iterate i in the same manner as the first two approaches: at each iteration, i represents the final index of the left part. On each iteration, we are adding s[i] to the left part. Thus, if s[i] = '1' we increment ones, otherwise s[i] = '0' and we increment zeros. Then, we update best with zeros - ones if it is larger.

Recall that we don't iterate i over the final index since it would mean having an empty right part. Once we are done iterating over s, we will check the final index to see if it is a 1. If it is, we increment ones.

The reason we explicitly check the final index for 1 is that we want ones to represent OT​ in the end, but when we calculate ones, we don't iterate over the last index, so we need to account for it. Now, we have best as the maximum of all ZL​−OL​ and ones represents OT​, we can return best + ones as the answer.

Algorithm

    Initialize ones = 0, zeros = 0, and best to a very small value like negative infinity.
    Iterate i from 0 until s.length - 1:
        If s[i] == '1', increment ones.
        Otherwise, increment zeros.
        Update best with zeros - ones if it is larger.
    If the final character of s is equal to '1', increment ones.
    Return best + ones.

Complexity Analysis

Given n as the length of nums,

    Time complexity: O(n)

    We make one pass over nums, performing O(1) work at each iteration.

    Space complexity: O(1)

    We aren't using any extra space other than a few integers.

 */