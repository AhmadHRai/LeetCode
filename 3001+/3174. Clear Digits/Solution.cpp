class Solution {
    public:
        string clearDigits(string s) {
            // This variable keeps track of the actual length of the resulting
            // string
            int answerLength = 0;
    
            // Iterate through each character in the input string
            for (int charIndex = 0; charIndex < s.size(); charIndex++) {
                // If the current character is a digit
                if (isdigit(s[charIndex])) {
                    // Decrement answerLength to remove the last character from the
                    // result
                    answerLength = max(answerLength - 1, 0);
                } else {
                    // Place the character in the "answer" portion of the string
                    s[answerLength++] = s[charIndex];
                }
            }
    
            // Resize the string to match the actual length of the answer
            s.resize(answerLength);
    
            return s;
        }
    };

/* 
Algorithm

    Initialize answerLength to 0.
    Iterate over s with charIndex from 0 to s.length - 1:
        If the character at charIndex is a digit:
            Decrement answerLength by 1.
        Otherwise, if the character at charIndex is not a digit:
            Add it to the end of the answer, by setting s[answerLength] = s[charIndex].
            Increment answerLength.
    Return the first answerLength characters of the modified string s.

Complexity Analysis
    Let n be the length of the string s.

    Time Complexity: O(n).

        Like in the previous approach, we iterate over all characters in s and perform constant-time operations, including checks and retrievals of characters in a 
        string. Additionally, the "resize" operation on the string requires O(n) time and therefore the total time complexity of the algorithm is O(n).

    Space Complexity: O(1).

        As the input string does not count as auxiliary space, the C++ implementation requires only constant extra space for the variables answerLength and charIndex.

        However, the Java and Python implementations require additional structures (such as a list or a charArray), as they do not provide mutable strings. Since these 
        structures are neither part of the input nor the output of the algorithm, they contribute to its auxiliary space complexity, which is O(n).

*/