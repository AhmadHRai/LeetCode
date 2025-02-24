class Solution {
    private:
        // Adjacency list representation of the tree
        vector<vector<int>> tree;
        // Vector to store distances from Bob to each node
        vector<int> distanceFromBob;
        int n; // Number of nodes in the tree
    
        // Recursive DFS function to find the most profitable path
        int findPaths(int sourceNode, int parentNode, int time, int bob, vector<int>& amount) {
            int maxIncome = 0; // Maximum income collected so far
            int maxChild = INT_MIN; // Maximum income from child nodes
    
            // Update distance from Bob to the current node
            if (sourceNode == bob) {
                distanceFromBob[sourceNode] = 0; // Bob is at this node
            } else {
                distanceFromBob[sourceNode] = n; // Initialize with a large value
            }
    
            // Explore adjacent nodes
            for (int adjacentNode : tree[sourceNode]) {
                if (adjacentNode != parentNode) { // Avoid backtracking
                    // Recursively find the maximum income from child nodes
                    maxChild = max(maxChild, findPaths(adjacentNode, sourceNode, time + 1, bob, amount));
    
                    // Update the distance from Bob to the current node
                    distanceFromBob[sourceNode] = min(distanceFromBob[sourceNode], distanceFromBob[adjacentNode] + 1);
                }
            }
    
            // Calculate income based on who reaches the node first
            if (distanceFromBob[sourceNode] > time) {
                // Alice reaches first, collect full amount
                maxIncome += amount[sourceNode];
            } else if (distanceFromBob[sourceNode] == time) {
                // Alice and Bob reach together, collect half amount
                maxIncome += amount[sourceNode] / 2;
            }
    
            // Return the maximum income
            if (maxChild == INT_MIN) {
                return maxIncome; // No child nodes
            } else {
                return maxIncome + maxChild; // Include income from child nodes
            }
        }
    
    public:
        // Returns the most profitable path in the tree
        int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
            n = amount.size(); // Number of nodes in the tree
    
            // Initialize the tree with edges
            tree.resize(n, vector<int>());
            for (vector<int> edge : edges) {
                tree[edge[0]].push_back(edge[1]);
                tree[edge[1]].push_back(edge[0]);
            }
    
            // Initialize distances from Bob
            distanceFromBob.resize(n);
    
            // Start the DFS from node 0
            return findPaths(0, 0, 0, bob, amount);
        }
    }
    /*
    Approach Summary:
        This solution uses a recursive DFS approach to find the most profitable path in the tree. It calculates the distance from Bob to each node and determines the 
        income based on who reaches the node first.
    
        However, the current implementation seems to have logical issues in calculating the distances and incomes. A correct approach should involve calculating the 
        distances from Bob to each node and then using these distances to determine the income at each node based on whether Alice or Bob reaches first.
    
    Complexity Analysis:
        Time Complexity: O(N), where N is the number of nodes in the tree, because each node is visited once.
        Space Complexity: O(N), for storing the tree and the recursion stack.
    */
    