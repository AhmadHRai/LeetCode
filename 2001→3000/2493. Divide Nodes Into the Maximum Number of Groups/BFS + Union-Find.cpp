class Solution {
    public:
        // Main function to calculate the maximum number of groups for the entire
        // graph
        int magnificentSets(int n, vector<vector<int>> &edges) {
            vector<vector<int>> adjList(n);
            vector<int> parent(n, -1);
            vector<int> depth(n, 0);
    
            // Build the adjacency list and apply Union-Find for each edge
            for (auto edge : edges) {
                adjList[edge[0] - 1].push_back(edge[1] - 1);
                adjList[edge[1] - 1].push_back(edge[0] - 1);
                Union(edge[0] - 1, edge[1] - 1, parent, depth);
            }
    
            unordered_map<int, int> numOfGroupsForComponent;
    
            // For each node, calculate the maximum number of groups for its
            // component
            for (int node = 0; node < n; node++) {
                int numberOfGroups = getNumberOfGroups(adjList, node, n);
                if (numberOfGroups == -1) return -1;  // If invalid split, return -1
                int rootNode = find(node, parent);
                numOfGroupsForComponent[rootNode] =
                    max(numOfGroupsForComponent[rootNode], numberOfGroups);
            }
    
            // Calculate the total number of groups across all components
            int totalNumberOfGroups = 0;
            for (auto [rootNode, numberOfGroups] : numOfGroupsForComponent) {
                totalNumberOfGroups += numberOfGroups;
            }
            return totalNumberOfGroups;
        }
    
    private:
        // Find the root of the given node in the Union-Find structure
        int find(int node, vector<int> &parent) {
            while (parent[node] != -1) node = parent[node];
            return node;
        }
    
        // Union operation to merge two sets
        void Union(int node1, int node2, vector<int> &parent, vector<int> &depth) {
            node1 = find(node1, parent);
            node2 = find(node2, parent);
    
            // If both nodes already belong to the same set, no action needed
            if (node1 == node2) return;
    
            // Union by rank (depth) to keep the tree balanced
            if (depth[node1] < depth[node2]) swap(node1, node2);
            parent[node2] = node1;
    
            // If the depths are equal, increment the depth of the new root
            if (depth[node1] == depth[node2]) depth[node1]++;
        }
    
        // Function to calculate the number of groups for a given component starting
        // from srcNode
        int getNumberOfGroups(vector<vector<int>> &adjList, int srcNode, int n) {
            queue<int> nodesQueue;
            vector<int> layerSeen(n, -1);
            nodesQueue.push(srcNode);
            layerSeen[srcNode] = 0;
            int deepestLayer = 0;
    
            // Perform BFS to calculate the number of layers (groups)
            while (!nodesQueue.empty()) {
                int numOfNodesInLayer = nodesQueue.size();
                for (int i = 0; i < numOfNodesInLayer; i++) {
                    int currentNode = nodesQueue.front();
                    nodesQueue.pop();
                    for (int neighbor : adjList[currentNode]) {
                        // If neighbor hasn't been visited, assign it to the next
                        // layer
                        if (layerSeen[neighbor] == -1) {
                            layerSeen[neighbor] = deepestLayer + 1;
                            nodesQueue.push(neighbor);
                        } else {
                            // If the neighbor is already in the same layer, return
                            // -1 (invalid partition)
                            if (layerSeen[neighbor] == deepestLayer) {
                                return -1;
                            }
                        }
                    }
                }
                deepestLayer++;
            }
            return deepestLayer;
        }
    };

/* 
Algorithm
    getNumberOfGroups(adjList, srcNode, n)

        Initialize a queue, nodesQueue, and an array, layerSeen of size n with all values set to -1.
        PushsrcNode into the queue and set layerSeen[srcNode] to 0.
        Initialize deepestLayer to 0.
        While the nodesQueue is not empty:
            Initialize numOfNodesInLayer to the size of the queue.
            Process all nodes in the current layer, i.e. for i from 0 to numOfNodesInLayer - 1:
                Pop out the first element from the queue as currentNode.
                For each neighbor of currentNode:
                    If the neighbor is not visited, i.e. layerSeen[neighbor] == -1:
                        Set layerSeen[neighbor] = deepestLayer + 1.
                        Push neighbor into the queue.
                    Otherwise:
                        If the neighbor is seen in the current layer (deepestLayer), then the split is invalid; return -1.
            Increment deepestLayer by 1.
        Return deepestLayer.

    find(node, parent) function

        While node is not the root of its subtree, i.e. parent[node] != -1:
            Set node = parent[node].
        Return node.

    Union(node1, node2, parent, depth) function

        Replace node1 and node2 by the roots of their subtrees, by setting node1 = find(node1, parent) and node2 = find(node2, parent).
        If node1 == node2, the two nodes already belong in the same set, so simply return.
        If node1 has a smaller depth than node2, swap the two nodes.
        Set node1 to be the parent of node2.
        If the depths of the two nodes are equal, increment depth[node1] by 1.

    In the main magnificentSets(n, edges) function:

        Create a 2D array, adjList.
        Initialize two arrays of size n, parent, and depth for the Union-Find. Set the parent of each node to -1 and its depth to 0.
        For each edge = [node1, node2] in edges:
            Push node1 - 1 to adjList[node2 - 1] (transitioning to 0-index).
            Push node2 - 1 to adjList[node1 - 1].
            Call Union(node1 - 1, node2 - 1, parent, depth).
        Initialize a map, numOfGroupsForComponent to store the greatest number of groups that can be achieved for each component of the graph.
        For each node of the graph:
            Calculate the number of groups the nodes of its component will be split into, if we assign node to the first group: numberOfGroups = getNumberOfGroups(adjList, node, n).
            If numberOfGroups = -1, then a split is impossible for that component, so return -1.
            Find the rootNode of nodes component, root = find(node, parent).
            Update the greatest number of groups that can be achieved for this component (numOfGroupsForComponent[rootNode]) to the maximum of its current value and numberOfGroups.
        Initialize totalNumberOfGroups to 0.
        For every [rootNode, numberOfGroups] in numOfGroupsForComponent:
            Add numberOfGroups to totalNumberOfGroups.
        Return totalNumberOfGroups.

Complexity Analysis
Let n be the number of nodes in the graph and m the size of the edges array.

    Time complexity: O(n×(n+m))

        We use the Union-Find method to detect the connected components of the graph. Each call to the find function traverses the nodes in the component of the given node until it reaches the root. By using the depth array, we maintain balanced sets, ensuring that the find operation has a time complexity of O(logn). As a result, the process of identifying the connected components takes O(nlogn) time.

        Next, we perform a BFS traversal starting from each node. Since the time complexity of BFS is O(m+n), the total time for this operation is O(n×(m+n)).

        Since nlogn=O(n×(m+n)), the overall time complexity is dominated by the BFS traversals, giving us a final time complexity of O(n×(n+m)).

    Space complexity: O(n+m)

        As in the previous approach, representing the graph using an adjacency list requires O(n+m) space. This is an additional space requirement rather than part of the input itself. The auxiliary space complexity is determined by both the adjacency list and the additional data structures used (parent, depth, numberOfGroupsForComponent), which can grow up to O(n) in size. Therefore, the overall space complexity is O(n+m).

*/