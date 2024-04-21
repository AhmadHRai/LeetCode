// Solution 1: BFS, form a graph and check if there's a path
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>> graph; 
        // Construct the graph from the edges
        for(auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n,0);        
        // Initialize a queue for BFS and mark the source node as visited
        queue<int> q;
        q.push(source);
        visited[source] = 1; 
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            // If the current node is the destination, return true
            if(curr == destination)
                return 1; 
            // Visit all unvisited neighbors of the current node
            for(auto &node : graph[curr]){
                if(!visited[node]){
                    visited[node] = 1; 
                    q.push(node);
                }
            }
        }
        // If the destination is not reachable, return false
        return false;
    }
};

/* 
Approach:

    This algorithm uses a Breadth-First Search (BFS) to determine if there is a path from the source node to the destination node in a graph. The graph is represented as 
    an adjacency list, where each node is connected to its neighbors. The algorithm starts at the source node and explores its neighbors. If it encounters the 
    destination node during this exploration, it returns true, indicating that a path exists. If the algorithm exhausts all possible paths without finding the 
    destination node, it returns false, indicating that no path exists.

Complexity Analysis:

    Time Complexity: The time complexity of this algorithm is O(n + m), where n is the number of nodes and m is the number of edges in the graph. This is because each 
    node and each edge is visited exactly once by the BFS algorithm.

    Space Complexity: The space complexity is O(n + m), as the algorithm needs to store the graph and the visited status of each node. In the worst case, the graph could 
    be fully connected, meaning each node is connected to every other node, and the visited array would need to store the status of each node.
 */