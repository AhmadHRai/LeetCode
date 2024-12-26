// from editorial because I'm not doing hard problems by myself yet
class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1,
                                  vector<vector<int>>& edges2) {
        // Calculate the number of nodes for each tree (number of edges + 1)
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        // Build adjacency lists for both trees
        vector<vector<int>> adjList1 = buildAdjList(n, edges1);
        vector<vector<int>> adjList2 = buildAdjList(m, edges2);

        // Calculate the diameter of both trees
        int diameter1 = findDiameter(n, adjList1);
        int diameter2 = findDiameter(m, adjList2);

        // Output the diameters for debugging (can be removed in production
        // code)
        cout << diameter1 << " " << diameter2 << "\n";

        // Calculate the longest path that spans across both trees.
        int combinedDiameter =
            ceil(diameter1 / 2.0) + ceil(diameter2 / 2.0) + 1;

        return max({diameter1, diameter2, combinedDiameter});
    }

private:
    // Helper function to build an adjacency list from an edge list
    vector<vector<int>> buildAdjList(int size, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(size);
        for (auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        return adjList;
    };

    // Function to find the diameter of a tree using topological sorting
    int findDiameter(int n, vector<vector<int>>& adjList) {
        queue<int> leavesQueue;
        vector<int> degrees(n);
        // Initialize the degree of each node and add leaves (nodes with degree
        // 1) to the queue
        for (int node = 0; node < n; node++) {
            degrees[node] =
                adjList[node].size();  // Degree is the number of neighbors
            if (degrees[node] == 1) {
                leavesQueue.push(node);
            }
        }

        int remainingNodes = n;
        int leavesLayersRemoved = 0;

        // Process the leaves until there are 2 or fewer nodes remaining
        while (remainingNodes > 2) {
            int size = leavesQueue.size();  // Get the number of leaves to
                                            // remove in this iteration
            remainingNodes -= size;
            leavesLayersRemoved++;

            // Remove the leaves from the queue and update the degrees of their
            // neighbors
            for (int i = 0; i < size; i++) {
                int currentNode = leavesQueue.front();
                leavesQueue.pop();

                // Process the neighbors of the current leaf
                for (int neighbor : adjList[currentNode]) {
                    degrees[neighbor]--;  // Decrease the degree of the neighbor
                    if (degrees[neighbor] == 1) {
                        leavesQueue.push(
                            neighbor);  // If the neighbor becomes a leaf, add
                                        // it to the queue
                    }
                }
            }
        }

        // If exactly two nodes remain, return the diameter as twice the number
        // of layers of leaves removed + 1 (as the diameter will include the
        // final connecting edge)
        if (remainingNodes == 2) return 2 * leavesLayersRemoved + 1;

        return 2 * leavesLayersRemoved;
    }
};

/* 
Intuition:

    The goal is to find the minimum diameter of a new tree formed by merging two separate trees. The diameter of a tree is the longest path between two nodes, and it 
    must end at leaf nodes. The approach simplifies the problem by:

    - Identifying Leaves: Removing leaf nodes progressively shrinks the tree until one or two nodes remain, which determines the diameter.
    - Combining Trees: The combined diameter accounts for the diameters of both trees and the edge that connects them.
    - Optimizing Calculation: The new diameter is calculated as the maximum of:
        Diameter of Tree 1
        Diameter of Tree 2
        Combined diameter: the sum of half the diameters of both trees plus 1 (for the merging edge).

Algorithm:

    Calculate Node Count:
        Determine the number of nodes in each tree based on their edge count.

    Build Adjacency List:
        Represent each tree as an adjacency list for efficient traversal.

    Calculate Tree Diameters:
        Use a topological sorting technique to iteratively remove leaves and find the diameter for each tree.

    Combine Diameters:
        Calculate the combined diameter using the formula:
        combinedDiameter=⌈diameter1/2⌉+⌈diameter2/2⌉+1
        combinedDiameter=⌈diameter1/2⌉+⌈diameter2/2⌉+1

    Return the Maximum Diameter:
        The result is the maximum of the two tree diameters and the combined diameter.

Complexity Analysis

    Let n be the number of nodes in the first tree and m the number of nodes in the second tree.

    Time complexity: O(n+m)

        In the findDiameter function, each node is added and removed from the leavesQueue once. Each edge is processed once when updating the degrees of neighboring 
        nodes. Therefore, the time complexity is O(k), where k is the size of the input tree. Consequently, calculating the diameter for both trees takes O(n+m) time.

        The calculation of the diameter of the combined tree involves only a few constant-time operations, such as adding and comparing values. This step contributes O
        (1) to the total time complexity, which is still O(n+m).

    Space complexity: O(n+m)

        Similar to the first approach, all the data structures used (adjacency lists, leavesQueue and,the degrees array), have a linear space complexity in terms of the 
        size of the tree being processed. Therefore, the total space complexity is O(n+m).

 */