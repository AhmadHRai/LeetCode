class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> letters;
        for (char c : s) {
            letters.insert(c);
        }
        
        int ans = 0;
        for (char letter : letters) {
            int i = -1;
            int j = 0;
            
            for (int k = 0; k < s.size(); k++) {
                if (s[k] == letter) {
                    if (i == -1) {
                        i = k;
                    }
                    
                    j = k;
                }
            }
            
            unordered_set<char> between;
            for (int k = i + 1; k < j; k++) {
                between.insert(s[k]);
            }
            
            ans += between.size();
        }
        
        return ans;
    }
};

/* 
Intuition

There is only one possible form a palindrome with length 3 can take. The first and last character must be the same, and the character in the middle can be anything (including the same character as the first/last character).

The important thing to notice here is that the first and last characters must be the same. To solve this problem, we can focus on each letter of the alphabet letter and treat it as the first and last character. Then, we find how many characters we can put in between them to form a palindrome.

There may be many occurrences of a given letter in s. Which ones should we choose? We should choose the first occurrence of letter in s to be the first character in our palindrome, and the last occurrence of letter in s to be the last character in our palindrome. Why?

The problem wants us to find subsequences - so when we look for a character to put as the middle character in the palindrome, this character must also be in between our two occurrences in s. Thus, by choosing the first and last occurrence, we are maximizing the number of characters in between, and thus maximizing the number of potential palindromes we could form.

For each unique letter in s, we find i as the first index where letter occurs and j as the final index where letter occurs. Next, we look at all the characters between indices i and j (the range of [i + 1, j - 1]) and count how many unique letters there are. Each of these unique letters can form a palindrome by being between two letter.

 We will use a hash set since hash sets do not record duplicates. We iterate over each index k between i and j and add s[k] to our hash set between. Once finished, we can add the size of between to our answer. We repeat this process for every unique letter that appears in s. We can also use a hash set to find all the unique letters that appear in s.

Algorithm

    Create letters, a hash set of all letters in s.
    Initialize ans = 0.
    Iterate over each letter in letters:
        Calculate i as the first index in which letter appears in s and j as the final index in which letter appears in s:
            Initialize i = -1 and j = 0. Iterate over each index k in s. If s[k] = letter, set i = k if i = -1, and set j = k.
        Initialize a hash set between.
        Iterate k over the indices between i and j:
            Add s[k] to between.
        Add the length of between to ans.
    Return ans.

Complexity Analysis

Given n as the length of s,

    Time complexity: O(n)

    To create letters, we use O(n) time to iterate over s.

    Next, we iterate over each letter in letters. Because s only contains lowercase letters of the English alphabet, there will be no more than 26 iterations.

    At each iteration, we iterate over s to find i and j, which costs O(n). Next, we iterate between i and j, which could cost O(n) in the worst-case scenario.

    Overall, each iteration costs O(n). This gives us a time complexity of O(26n)=O(n)

    Space complexity: O(1)

    letters and between cannot grow beyond a size of 26, since s only contains letters of the English alphabet.


 */