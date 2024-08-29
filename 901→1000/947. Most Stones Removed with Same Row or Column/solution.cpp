class Solution {
public:
    // Function to determine the maximum number of stones that can be removed
    int removeStones(vector<vector<int>>& stones) {
        for (int i = 0; i < stones.size(); ++i) {
            // Union the row and column indices for each stone
            uni(stones[i][0], ~stones[i][1]);
        }
        // Return the total number of stones minus the number of disjoint sets (islands)
        return stones.size() - islands;
    }

    unordered_map<int, int> f; // Union-Find data structure (parent map)
    int islands = 0; // Counter for the number of disjoint sets (islands)
    
private:
    // Find the representative (root) of the set containing x
    int find(int x) {
        if (!f.count(x)) {
            // If x is not yet in the map, initialize it and increment the island count
            f[x] = x;
            islands++;
        }
        if (x != f[x]) {
            // Path compression: make the root of x point directly to the root
            f[x] = find(f[x]);
        }
        return f[x];
    }

    // Union the sets containing x and y
    void uni(int x, int y) {
        x = find(x); // Find the root of x
        y = find(y); // Find the root of y
        if (x != y) {
            // Union the sets by making the root of x point to the root of y
            f[x] = y;
            islands--; // Decrement the island count as two sets are merged into one
        }
    }
};

/*
Approach Summary:
- Use Union-Find to group stones that can be connected through their rows or columns.
- Each stone is represented by its row and column indices. The row index is used directly, and the column index is negated to avoid collisions.
- Union-Find is used to connect stones that share the same row or column.
- The number of removable stones is calculated as the total number of stones minus the number of disjoint sets (islands) in the Union-Find structure.

Time Complexity:
- O(n * α(n)), where n is the number of stones and α is the inverse Ackermann function. Each union and find operation is nearly constant time due to path compression and union by rank.

Space Complexity:
- O(n), where n is the number of stones. Space is used for the Union-Find data structure to keep track of parents and the number of disjoint sets.
*/
