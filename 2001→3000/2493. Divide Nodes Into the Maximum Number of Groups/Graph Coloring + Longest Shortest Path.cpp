class Solution {
    public:
        // Main function to calculate the maximum number of magnificent sets
        int magnificentSets(int n, vector<vector<int>> &edges) {
            vector<vector<int>> adjList(n);
            for (auto edge : edges) {
                // Transition to 0-index
                adjList[edge[0] - 1].push_back(edge[1] - 1);
                adjList[edge[1] - 1].push_back(edge[0] - 1);
            }
    
            vector<int> colors(n, -1);
            for (int node = 0; node < n; node++) {
                if (colors[node] != -1) continue;
                // Start coloring from uncolored nodes
                colors[node] = 0;
                // If the graph is not bipartite, return -1
                if (!isBipartite(adjList, node, colors)) return -1;
            }
    
            // Calculate the longest shortest path for each node
            vector<int> distances(n);
            for (int node = 0; node < n; node++) {
                distances[node] = getLongestShortestPath(adjList, node, n);
            }
    
            // Calculate the total maximum number of groups across all components
            int maxNumberOfGroups = 0;
            vector<bool> visited(n, false);
            for (int node = 0; node < n; node++) {
                if (visited[node]) continue;
                // Add the number of groups for this component to the total
                maxNumberOfGroups += getNumberOfGroupsForComponent(
                    adjList, node, distances, visited);
            }
    
            return maxNumberOfGroups;
        }
    
    private:
        // Checks if the graph is bipartite starting from the given node
        bool isBipartite(vector<vector<int>> &adjList, int node,
                         vector<int> &colors) {
            for (int neighbor : adjList[node]) {
                // If a neighbor has the same color as the current node, the graph
                // is not bipartite
                if (colors[neighbor] == colors[node]) return false;
    
                // If the neighbor is already colored, skip it
                if (colors[neighbor] != -1) continue;
    
                // Assign the opposite color to the neighbor
                colors[neighbor] = (colors[node] + 1) % 2;
    
                // Recursively check bipartiteness for the neighbor; return false if
                // it fails
                if (!isBipartite(adjList, neighbor, colors)) return false;
            }
            // If all neighbors are properly colored, return true
            return true;
        }
    
        // Computes the longest shortest path (height) in the graph starting from
        // the source node
        int getLongestShortestPath(vector<vector<int>> &adjList, int srcNode,
                                   int n) {
            // Initialize a queue for BFS and a visited array
            queue<int> nodesQueue;
            vector<bool> visited(n, false);
    
            nodesQueue.push(srcNode);
            visited[srcNode] = true;
            int distance = 0;
    
            // Perform BFS layer by layer
            while (!nodesQueue.empty()) {
                // Process all nodes in the current layer
                int numOfNodesInLayer = nodesQueue.size();
                for (int i = 0; i < numOfNodesInLayer; i++) {
                    int currentNode = nodesQueue.front();
                    nodesQueue.pop();
    
                    // Visit all unvisited neighbors of the current node
                    for (int neighbor : adjList[currentNode]) {
                        if (visited[neighbor]) continue;
                        visited[neighbor] = true;
                        nodesQueue.push(neighbor);
                    }
                }
                // Increment the distance for each layer
                distance++;
            }
            // Return the total distance (longest shortest path)
            return distance;
        }
    
        // Calculates the maximum number of groups for a connected component
        int getNumberOfGroupsForComponent(vector<vector<int>> &adjList, int node,
                                          vector<int> &distances,
                                          vector<bool> &visited) {
            // Start with the distance of the current node as the maximum
            int maxNumberOfGroups = distances[node];
            visited[node] = true;
    
            // Recursively calculate the maximum for all unvisited neighbors
            for (int neighbor : adjList[node]) {
                if (visited[neighbor]) continue;
                maxNumberOfGroups = max(maxNumberOfGroups,
                                        getNumberOfGroupsForComponent(
                                            adjList, neighbor, distances, visited));
            }
            return maxNumberOfGroups;
        }
    };

/* 
Algorithm
    isBipartite(adjList, node, colors) function

        Iterate over the neighbors of node and attempt to assign them the opposite color of node:
            If neighbor already has the same color as node (i.e., colors[neighbor] == colors[node]), return false.
            If neighbor has already been assigned a color (i.e., colors[neighbor] != -1), skip to the next neighbor.
            Assign colors[neighbor] = (colors[node] + 1) % 2.
            Recursively call isBipartite(adjList, neighbor, colors) and return false if the call returns false.
        If all neighbors are successfully assigned the opposite color without conflicts, return true.

    getLongestShortestPath(adjList, srcNode, n) function

        Initialize a queue, nodesQueue and a visited array of size n.
        PushsrcNode into the queue and mark it as visited.
        Initialize distance to 0.
        While the nodesQueue is not empty:
            Initialize numOfNodesInLayer to the size of the queue.
            Process all nodes in the current layer, i.e. for i from 0 to numOfNodesInLayer - 1:
                Pop out the first element from the queue as currentNode.
                For each neighbor of currentNode:
                If the neighbor is visited, skip it.
                Otherwise, mark it as visited and push it into the nodesQueue.
            Increment distance by 1.
        Return distance.

    getNumberOfGroupsForComponent(adjList, node, distances, visited) function

        Initialize maxNumberOfGroups to distances[node].
        Mark the current node as visited.
        Explore the rest of the nodes in the component, i.e. for each neighbor of node:
            If the neighbor is visited, skip it.
            Otherwise, set maxNumberOfGroups to the maximum of its current value and getNumberOfComponentsInGroup(adjList, neighbor, distances, visited).
        Return maxNumberOfGroups.

    In the main magnificentSets(n, edges) function:

        Create the adjList of the graph.
        Create a colors array of size n with all elements initially set to -1.
        For each node of the graph:
            If the node have not been assigned a color, i.e. (colors[node] == -1):
                Fix the color of the first node of the component, i.e. set colors[node] = 0.
                Call isBipartite(adjList, node, colors) to determine if the current component is bipartite. If not, return -1.
        Initialize an array distances to store the length of the longest shortest path from any node to any other.
        Fill the distances array using the getLongestShortestPath function.
        Initialize maxNumberOfGroups to 0 and a visited array with all elements set to false.
        For each node of the graph:
            If node has not been visited:
                Get the number of groups for its component and add it to the total number of groups, i.e. maxNumberOfGroups += getNumberOfGroupsForComponent(adjList, node, distances, visited).
        Return maxNumberOfGroups.

Complexity Analysis
    Let n be the number of nodes in the graph and m the size of the edges array.

    Time complexity: O(n×(n+m))

        To check whether the graph is bipartite, we perform a DFS traversal, assigning a color to each node exactly once and visiting each edge exactly once. Thus, this step has a time complexity of O(n+m).

        Next, calculating the longest shortest path for each node involves n BFS traversals (one for each node as the source), resulting in a time complexity of O(n×(n+m)).

        Finally, another DFS is performed to compute the sum of the longest shortest paths across all components, which adds an additional O(n+m) to the total.

        Overall, the total time complexity is O(n+m)+O(n×(n+m))+O(n+m)=O(n×(n+m)).

    Space complexity: O(n+m)

        Constructing the adjacency list from the list of edges requires O(n+m) space, which is an additional space requirement rather than part of the input itself. Therefore, the total auxiliary space complexity is determined by both the adjacency list and the additional data structures (visited, nodesQueue, colors), all of which take O(n) space. As a result, the overall space complexity is O(n+m).

*/