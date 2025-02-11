class Solution {
public:
    string removeOccurrences(string s, string part) {
        // Continuously remove occurrences of the substring until none are found
        while (s.find(part) != string::npos) {
            // Find the index of the first occurrence of the substring
            size_t part_i = s.find(part);
            // Remove the substring by concatenating the parts before and after it
            s = s.substr(0, part_i) + s.substr(part_i + part.length());
        }
        // Return the string with all occurrences removed
        return s;
    }
}

/*
Approach Summary:
    This solution iteratively removes all occurrences of a given substring from a string. It uses a loop to continuously find and remove the substring until no more 
    occurrences are found.

Complexity Analysis:
    Time Complexity: O(N*M), where N is the length of the string and M is the length of the substring, because in the worst case, the substring could be removed from every position in the string.
    
    Space Complexity: O(N), for creating new strings during each removal operation.
*/
    