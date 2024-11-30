class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adjacencyList;
        unordered_map<int, int> inOutDegree;
        
        // Build graph and count in/out degrees
        for (const auto& pair : pairs) {
            adjacencyList[pair[0]].push_back(pair[1]);
            inOutDegree[pair[0]]++;  // out-degree
            inOutDegree[pair[1]]--;  // in-degree
        }
        
        // Find starting node (head)
        int startNode = pairs[0][0];
        for (const auto& [node, degree] : inOutDegree) {
            if (degree == 1) {
                startNode = node;
                break;
            }
        }
        
        vector<int> path;
        stack<int> nodeStack;
        nodeStack.push(startNode);
        
        // Perform depth-first search (DFS) to find the Eulerian Path
        while (!nodeStack.empty()) {
            auto& neighbors = adjacencyList[nodeStack.top()];
            if (neighbors.empty()) {
                path.push_back(nodeStack.top());
                nodeStack.pop();
            } else {
                int nextNode = neighbors.back();
                nodeStack.push(nextNode);
                neighbors.pop_back();
            }
        }
        
        vector<vector<int>> arrangement;
        int pathSize = path.size();
        arrangement.reserve(pathSize - 1);
        
        // Construct the result from the path
        for (int i = pathSize - 1; i > 0; --i) {
            arrangement.push_back({path[i], path[i-1]});
        }
        
        return arrangement;
    }
};

/*
    Approach:
    1. The problem involves finding a valid arrangement of pairs that can be represented as an Eulerian Path 
       in a directed graph. An Eulerian Path exists if:
       - At most one vertex has an out-degree greater than its in-degree by 1 (potential starting point).
       - At most one vertex has an in-degree greater than its out-degree by 1 (potential ending point).
       - All other vertices should have equal in-degrees and out-degrees.

    2. We begin by constructing the graph using an adjacency list representation (`adjacencyList`), 
       where each key is a starting node and the value is a list of end nodes. We also maintain an 
       `inOutDegree` map to track the difference between in-degrees and out-degrees for each node.

    3. Next, we identify the starting node for our traversal:
       - If we find a node with an out-degree greater than its in-degree by 1, we select that as our starting point.
       - If no such node exists, we default to the first pair's starting node.

    4. We then perform a depth-first search (DFS) using a stack to explore all edges starting from the identified `startNode`.
       - If there are no more outgoing edges from the current node, we add it to our path and backtrack.
       - If there are outgoing edges, we continue traversing until all edges are used.

    5. Finally, we construct the result by reversing the collected path to produce the correct order of pairs for the valid arrangement.

    Complexity:
        Time Complexity: O(m + n), where m is the number of pairs (edges) and n is the number of distinct nodes (vertices).
        Space Complexity: O(m + n), due to storage of the adjacency list and degree information.

*/
