#include <vector>
using namespace std;

class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> tree(n);
        for (auto& edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }

        int components = 0;

        // Helper function for DFS
        function<long long(int, int)> dfs = [&](int node, int parent) -> long long {
            long long subtreeSum = values[node]; // Use long long to avoid overflow
            for (int neighbor : tree[node]) {
                if (neighbor == parent) continue;
                subtreeSum += dfs(neighbor, node); // Add the value from the child node
            }
            // Check divisibility by k
            if (subtreeSum % k == 0) {
                components++;  // Increment components counter if divisible by k
                return 0;  // Reset the sum for this subtree (as it is a valid component)
            }
            return subtreeSum; // Return the current sum to the parent node
        };

        dfs(0, -1);  // Start DFS from node 0
        return components;
    }
};

/* 
Approach Explanation:
    Graph Construction: A tree is built from the input edges list, where each node is connected to its neighbors.
    DFS Traversal: The DFS function is defined to calculate the sum of values for the subtree rooted at each node. For each node, its sum is checked for divisibility by k. If it is divisible, the component count is incremented, and the subtree sum is reset to 0. This ensures that we count components whose total value is divisible by k.
    Helper Function: The dfs function calculates the subtree sum and ensures correct divisibility checks.

Time and Space Complexity:
    Time Complexity: O(n), as we visit each node once during DFS.
    Space Complexity: O(n), due to the recursion stack and storing the tree structure.
 */