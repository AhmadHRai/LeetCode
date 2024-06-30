class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        // Define UnionFind class for disjoint set operations
        class UnionFind {
        public:
            vector<int> parent, size;
            int components;
            
            // Constructor to initialize UnionFind
            UnionFind(int n) {
                components = n;
                parent.resize(n + 1);
                size.resize(n + 1, 1);
                for (int i = 0; i <= n; ++i) {
                    parent[i] = i;
                }
            }

            // Find operation with path compression
            int find(int x) {
                if (parent[x] != x) {
                    parent[x] = find(parent[x]);
                }
                return parent[x];
            }

            // Union operation with union by size
            bool unite(int x, int y) {
                int rootX = find(x), rootY = find(y);
                if (rootX == rootY) return false;
                if (size[rootX] < size[rootY]) swap(rootX, rootY);
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
                components--;
                return true;
            }

            // Check if all nodes are in one connected component
            bool isConnected() {
                return components == 1;
            }
        };
        
        // Initialize UnionFind instances for Alice and Bob
        UnionFind alice(n), bob(n);
        int edgesRequired = 0;
        
        // Process type 3 edges first
        for (const auto& edge : edges) {
            if (edge[0] == 3) {
                if (alice.unite(edge[1], edge[2]) | bob.unite(edge[1], edge[2])) {
                    edgesRequired++;
                }
            }
        }
        
        // Process type 1 and type 2 edges
        for (const auto& edge : edges) {
            if (edge[0] == 1) {
                if (alice.unite(edge[1], edge[2])) {
                    edgesRequired++;
                }
            } else if (edge[0] == 2) {
                if (bob.unite(edge[1], edge[2])) {
                    edgesRequired++;
                }
            }
        }
        
        // Check if both Alice and Bob are fully connected
        if (alice.isConnected() && bob.isConnected()) {
            return edges.size() - edgesRequired;
        }
        
        return -1;  // Return -1 if it's not possible to connect all nodes
    }
};

/*
Approach:
- Define a UnionFind class to handle union-find operations (find and union).
- Initialize two instances of UnionFind for Alice and Bob to track connections separately.
- Use UnionFind to process all type 3 edges, uniting nodes in Alice's and Bob's sets if possible.
- Process type 1 edges for Alice and type 2 edges for Bob, separately.
- Count the minimum number of edges required to connect all nodes for both Alice and Bob.
- Check if both Alice and Bob form a single connected component.
- Return the maximum number of edges that can be removed while ensuring all nodes are connected, or return -1 if not possible.

Complexity Analysis:
- Time Complexity: O(m * α(n)), where m is the number of edges and α is the inverse Ackermann function (almost constant).
  - Union and find operations using path compression and union by size ensure nearly constant time complexity.
  - Processing each edge and union operation contributes to O(m * α(n)) time complexity.
- Space Complexity: O(n), where n is the number of nodes.
  - Space is primarily used for storing parent and size arrays in UnionFind, which are proportional to the number of nodes.
  - Additional space complexity comes from storing the edges and auxiliary variables used during processing.
*/
