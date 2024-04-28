class Solution {
public:
    vector<vector<int>> v;
    vector<int> counter, res;

    // Initially, count array was initialized to 0.
    // count[parent] is the sum of count of its child + 1
    // v is the Adjacency List    
    void dfs(int i, int p = -1) {
        for(auto u : v[i]) {
            if(u == p) continue;
            dfs(u, i);
            counter[i] += counter[u];
            res[i] += res[u] + counter[u];
        }
        counter[i] += 1;
    }

    /*
    Suppose we shift the root from root 0 to 1, what changes can we observe.
    count[1] nodes got 1 unit closer to new root and n - count[1] nodes got 1 unit away from the new root.
    So,
    res[1] = res[0] - count[1] + n - count[1]
    i.e
    res[new_root] = res[root] - count[new_root] + n - count[new_root]

    The way we are running dfs the new_root will be child and root will be parent.
    Here, is the code for this part.
    */
    void dfs2(int i, int n, int p = -1) {
        for(auto u : v[i]) {
            if(u == p) continue;
            res[u] = res[i] - counter[u] + n - counter[u];
            dfs2(u, n, i);
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        v.resize(n);
        for(int i = 0; i < n - 1; i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            v[a].push_back(b);
            v[b].push_back(a);
        }
        res.resize(n);
        counter.resize(n);
        dfs(0);
        dfs2(0, n);
        return res;
    }
};

/* 
Approach:

This solution uses a two-pass depth-first search (DFS) algorithm to calculate the sum of distances from each node to all other nodes in a tree. The first pass (`dfs`)  
calculates the sum of distances for the root node, and the second pass (`dfs2`) adjusts these sums for each node in the tree.

1. Initialize an adjacency list `v` and two vectors `counter` and `res` to store the count of nodes in the subtree rooted at each node and the sum of distances from each 
    node to all other nodes, respectively.
2. Perform the first DFS pass starting from the root node (0) to calculate the sum of distances for the root node.
3. Perform the second DFS pass starting from the root node (0) to adjust the sums of distances for each node in the tree.
4. Return the vector `res` containing the sum of distances from each node to all other nodes.

Complexity:

    Time Complexity: O(n), where n is the number of nodes in the tree. This is because each node is processed once during the first DFS pass and once during the second DFS pass.
    Space Complexity: O(n), where n is the number of nodes in the tree. This is due to the storage required for the adjacency list, count array, and result array.

This approach is efficient for solving the problem within the given constraints, as it systematically calculates the sum of distances from each node to all other nodes 
in the tree.
*/