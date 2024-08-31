static const int _ = []{cin.tie(0); ios::sync_with_stdio(0); return 0;}(); // Fast I/O for competitive programming

class Solution {
public:
    // Function to find the maximum probability of reaching the end_node from start_node
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> prob(n); // Vector to store the maximum probability to reach each node
        prob[start_node] = 1.0; // Probability to reach the start_node is 1
        
        for (int i = 0; i < n; ++i) {
            bool connected = false; // Flag to check if any updates are made in this iteration
            for (int j = 0; j < edges.size(); ++j) {
                int a = edges[j][0], b = edges[j][1];
                double p = succProb[j]; // Probability of edge from node a to node b
                // Update the probability for node b if a better path through node a is found
                if (prob[a] * p > prob[b]) {
                    prob[b] = prob[a] * p;
                    connected = true;
                }
                // Update the probability for node a if a better path through node b is found
                if (prob[b] * p > prob[a]) {
                    prob[a] = prob[b] * p;
                    connected = true;
                }
            }
            // If no updates were made in this iteration, break out of the loop
            if (!connected) break;
        }
        
        return prob[end_node]; // Return the maximum probability to reach the end_node
    }
};

/*
Approach Summary:
- Use a modified Bellman-Ford approach to calculate the maximum probability of reaching each node.
- Initialize the probability of the start_node to 1 and update the probabilities for other nodes iteratively.
- The algorithm continues until no further updates are made in an iteration.
- Return the maximum probability to reach the end_node.

Time Complexity:
- O(n * E), where n is the number of nodes and E is the number of edges. Each edge is processed in each iteration up to n times.

Space Complexity:
- O(n), where n is the number of nodes. Space is used to store the probability of reaching each node.
*/
