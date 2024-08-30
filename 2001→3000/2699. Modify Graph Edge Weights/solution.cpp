class Solution {
public:
    // Function to modify the graph edges so that the shortest path from source to destination is exactly target
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        vector<vector<pair<int, int>>> adjacencyList(n); // Adjacency list for the graph
        for (int i = 0; i < edges.size(); i++) {
            int nodeA = edges[i][0], nodeB = edges[i][1];
            adjacencyList[nodeA].emplace_back(nodeB, i); // Store the edge index for each neighbor
            adjacencyList[nodeB].emplace_back(nodeA, i); // Store the edge index for each neighbor
        }

        vector<vector<int>> distances(n, vector<int>(2, INT_MAX)); // Distance array for 0 and 1 modification states
        distances[source][0] = distances[source][1] = 0; // Distance to source is 0 for both states

        // Run Dijkstra's algorithm for the shortest path with no modifications
        runDijkstra(adjacencyList, edges, distances, source, 0, 0);
        int difference = target - distances[destination][0]; // Calculate the difference needed to meet the target
        if (difference < 0) return {}; // If target is unreachable, return an empty vector

        // Run Dijkstra's algorithm to find if it's possible to meet the target with modification
        runDijkstra(adjacencyList, edges, distances, source, difference, 1);
        if (distances[destination][1] < target) return {}; // If the target is not achievable, return an empty vector

        // Modify the edges with weight -1 to 1 where necessary
        for (auto& edge : edges) {
            if (edge[2] == -1) edge[2] = 1;
        }
        return edges; // Return the modified edges
    }

private:
    // Helper function to run Dijkstra's algorithm
    void runDijkstra(const vector<vector<pair<int, int>>>& adjacencyList, vector<vector<int>>& edges, vector<vector<int>>& distances, int source, int difference, int run) {
        int n = adjacencyList.size(); // Number of nodes
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> priorityQueue; // Min-heap priority queue
        priorityQueue.push({0, source}); // Start with the source node
        distances[source][run] = 0; // Initialize distance to source

        while (!priorityQueue.empty()) {
            auto [currentDistance, currentNode] = priorityQueue.top(); // Get the node with the smallest distance
            priorityQueue.pop();

            if (currentDistance > distances[currentNode][run]) continue; // Skip if this is not the shortest path

            for (auto& neighbor : adjacencyList[currentNode]) {
                int nextNode = neighbor.first, edgeIndex = neighbor.second;
                int weight = edges[edgeIndex][2];

                if (weight == -1) weight = 1; // Default weight for -1 edges

                // If modifying edges, calculate new weight and update if it's better
                if (run == 1 && edges[edgeIndex][2] == -1) {
                    int newWeight = difference + distances[nextNode][0] - distances[currentNode][1];
                    if (newWeight > weight) {
                        edges[edgeIndex][2] = weight = newWeight;
                    }
                }

                // Update the distance to the next node if a shorter path is found
                if (distances[nextNode][run] > distances[currentNode][run] + weight) {
                    distances[nextNode][run] = distances[currentNode][run] + weight;
                    priorityQueue.push({distances[nextNode][run], nextNode});
                }
            }
        }
    }
};

// Fast I/O for competitive programming
static const auto fast = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

/*
Approach Summary:
- Use Dijkstra's algorithm to compute the shortest path from the source to destination with no modifications.
- Calculate the difference needed to reach the target distance.
- Run Dijkstra's algorithm again to see if this difference can be achieved by modifying edge weights.
- Modify edges with weight -1 to 1 where necessary to achieve the target distance.

Time Complexity:
- O((E + V) log V), where E is the number of edges and V is the number of vertices. Dijkstra's algorithm is run twice, each with O((E + V) log V) complexity.

Space Complexity:
- O(V + E), where V is the number of vertices and E is the number of edges. Space is used for the adjacency list, distance arrays, and the priority queue.
*/
