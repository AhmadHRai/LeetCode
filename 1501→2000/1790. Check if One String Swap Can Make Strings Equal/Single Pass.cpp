class Solution {
    public:
        bool areAlmostEqual(string s1, string s2) {
            // If the strings are identical, they are almost equal
            if (s1 == s2) return true;
    
            // Store indices where the strings differ
            vector<int> indexes;
            for (int i = 0; i < s1.length(); i++) {
                if (s1[i] != s2[i]) {
                    indexes.push_back(i);
                }
                // If more than two differences are found, the strings are not almost equal
                if (indexes.size() > 2) return false;
            }
    
            // If exactly two differences are found, check if they can be swapped to match
            if (indexes.size() == 2) {
                int i = indexes.at(0);
                int j = indexes[1];
    
                // Check if swapping the differing characters makes the strings equal
                return s1[i] == s2[j] && s1[j] == s2[i];
            }
            // If no differences or more than two differences, the strings are not almost equal
            return false;
        }
    }
    /*
    Approach Summary:
    This solution checks if two strings are almost equal by identifying differences and determining if they can be resolved by swapping two characters. It iterates through the strings once, storing indices of differences and checking if a swap can make the strings equal.
    
    Complexity Analysis:
    - Time Complexity: O(N), where N is the length of the strings, because each character is visited once.
    - Space Complexity: O(1), as only a constant amount of space is used for storing indices (at most two differences).
    
    For naming the approach file, you could use something like:
    */
    