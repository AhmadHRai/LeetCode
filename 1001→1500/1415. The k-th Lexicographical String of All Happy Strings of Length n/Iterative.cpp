class Solution {
    public:
        string getHappyString(int n, int k) {
            int total = 3 * (1 << (n - 1));
    
            if (k > total)
                return "";
    
            string result(n, 'a');
    
            unordered_map<char, char> nextSmallest = {
                {'a', 'b'}, {'b', 'a'}, {'c', 'a'}};
            unordered_map<char, char> nextGreatest = {
                {'a', 'c'}, {'b', 'c'}, {'c', 'b'}};
    
            int startA = 1;
            int startB = startA + (1 << (n - 1));
            int startC = startB + (1 << (n - 1));
    
            if (k < startB) {
                result[0] = 'a';
                k -= startA;
            } else if (k < startC) {
                result[0] = 'b';
                k -= startB;
            } else {
                result[0] = 'c';
                k -= startC;
            }
    
            for (int charIndex = 1; charIndex < n; charIndex++) {
                // Calculate the midpoint of the group for the current character
                // position
                int midpoint = (1 << (n - charIndex - 1));
    
                // Determine the next character based on the value of k
                if (k < midpoint) {
                    result[charIndex] = nextSmallest[result[charIndex - 1]];
                } else {
                    result[charIndex] = nextGreatest[result[charIndex - 1]];
                    k -= midpoint;
                }
            }
    
            return result;
        }
    };

/* 
Approach Summary:
    This solution constructs the k-th lexicographically smallest happy string of length n by iteratively determining each character based on the value of k. It uses maps 
    to find the next smallest and greatest character for each position.

Complexity Analysis:
    Time Complexity: O(N), where N is the length of the string, because each character is determined once.
    Space Complexity: O(N), for storing the result string.
*/