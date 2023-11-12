// This class defines a solution to the problem of designing a graph with a shortest path calculator
// The graph is represented by an adjacency list, where each node has a list of neighbors and their weights
class Graph {
public:
    // This vector stores the adjacency list of the graph
    vector<vector<pair<int, int>>> adj_list;
    // This constructor takes an integer n representing the number of nodes in the graph,
    // and a vector of vectors of integers representing the edges in the graph
    // Each edge is a vector of three integers: the source node, the destination node, and the weight
    Graph(int n, vector<vector<int>>& edges) {
        // This resizes the adjacency list to have n empty vectors
        adj_list.resize(n);
        // This loop iterates over the edges vector and adds each edge to the adjacency list
        for (auto& e: edges)
        // This adds a pair of the destination node and the weight to the source node's vector
        adj_list[e[0]].push_back(make_pair(e[1], e[2]));
    }
    
    // This function takes a vector of three integers representing an edge to be added to the graph
    // It updates the adjacency list with the new edge
    void addEdge(vector<int> edge) {
        // This adds a pair of the destination node and the weight to the source node's vector
        adj_list[edge[0]].push_back(make_pair(edge[1], edge[2]));
    }
    
    // This function takes two integers representing the source node and the destination node
    // It returns the shortest path distance between them, or -1 if there is no path
    int shortestPath(int node1, int node2) {
        // This gets the number of nodes in the graph
        int n = adj_list.size();
        // This creates a priority queue of pairs of integers, where the first element is the distance and the second element is the node
        // The priority queue is ordered by the smallest distance first
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // This creates a vector of integers to store the shortest distance from the source node to each node
        // The vector is initialized with the maximum integer value for each node
        vector<int> dist(n, INT_MAX);
        // This sets the distance of the source node to zero
        dist[node1] = 0;
        // This adds a pair of zero distance and the source node to the priority queue
        pq.push(make_pair(0, node1));
        
        // This loop continues until the priority queue is empty or the destination node is found
        while (!pq.empty()) {
            // This gets the distance and the node at the top of the priority queue
            int d = pq.top().first, node = pq.top().second;
            // This removes the top element from the priority queue
            pq.pop();
            // This checks if the node is the destination node
            if (node == node2)
                // If yes, then return the distance
                return d;
            // This checks if the distance is larger than the current shortest distance for the node
            if (d > dist[node])
                // If yes, then skip this node as it is not optimal
                continue;
            // This loop iterates over the neighbors of the node in the adjacency list
            for (auto& neighbor : adj_list[node]) {
                // This calculates the new distance by adding the current distance and the neighbor's weight
                int new_dist = d + neighbor.second;
                // This checks if the new distance is smaller than the current shortest distance for the neighbor
                if (new_dist < dist[neighbor.first]) {
                    // If yes, then update the shortest distance for the neighbor
                    dist[neighbor.first] = new_dist;
                    // And add a pair of the new distance and the neighbor to the priority queue
                    pq.push(make_pair(new_dist, neighbor.first));
                }
            }
        }
        // If the loop ends without finding the destination node, then return -1
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */

/* 
The time complexity of this solution is O(m + n \log n), where m is the number of edges and n is the number of nodes in the graph. This is because the constructor and the addEdge 
function loop through the edges vector once and perform constant time operations in each iteration, which is O(m). The shortestPath function uses a priority queue to perform a 
Dijkstra’s algorithm, which takes O(m + n \log n) time in the worst case, as each edge is visited once and each node is extracted from the priority queue once.

The space complexity of this solution is O(m + n), where m is the number of edges and n is the number of nodes in the graph. This is because the solution uses an adjacency list to 
store the graph, which takes O(m + n) space, a priority queue to store the nodes and their distances, which takes O(n) space in the worst case, and a vector to store the shortest 
distances, which takes O(n) space.
 */