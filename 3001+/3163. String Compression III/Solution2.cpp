class Solution {
public:
    string compressedString(string word) {
        string temp;
        char last = word[0]; // Store the first character as the initial `last`
        int cnt = 1; // Start counting the first character
        
        for (int i = 1; i < word.size(); i++) {
            if (last == word[i]) { 
                if (cnt < 9) { 
                    ++cnt; // Increment count if under the limit of 9
                    continue;
                } else { 
                    // If count reaches 9, append to result and reset
                    temp.push_back(cnt + '0');
                    temp.push_back(last);
                    cnt = 1;
                }
            } else {
                // Append count and character when switching to a new character
                temp.push_back(cnt + '0');
                temp.push_back(last);
                cnt = 1;
                last = word[i];
            }
        }
        
        // Append the last counted character and its count
        temp.push_back(cnt + '0');
        temp.push_back(last);
        
        return temp;
    }
};

/* 
Key Parts of the Solution

    Tracking Consecutive Characters:
        The variable last keeps track of the current character being counted.
        cnt increments as long as consecutive characters match, resetting to 1 when encountering a different character.
        When cnt reaches 9, the current count and character are appended to temp.

    Appending Counts and Characters:
        When a different character is encountered or the count limit is reached, the current count and character are appended to temp.
        Finally, the last character group is appended outside the loop.

Complexity Analysis

    Time Complexity: O(n), where nn is the length of word, as each character is processed once.
    Space Complexity: O(n), as the resulting compressed string temp could be up to the length of the original word.
 */