class Solution {
    public:
        void backtrack(unordered_map<char, int>& freq, int& count) {
            // Try all possible tiles
            for (auto& entry : freq) {
                if (entry.second > 0) {
                    // Use the tile, reduce its frequency, and increment count
                    entry.second--;
                    count++;
                    backtrack(freq, count);
                    // Backtrack: restore the frequency
                    entry.second++;
                }
            }
        }
    
        // Returns the number of unique sequences that can be formed from the given tiles
        int numTilePossibilities(string tiles) {
            // Frequency map to store the count of each tile
            unordered_map<char, int> freq;
    
            // Count the frequency of each character
            for (int i = 0; i < tiles.size(); i++) {
                freq[tiles[i]]++;
            }
    
            int count = 0; // Initialize count of unique sequences
    
            // Start the backtracking process
            backtrack(freq, count);
    
            return count;
        }
    }
    /*
    Approach Summary:
        This solution uses a recursive backtracking approach to count all possible combinations of tiles. It increments a count whenever a new sequence is generated and ensures that each tile is used according to its frequency.
    
    Complexity Analysis:
    - Time Complexity: O(N!), where N is the number of unique tiles, because in the worst case, all permutations of tiles need to be explored.
    - Space Complexity: O(N), for storing the frequency of tiles and the recursion stack.
    */
    