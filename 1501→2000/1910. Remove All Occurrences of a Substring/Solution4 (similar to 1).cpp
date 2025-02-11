class Solution {
    public:
        string removeOccurrences(string s, string part) {
            size_t N = part.length();
            
            // Repeatedly search for `part` and remove it
            while (true) {
                size_t i = s.find(part);
                if (i == string::npos) {
                    break;  // No more occurrences of `part` found
                }
                s.erase(i, N);  // Remove the occurrence of `part` at index `i`
            }
            return s;
        }
    };

/*
Approach Summary:
    This solution iteratively finds and removes all occurrences of a given substring from a string. It uses a loop to continuously search for the substring and remove it 
    until no more occurrences are found.

Complexity Analysis:
    Time Complexity: O(N*M), where N is the length of the string and M is the length of the substring, because in the worst case, the substring could be removed from 
    every position in the string.
    
    Space Complexity: O(N), for creating new strings during each removal operation.
*/