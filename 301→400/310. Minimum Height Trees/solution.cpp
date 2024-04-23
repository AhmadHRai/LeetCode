class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // Base cases: if there are no nodes or only one node, return the node itself
        if(n==0)
            return {};
        if(n==1)
            return {0};
        vector<int>res;
        vector<int>degrees(n,0);
        vector<vector<int>>adj(n);
        // Create an adjacency list and calculate the degree of each node
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]); // Creating adjacent list
            adj[edges[i][1]].push_back(edges[i][0]);
            degrees[edges[i][1]]++; // Updating how many edges each node has
            degrees[edges[i][0]]++;
        }
        // Initialize a queue with all nodes that have a degree of 1 (leaves)
        queue<int>queue;
        for(int i=0;i<n;i++)
        {
            if(degrees[i]==1) // Adding all the leaf nodes
                queue.push(i);
        }
        // Perform BFS to find the minimum height trees
        while(!queue.empty())
        {
            res.clear(); // Clear vector before we start traversing level by level
            int size=queue.size();
            for(int i=0;i<size;i++)
            {
                int cur=queue.front();
                queue.pop();
                res.push_back(cur); // Adding nodes to vector. Goal is to get a vector of just 1 or 2 nodes available
                for(auto &neighbor:adj[cur])
                {
                    degrees[neighbor]--; // Removing current leaf nodes
                    if(degrees[neighbor]==1) // Adding current leaf nodes
                        queue.push(neighbor);
                }
            }
        }
        return res;
    }
};

/* 
Approach:

This solution uses a breadth-first search (BFS) algorithm to find the minimum height trees in a graph. The minimum height trees are the ones that have the smallest 
number of edges between them and the rest of the graph.

    1. Initialize an adjacency list and a degree array to keep track of the number of edges each node has.
    2. Enqueue all nodes that have a degree of 1 (leaves) into a queue.
    3. Perform BFS, where each level of the BFS represents a layer of the tree.
    4. For each node dequeued, remove it from the graph by decrementing the degree of its neighbors. If a neighbor's degree becomes 1, enqueue it.
    5. Repeat the BFS until the queue is empty. The remaining nodes in the queue are the roots of the minimum height trees.

Complexity:

    Time Complexity: O(n), where n is the number of nodes in the graph. This is because each node is processed once during the BFS.
    Space Complexity: O(n), where n is the number of nodes in the graph. This is due to the storage required for the adjacency list, degree array, and queue.

This approach is efficient for solving the problem within the given constraints, as it systematically explores the graph layer by layer to find the minimum height trees.
*/