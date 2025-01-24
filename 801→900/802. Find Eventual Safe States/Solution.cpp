class Solution {
    public:
        // Perform DFS to detect cycles starting from a given node
        bool dfs(int node, vector<vector<int>>& adj, vector<bool>& visit,
                 vector<bool>& inStack, vector<bool>& safe) {
            // If the node is already in the stack, we have a cycle.
            if (inStack[node]) {
                return true;
            }
            if (visit[node]) {
                // If the node is visited and not in the stack, it means we've already checked it.
                return false;
            }
            // Mark the current node as visited and part of the current recursion stack.
            visit[node] = true;
            inStack[node] = true;
            
            // Check all neighbors for cycles
            for (auto neighbor : adj[node]) {
                if (dfs(neighbor, adj, visit, inStack, safe)) {
                    return true;
                }
            }
            // Remove the node from the stack.
            inStack[node] = false;
            // If no cycle is found, mark the node as safe.
            safe[node] = true;
            return false;
        }
    
        // Find all eventual safe nodes in the graph
        vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
            int n = graph.size();
            vector<bool> visit(n), inStack(n), safe(n);
    
            for (int i = 0; i < n; i++) {
                dfs(i, graph, visit, inStack, safe);
            }
    
            vector<int> safeNodes;
            for (int i = 0; i < n; i++) {
                if (safe[i]) {
                    safeNodes.push_back(i);
                }
            }
    
            return safeNodes;
        }
    }
    /*
    Approach Summary:
    This solution uses DFS to detect cycles in the graph. It maintains three boolean vectors: `visit` to track visited nodes, `inStack` to detect cycles, and `safe` to mark nodes that do not lead to cycles. After performing DFS from each node, it collects nodes marked as safe.
    
    Complexity Analysis:
    - Time Complexity: O(N + E), where N is the number of nodes and E is the number of edges, because each node and edge is visited once.
    - Space Complexity: O(N), for the `visit`, `inStack`, and `safe` vectors.
    */
    