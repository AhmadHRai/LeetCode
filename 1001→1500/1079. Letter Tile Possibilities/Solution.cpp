class Solution {
    public:
        int numTilePossibilities(string tiles) {
            // Frequency map to store the count of each tile
            unordered_map<char, int> freq;
            
            // Count the frequency of each character
            for (char tile : tiles) {
                freq[tile]++;
            }
            
            // Set to store unique sequences
            set<string> result;
            
            // Backtracking helper function
            backtrack(freq, "", result);
            
            // The size of the result set will give the number of unique sequences
            return result.size();
        }
    
    private:
        void backtrack(unordered_map<char, int>& freq, string current, set<string>& result) {
            // If current sequence is non-empty, add it to the result set
            if (!current.empty()) {
                result.insert(current);
            }
    
            // Try all possible tiles
            for (auto& entry : freq) {
                char tile = entry.first;
                int count = entry.second;
    
                if (count > 0) {
                    // Use the tile, reduce its frequency, and recurse
                    freq[tile]--;
                    backtrack(freq, current + tile, result);
                    // Backtrack: restore the frequency
                    freq[tile]++;
                }
            }
        }
    };

/*
Approach Summary:
    This solution uses a recursive backtracking approach to generate all possible combinations of tiles. It maintains a set to store unique combinations and ensures that 
    each tile is used according to its frequency.

Complexity Analysis:
    - Time Complexity: O(N!), where N is the number of unique tiles, because in the worst case, all permutations of tiles need to be explored.
    - Space Complexity: O(N), for storing the frequency of tiles and the set of unique combinations.
*/