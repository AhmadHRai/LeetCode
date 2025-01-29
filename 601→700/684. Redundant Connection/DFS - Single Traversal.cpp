class Solution {
    private:
        int cycleStart = -1;
    
        // Peform the DFS and store a node in the cycle as cycleStart.
        void DFS(int src, vector<bool> &visited, vector<int> adjList[],
                 vector<int> &parent) {
            visited[src] = true;
    
            for (int adj : adjList[src]) {
                if (!visited[adj]) {
                    parent[adj] = src;
                    DFS(adj, visited, adjList, parent);
                    // If the node is visited and the parent is different then the
                    // node is part of the cycle.
                } else if (adj != parent[src] && cycleStart == -1) {
                    cycleStart = adj;
                    parent[adj] = src;
                }
            }
        }
    
    public:
        vector<int> findRedundantConnection(vector<vector<int>> &edges) {
            int N = edges.size();
    
            vector<bool> visited(N, false);
            vector<int> parent(N, -1);
    
            vector<int> adjList[N];
            for (auto edge : edges) {
                adjList[edge[0] - 1].push_back(edge[1] - 1);
                adjList[edge[1] - 1].push_back(edge[0] - 1);
            }
    
            DFS(0, visited, adjList, parent);
    
            unordered_map<int, int> cycleNodes;
            int node = cycleStart;
            // Start from the cycleStart node and backtrack to get all the nodes in
            // the cycle. Mark them all in the map.
            do {
                cycleNodes[node] = 1;
                node = parent[node];
            } while (node != cycleStart);
    
            // If both nodes of the edge were marked as cycle nodes then this edge
            // can be removed.
            for (int i = edges.size() - 1; i >= 0; i--) {
                if (cycleNodes[edges[i][0] - 1] && cycleNodes[edges[i][1] - 1]) {
                    return edges[i];
                }
            }
    
            return {};
        }
    };

/* 
Algorithm

    Initialize Variables:
        Set cycleStart to -1 to mark the start of the cycle.
        Create a visited array to keep track of visited nodes.
        Create a parent array to store the parent of each node in the DFS traversal.
        Initialize an adjacency list adjList to represent the graph.

    Build the Graph:
        Loop through each edge in the input edges list.
        For each edge [u, v], add v to adjList[u] and u to adjList[v] to make the graph undirected.

    Start a DFS from node 0 (or any node, as the graph is connected).
        In the DFS function:
            Mark the current node as visited.
            For each adjacent node, check if it's visited:
                If not visited, recursively call DFS on the adjacent node, and update its parent.
                If the node is visited and its parent is different from the previous one, mark it as cycleStart to identify the cycle.

    Track Cycle Nodes:
        Using the parent array, backtrack from cycleStart to collect all nodes in the cycle.
        Store these nodes in the cycleNodes map for quick lookup.

    Identify the Redundant Edge:
        Iterate through the edges in reverse order.
        For each edge, check if both nodes of the edge are in the cycleNodes map:
            If both nodes are in the cycle, return this edge as the redundant connection.

Complexity Analysis

Here, N is the number of nodes and edges in the given graph.

    Time complexity: O(N).

    We perform the DFS starting from node 0 only once, which has a time complexity of O(N). Then, we iterate over the cycle nodes using the parent array, with a maximum of N iterations if all nodes are part of the cycle. Finally, we iterate over all edges and check the map in O(1) time for each edge. Therefore, the total time complexity is O(N).

    Space complexity: O(N)

    The adjacency list adjList will store N edges, and the size of the visited array is N. Additionally, space is required for the active stack calls during DFS, which can be as large as one per node. The map cycleNodes can contain at most N entries. Therefore, the total space complexity is O(N).

*/