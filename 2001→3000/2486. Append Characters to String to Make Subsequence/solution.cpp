/**
 * Calculates the minimum number of characters needed to append to string t
 * to transform it into string s, while maintaining the order of characters.
 *
 * @param s A string representing the target string.
 * @param t A string representing the original string.
 * @return The minimum number of characters to append to t to make it equal to s.
 */
class Solution {
public:
    int appendCharacters(string s, string t) {
        int s_index = 0, t_index = 0;
        int s_length = s.length(), t_length = t.length();
        
        // Iterate through both strings with two pointers to find the longest common subsequence.
        while (s_index < s_length && t_index < t_length) {
            // If characters match, move to the next character in t
            if (s[s_index] == t[t_index]) {
                t_index++;
            }
            // Always move to the next character in s
            s_index++;
        }
    
        // Return the number of characters needed to append to t to make it equal to s
        return t_length - t_index;
    }
};

/*
Approach:
    We use two pointers to iterate through strings s and t simultaneously. 
    The goal is to find the longest subsequence in t that matches s.
    By the end of the iteration, the number of characters remaining in t (t_length - t_index)
    represents the minimum number of characters needed to append to t to transform it into s.

Complexity Analysis:
    - Time Complexity: O(max(m, n))
      where m is the length of string s and n is the length of string t. The function iterates
      through both strings once, making the time complexity linear relative to the longer string.
      
    - Space Complexity: O(1)
      The function uses only a constant amount of extra space for variables, regardless of input size.
*/

