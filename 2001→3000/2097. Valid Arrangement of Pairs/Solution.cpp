class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int numPairs = pairs.size();
        
        // Graph for Eulerian Path
        unordered_map<int, stack<int>> graph;
        unordered_map<int, int> inDegree;
        unordered_map<int, int> outDegree;
        
        // Reserve space for unordered_map to improve runtime
        graph.reserve(numPairs);
        inDegree.reserve(numPairs);
        outDegree.reserve(numPairs);
        
        // Build the graph and calculate in-degrees and out-degrees
        for (int i = 0; i < numPairs; i++) {
            int startNode = pairs[i][0], endNode = pairs[i][1];
            inDegree[endNode]++;
            outDegree[startNode]++;
            graph[startNode].push(endNode);
        }
        
        // Find the starting node for Eulerian Path (if any)
        int startNode = -1;
        for (const auto& entry : graph) {
            int node = entry.first;
            if (outDegree[node] - inDegree[node] == 1) {
                startNode = node;
                break;
            }
        }
        
        // If no such start node is found, start from any node in the graph (Eulerian Circuit)
        if (startNode == -1) {
            startNode = graph.begin()->first;
        }
        
        vector<vector<int>> result;
        // Perform the Eulerian path traversal
        findEulerianPath(graph, result, startNode);
        
        // Reverse the result to get the correct order
        reverse(result.begin(), result.end());
        
        return result;
    }

private:
    void findEulerianPath(unordered_map<int, stack<int>>& graph, vector<vector<int>>& result, int currentNode) {
        auto& adjList = graph[currentNode];
        
        // Traverse the graph in a depth-first manner
        while (!adjList.empty()) {
            int nextNode = adjList.top();
            adjList.pop();
            findEulerianPath(graph, result, nextNode);
            
            // Record the edge after exploring the next node (postorder)
            result.push_back({currentNode, nextNode});
        }
    }
};


/*
    Approach:
    1. The problem is essentially finding an Eulerian Path in a directed graph. An Eulerian Path exists if, 
       for every node:
       - The in-degree and out-degree differ by at most 1.
       - All nodes with non-zero degree are connected in a single component.

    2. We start by building the graph from the given `pairs`. Each pair represents a directed edge from `startNode` to `endNode`.
       - We use an unordered_map `graph` to represent the adjacency list of the graph.
       - We maintain two other unordered_maps `inDegree` and `outDegree` to store the in-degrees and out-degrees of each node.
    
    3. After building the graph, we look for the starting node for the Eulerian Path:
       - If there is a node with an out-degree greater than its in-degree by 1, we start from that node.
       - If no such node exists, it means the graph is an Eulerian Circuit, and we can start from any node.

    4. We then perform a depth-first search (DFS) to find the Eulerian Path. During the DFS:
       - We recursively explore all outgoing edges for a node and backtrack once all edges are used.
       - We store the edges in the result in postorder (i.e., after we finish exploring the next node).

    5. Finally, we reverse the collected edges to produce the correct order of the Eulerian Path.

    Time Complexity: O(N), where N is the number of pairs (edges).
    Space Complexity: O(N), as we store the graph and degree information.
*/
