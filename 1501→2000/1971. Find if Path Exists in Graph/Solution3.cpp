/* Solution 3: We don't really to need to find the length of the path. Since this is an undirected graph, 
we just need to check if start and end are in the same connected component. So we use union find
*/
class Solution {
public:
    vector<int> parent;     
    int findParent(int node) {
        return parent[node] == node ? node : (parent[node] = findParent(parent[node]));
    }    
    void makeSameGroup(int u , int v) {
        int pu = findParent(u) ; 
        int pv = findParent(v);
        parent[pu] = pv; 
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        parent.resize(n);
        for(int i=0;i<n;i++)
            parent[i] = i; 
        
        for(auto e : edges) {
            makeSameGroup(e[0] , e[1]); 
        }                         
        return findParent(source) == findParent(destination); 
    }
};

/* 
Approach:
    We are using the Union-Find data structure here to determine if there is a path from the source node to the destination node in an undirected graph. The Union-Find 
    data structure is used to keep track of a partition of a set into disjoint subsets. In this context, it is used to determine if two nodes belong to the same 
    connected component. The algorithm starts by initializing each node as its own parent, representing that each node is initially in its own connected component. Then, 
    for each edge in the graph, it merges the connected components of the two nodes of the edge. Finally, it checks if the source and destination nodes have the same 
    parent, which would indicate that they are in the same connected component and thus there is a path between them.

Complexity Analysis:

    Time Complexity: The time complexity of this algorithm is O(n + m), where n is the number of nodes and m is the number of edges in the graph. This is because each 
    node and each edge is processed exactly once. The Union-Find operations (find and union) can be performed in nearly constant time, amortized over a sequence of 
    operations, due to path compression and union by rank.

    Space Complexity: The space complexity is O(n), as the algorithm needs to store the parent array to keep track of the connected components. In the worst case, each 
    node is in its own connected component, and the parent array would need to store the status of each node.
 */