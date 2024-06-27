#define UNSYNC ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);  // Fast IO macros

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        UNSYNC;  // Fast IO initialization
        
        unordered_set<int> seen;  // Set to track seen nodes
        
        // Iterate through each edge in the edges vector
        for (const auto& edge : edges) {
            // Iterate through each number in the current edge
            for (int num : edge) {
                // Check if the number is already in the set
                if (seen.find(num) != seen.end()) {
                    // Found duplicate, which is the center node
                    return num;
                }
                seen.insert(num);  // Insert the number into the set
            }
        }
        
        return -1;  // If no center node is found, return -1
    }
};

/*
Approach:
- Use UNSYNC macro for fast input/output operations.
- Initialize an unordered_set 'seen' to keep track of seen nodes.
- Iterate through each edge in the edges vector.
- For each number in the current edge, check if it's already in the 'seen' set.
- If it is, this number is the center node (since each edge has exactly two nodes, and the center is the node shared by all edges).
- Return the center node if found.
- If no center node is found after iterating through all edges, return -1.

Complexity Analysis:
- Time Complexity: O(E), where E is the number of edges.
  - We iterate through each edge and each node in the worst case scenario, making the time complexity linear relative to the number of edges.
  
- Space Complexity: O(V), where V is the number of vertices (nodes).
  - The space complexity is primarily due to the unordered_set 'seen' that stores unique node values.
  - In the worst case, all nodes could be unique, so the space complexity is linear relative to the number of nodes.

*/

