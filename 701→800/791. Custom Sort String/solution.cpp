#include <string>
#include <vector>

class Solution {
public:
    string customSortString(string order, string s) {
        // Create a vector to keep count of each character's occurrence in s
        vector<int> charCounts(26, 0);

        // Fill the vector with the counts of each character
        for (char& c : s) {
            charCounts[c - 'a']++;
        }

        // This string will store the result
        string sortedStr;

        // Iterate over the 'order' string and append the characters to 'sortedStr' in the order they appear
        for (char& c : order) {
            while (charCounts[c - 'a']-- > 0) {
                sortedStr += c;
            }
        }

        // Append characters that did not appear in 'order' to the end of 'sortedStr', in their original order
        for (int i = 0; i < 26; ++i) {
            // Check if the character is present in 's' and was not included via 'order'
            if (charCounts[i] > 0) {
                // Append the character (i + 'a') 'charCounts[i]' times to the 'sortedStr'
                sortedStr += string(charCounts[i], i + 'a');
            }
        }

        // Return the custom sorted string
        return sortedStr;
    }
};

/* 
Approach:
    uses a vector to count the occurrences of each character in the input string s, which allows for constant-time access to the count of any character. It then iterates over the order 
    string, appending characters to the result string in the order they appear in order. Finally, it appends any characters from s that are not in order to the end of the result string 
    in their original order. This approach ensures that the characters in s are sorted according to the custom order specified in order, while maintaining the relative order of 
    characters not present in order.

Complexity:
    Time Complexity:
        - The first loop that counts the occurrences of each character in s runs in O(n), where n is the length of s. This is because it iterates through each character in s once.
        - The second loop that iterates over the order string and appends characters to the result string runs in O(m), where m is the length of order. This is because it iterates 
            through each character in order once.
        - The final loop that appends characters not present in order to the end of the result string runs in O(26), as it iterates through each of the 26 possible lowercase English 
            letters once.
        Combining these, the overall time complexity of the solution is O(n + m + 26), which simplifies to O(n + m) because the constant factor (26) is dropped in Big O notation.

    Space Complexity:
        The space complexity is primarily determined by the charCounts vector, which has a size of 26 (one for each lowercase English letter). Therefore, the space complexity is O(1), 
        as the size of the vector does not depend on the size of the input strings s and order.

    In summary, the time complexity of the solution is O(n + m), and the space complexity is O(1).
 */