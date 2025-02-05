class Solution {
    public:
        bool areAlmostEqual(string s1, string s2) {
            int firstIndexDiff = 0;
            int secondIndexDiff = 0;
            int numDiffs = 0;
            for (int i = 0; i < s1.size(); i++) {
                if (s1[i] != s2[i]) {
                    numDiffs++;
                    // numDiffs is more than 2, one string swap will not make two
                    // strings equal
                    if (numDiffs > 2)
                        return false;
                    else if (numDiffs == 1) {
                        // store the index of first difference
                        firstIndexDiff = i;
                    } else {
                        // store the index of second difference
                        secondIndexDiff = i;
                    }
                }
            }
            // check if swap is possible
            return s1[firstIndexDiff] == s2[secondIndexDiff] &&
                   s1[secondIndexDiff] == s2[firstIndexDiff];
        }
    };

/* 
Algorithm

    Initialize firstIndexDiff, secondIndexDiff, and numDiffs all to 0.
    Iterate through the characters of s1 and s2:
        Let s1Char and s2Char be the current characters of s1 and s2 at index i, respectively.
        If s1Char != s2Char:
            Increment numDiffs.
            If numDiffs is now greater than 2, then we know one string swap will not make the strings equal, so return false.
            If numDiffs is now equal to 1, then we have found our first difference: assign firstIndexDiff = i.
            Otherwise, numDiffs is 2 so we have found our second difference: assign secondIndexDiff = i.
    Return s1[firstIndexDiff] == s2[secondIndexDiff] && s1[secondIndexDiff] == s2[firstIndexDiff]

Complexity Analysis

    Time Complexity: O(N)
        Iterating through s1 and s2 takes O(N) time. For each character we iterate, updating numDiffs, firstIndexDiff, secondIndexDiff takes O(1) constant time. Thus, the 
        total time complexity is O(N).

    Space Complexity: O(1)
        We only use 3 integer variables, so the space complexity is constant O(1).
*/