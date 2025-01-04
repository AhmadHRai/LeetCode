class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first = vector(26, -1);
        vector<int> last = vector(26, -1);
        
        for (int i = 0; i < s.size(); i++) {
            int curr = s[i] - 'a';
            if (first[curr] == - 1) {
                first[curr] = i;
            }
            
            last[curr] = i;
        }
        
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (first[i] == -1) {
                continue;
            }
            
            unordered_set<char> between;
            for (int j = first[i] + 1; j < last[i]; j++) {
                between.insert(s[j]);
            }
            
            ans += between.size();
        }
        
        return ans;
    }
};

/* 
Intuition

We can slightly optimize the previous approach by pre-computing the indices i and j for each letter.

In the first approach, it costs O(n) to calculate i and j. While this does not affect the time complexity, it does add a large constant factor to our runtime. In this approach, we will spend O(n) once, then be able to retrieve i and j for every letter in O(1).

Let first be an array of length 26, where first[c] represents the first index the character c appears in s. Similarly, let last be an array of length 26, where last[c] represents the last index the character c appears in s. Because we need integer indices, we will map each character to its position in the alphabet.

    'a' = 0.
    'b' = 1.
    ...
    'z' = 25.

We will calculate the arrays first and last prior to calculating the answer. To indicate if a letter appears in s at all, we will initialize first to have values of -1, which would be overridden if a letter appears in s.

    To calculate first and last, we use a similar process from the previous approach. We iterate over s and for each s[i], if first[s[i]] = -1, we set first[s[i]] = i. We always set last[s[i]] = i.

Once we have first and last, we can iterate over each position in the alphabet i. We first check if this character appears in s at all, which we can do by checking if first[i] = -1. If i appears in s, we reference first[i] and last[i] to get the first and last indices.

We then perform the same process from the previous approach - declare a hash set between, iterate between the first and last indices, add each character to between, and finally add the length of between to our answer.

We repeat this process for each position i in the alphabet from 0 until 26.

Algorithm

    Initialize first and last as arrays of length 26 with values -1.
    Iterate i over the indices of s:
        Calculate the current alphabet position as curr = s[i] - 'a'.
        If first[curr] = -1, set first[curr] = i.
        Set last[curr] = i.
    Initialize ans = 0.
    Iterate over each alphabet position i from 0 until 26:
        If first[i] = -1, continue to the next iteration.
        Initialize a hash set between.
        Iterate j over the indices between first[i] and last[i]:
            Add s[j] to between.
        Add the length of between to ans.
    Return ans.

Complexity Analysis

Given n as the length of s,

    Time complexity: O(n)

    First, we calculate first and last by iterating over s, which costs O(n).

    Next, we iterate over 26 alphabet positions. At each iteration, we iterate j over some indices, which in the worst-case scenario would cost O(n). Overall, each of the 26 iterations cost O(n), giving us a time complexity of O(26n)=O(n).

    Space complexity: O(1)

    first, last, and between all use constant space since s only contains letters in the English alphabet.

 */