class Solution {
public:
    string compressedString(string word) {
        int n = word.length(), count = 0, i = 0, j = 0;
        string ans = "";
        while(j < n) {
            count = 0;
            // Count consecutive characters up to a maximum of 9
            while(j < n && word[i] == word[j] && count < 9) {
                j++;
                count++;
            }
            // Append the count and the character to the result string
            ans += to_string(count) + word[i];
            // Move the starting pointer to the current position
            i = j;
        }
        return ans;
    }
};

/* 
Explanation of Key Parts

    Counting Consecutive Characters: The while loop with count < 9 ensures that each compressed segment is limited to 9 characters. This prevents cases like aaaaaaaaaa (10 'a's) from becoming 10a (instead, it will appear as 9a1a).

    Appending the Result: For each segment, the count and character are added to ans. After processing a segment, the i pointer is moved to match j, marking the start of a new segment.

Complexity Analysis

    Time Complexity: O(n), where nn is the length of word. The loop iterates through each character once.
    Space Complexity: O(n), to store the result string ans.
 */