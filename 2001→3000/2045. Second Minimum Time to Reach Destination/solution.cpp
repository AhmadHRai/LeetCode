#include <vector>
#include <deque>
#include <limits>

inline const auto optimize = []() {
    std::ios::sync_with_stdio(false); // Disable synchronization with C I/O for faster input/output
    std::cin.tie(nullptr);            // Untie cin from cout to improve input performance
    std::cout.tie(nullptr);           // Untie cout from cin to improve output performance
    return 0;
}();

class Solution {
    // Helper function to compute the time required for a certain number of trips
    static constexpr int howLong(int needed, int time, int change) {
        int ans = 0; // Variable to accumulate the total time required
        for (int i = 0; i < needed; i++) { // Loop over the number of required trips
            int turn = ans / change; // Determine how many complete change periods have elapsed
            if ((turn % 2) != 0) // Check if currently in the "red" period of the traffic light
                ans += change - (ans % change); // Wait until the light turns green

            ans += time; // Add the time for one trip
        }
        return ans; // Return the total time required
    }
public:
    // Function to find the second minimum time to reach the target node
    static int secondMinimum(int N, const std::vector<std::vector<int>>& edges, int time, int change) {
        // Create adjacency list representation of the graph
        std::vector<std::vector<int>> G(N);
        for (const auto& edge : edges) {
            G[edge[0] - 1].push_back(edge[1] - 1); // Add edge in the graph (0-indexed)
            G[edge[1] - 1].push_back(edge[0] - 1); // Add reverse edge for undirected graph
        }

        std::deque<int> Q; // Deque for BFS traversal
        std::vector<char> seen(N * 2); // Array to keep track of visited nodes for both odd and even waves
        Q.push_front(0); // Start BFS from node 0
        seen[0] = true;  // Mark the starting node as visited

        int maxLength = std::numeric_limits<int>::max(); // Variable to store the length of the second shortest path

        int wave = 0; // Wave counter to track the level of BFS
        bool odd = true; // Boolean flag to alternate between odd and even levels
        while (!Q.empty()) { // BFS loop until queue is empty
            const int thisRound = Q.size(); // Number of nodes at the current wave level
            odd = !odd; // Toggle odd/even flag for current wave
            for (int i = 0; i < thisRound; i++) { // Process all nodes at the current wave level
                auto pos = Q.front(); // Get the current node
                Q.pop_front(); // Remove the node from the queue

                if (pos == N - 1) { // If the target node is reached
                    if (maxLength == std::numeric_limits<int>::max()) { // If it's the first time reaching the target
                        maxLength = wave + 2; // Set maxLength to the length of the first shortest path + 1
                        continue; // Continue to find the second minimum
                    } else {
                        maxLength = std::min(maxLength, wave); // Update maxLength with the second shortest path
                        return howLong(maxLength, time, change); // Compute and return the result
                    }
                }

                for (const auto next : G[pos]) { // Explore all adjacent nodes
                    if (seen[next * 2 + !odd]) // If the adjacent node has already been visited in the current wave
                        continue; // Skip the node

                    seen[next * 2 + !odd] = true; // Mark the adjacent node as visited
                    Q.push_back(next); // Add the node to the queue for further exploration
                }
            }
            wave++; // Increment wave counter

            if (maxLength < wave) // If we have found the second minimum path length
                break; // Exit the loop
        }

        return howLong(maxLength, time, change); // Compute and return the result based on maxLength
    }
};

/*
Approach:
1. **Graph Representation**:
   - **Graph Construction**: Build an undirected graph using adjacency lists from the given edges.
   - **BFS Initialization**: Use a deque to perform a BFS traversal from the source node (node 0). Track visited nodes with a boolean array to handle two states (odd and even waves).

2. **BFS Traversal**:
   - **Wave Processing**: Process nodes level by level. Toggle between odd and even waves to simulate traffic light changes.
   - **Path Length Calculation**: Track the length of the shortest and second shortest paths to the target node (node N-1).

3. **Time Calculation**:
   - **Time Calculation**: Use the `howLong` function to calculate the total time required to make the required trips, considering traffic light changes.

Complexity Analysis:
1. **Graph Construction**:
   - **Time Complexity**: O(E), where E is the number of edges. Each edge is processed once to build the graph.
   - **Space Complexity**: O(N + E), where N is the number of nodes and E is the number of edges. This space is used for the adjacency list and visited array.

2. **BFS Traversal**:
   - **Time Complexity**: O(N + E), where N is the number of nodes and E is the number of edges. Each node and edge is processed once during the BFS traversal.
   - **Space Complexity**: O(N), for the deque and the visited array.

3. **Time Calculation**:
   - **Time Complexity**: O(1), as it involves a fixed number of arithmetic operations.
   - **Space Complexity**: O(1), as it uses a fixed amount of space for calculations.

4. **Overall Complexity**:
   - **Time Complexity**: O(N + E), which is dominated by the BFS traversal.
   - **Space Complexity**: O(N + E), which includes space for the graph representation and BFS traversal.
*/
