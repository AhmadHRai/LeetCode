class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        # Counter to count the frequency of each character
        freq = Counter(tiles)
        result = set()

        def backtrack(path):
            # If the current path is not empty, add it to the result set
            if path:
                result.add(path)
            
            # Try all possible next tiles
            for tile in freq:
                if freq[tile] > 0:
                    # Reduce frequency and recurse
                    freq[tile] -= 1
                    backtrack(path + tile)
                    # Backtrack: restore frequency
                    freq[tile] += 1
        
        # Start the backtracking with an empty path
        backtrack('')
        return len(result)

""" 
Approach Summary:
    This solution uses a recursive backtracking approach to generate all possible combinations of tiles. It maintains a set to store unique combinations and ensures that each tile is used according to its frequency.

Complexity Analysis:
    Time Complexity: O(N!), where N is the number of unique tiles, because in the worst case, all permutations of tiles need to be explored.
    Space Complexity: O(N), for storing the frequency of tiles and the set of unique combinations.
"""