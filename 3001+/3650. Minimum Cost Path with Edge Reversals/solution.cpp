class Solution {
public:
    // Graph representation where each node points to a list of edges (destination, cost)
    vector<vector<pair<int, int>>> graph;

    // Dijkstra's algorithm to find the shortest path from node 0 to node n-1
    int findShortestPath(int numNodes) {
        vector<bool> visited(numNodes, false);  // To track visited nodes
        vector<int> distance(numNodes, INT_MAX);  // To store the minimum cost to reach each node

        // Priority queue to process nodes in order of their distance from the source (min-heap)
        priority_queue<pair<int, int>> minHeap;  // {distance, node}
        minHeap.push({0, 0});  // Starting from node 0 with a cost of 0
        distance[0] = 0;

        while (!minHeap.empty()) {
            int currentNode = minHeap.top().second;  // The node with the current shortest distance
            minHeap.pop();

            // Skip if the node has already been processed
            if (visited[currentNode]) continue;
            visited[currentNode] = true;

            // Process all neighbors of the current node
            for (const auto& [neighbor, edgeCost] : graph[currentNode]) {
                int newDistance = distance[currentNode] + edgeCost;

                // If a shorter path to the neighbor is found, update the distance
                if (newDistance < distance[neighbor]) {
                    distance[neighbor] = newDistance;
                    minHeap.push({-newDistance, neighbor});
                }
            }
        }

        // Return the minimum cost to reach node n-1, or -1 if it's unreachable
        return distance[numNodes - 1] == INT_MAX ? -1 : distance[numNodes - 1];
    }

    int minCost(int n, vector<vector<int>>& edges) {
        // Build the graph
        graph.resize(n);
        for (const auto& edge : edges) {
            int fromNode = edge[0];
            int toNode = edge[1];
            int edgeCost = edge[2];

            // Add directed edge from 'fromNode' to 'toNode' with cost 'edgeCost'
            graph[fromNode].push_back({toNode, edgeCost});

            // Add reverse directed edge from 'toNode' to 'fromNode' with cost '2 * edgeCost' (if switch is used)
            graph[toNode].push_back({fromNode, 2 * edgeCost});
        }

        // Run Dijkstra's algorithm to find the minimum cost from node 0 to node n-1
        return findShortestPath(n);
    }
};
