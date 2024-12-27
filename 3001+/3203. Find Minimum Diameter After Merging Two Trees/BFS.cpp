class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1,
                                  vector<vector<int>>& edges2) {
        // Calculate the number of nodes for each tree
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        // Build adjacency lists for both trees
        vector<vector<int>> adjList1 = buildAdjList(n, edges1);
        vector<vector<int>> adjList2 = buildAdjList(m, edges2);

        // Calculate the diameters of both trees
        int diameter1 = findDiameter(n, adjList1);
        int diameter2 = findDiameter(m, adjList2);

        // Calculate the longest path that spans across both trees
        int combinedDiameter =
            ceil(diameter1 / 2.0) + ceil(diameter2 / 2.0) + 1;

        // Return the maximum of the three possibilities
        return max({diameter1, diameter2, combinedDiameter});
    }

private:
    vector<vector<int>> buildAdjList(int size, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(size);
        for (auto edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        return adjList;
    }

    // Function to find the diameter of a tree using two BFS calls
    int findDiameter(int n, vector<vector<int>>& adjList) {
        // First BFS to find the farthest node from any arbitrary node (e.g., 0)
        auto [farthestNode, _] = findFarthestNode(n, adjList, 0);

        // Second BFS from the farthest node to determine the diameter
        auto [_, diameter] = findFarthestNode(n, adjList, farthestNode);
        return diameter;
    }

    // BFS helper function to find the farthest node and its distance from the
    // source
    pair<int, int> findFarthestNode(int n, vector<vector<int>>& adjList,
                                    int sourceNode) {
        queue<int> nodesQueue;
        vector<bool> visited(n, false);
        // Push source node into the queue
        nodesQueue.push(sourceNode);
        visited[sourceNode] = true;

        int maximumDistance = 0, farthestNode = sourceNode;

        // Explore neighbors
        while (!nodesQueue.empty()) {
            int size = nodesQueue.size();
            for (int i = 0; i < size; ++i) {
                int currentNode = nodesQueue.front();
                nodesQueue.pop();
                // Update farthest node
                // The farthest node is the last one that was popped out of the
                // queue.
                farthestNode = currentNode;

                for (int neighbor : adjList[currentNode]) {
                    // Explore neighbors
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        nodesQueue.push(neighbor);
                    }
                }
            }
            if (!nodesQueue.empty()) maximumDistance++;
        }
        return {farthestNode, maximumDistance};
    }
};

/* 
Intuition

    - The diameter of a tree is the longest path between two nodes.
    - An optimized method calculates the diameter using two BFS traversals:
    1. Find the farthest node from an arbitrary starting node.
    2. Use this farthest node to find the other endpoint of the diameter.
    - To merge two trees, the combined diameter includes:
    - Half the diameter of each tree (rounded up) plus one edge connecting the trees.

Algorithm

    1. **Calculate Node Count**:
    - Number of nodes = number of edges + 1.

    2. **Build Adjacency List**:
    - Construct adjacency lists for efficient graph traversal.

    3. **Calculate Tree Diameters**:
    - Use two BFS traversals per tree:
        1. Find the farthest node (first endpoint of the diameter).
        2. Calculate the diameter from this node.

    4. **Calculate Combined Diameter**:
    \[
    \text{Combined Diameter} = \lceil \text{Diameter}_1 / 2 \rceil + \lceil \text{Diameter}_2 / 2 \rceil + 1
    \]

    5. **Return Result**:
    - Maximum of:
        - Diameter of the first tree.
        - Diameter of the second tree.
        - Combined diameter.

Complexity Analysis

    Let n be the number of nodes in the first tree and m the number of nodes in the second tree.

    Time complexity: O(n+m)

        To calculate the diameter of a tree, we perform two BFS calls using the findFarthestNode function. Each BFS visits every node and edge exactly once, and since 
        the number of edges is k−1=O(k) for a tree of size k, the time complexity of one BFS is O(k). Thus, finding the diameter of the first tree takes O(n), and for 
        the second tree, it takes O(m), as each involves two BFS calls.

        The combined diameter of the tree is calculated using constant-time operations like addition and comparison, contributing O(1) to the overall time complexity of 
        O(n+m).

    Space complexity: O(n+m)

        All the data structures used in the algorithm, including the adjacency lists, the visited array, and the nodesQueue, have linear space complexity in terms of 
        the size of the tree being processed. Therefore, the total space complexity is O(n+m).
 */