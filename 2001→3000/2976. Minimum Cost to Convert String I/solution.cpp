#include <vector>
#include <string>
#include <algorithm>

class Solution {
private:
    static constexpr int CHAR_COUNT = 26;   // Total number of characters (a-z)
    static constexpr int INF = 1e9;         // A large number representing infinity

    // Build the conversion graph
    std::vector<std::vector<int>> buildConversionGraph(const std::vector<char>& original, const std::vector<char>& changed, const std::vector<int>& cost) {
        // Initialize graph with infinity
        std::vector<std::vector<int>> graph(CHAR_COUNT, std::vector<int>(CHAR_COUNT, INF));
        for (int i = 0; i < CHAR_COUNT; i++) {
            graph[i][i] = 0; // Zero cost to convert a character to itself
        }
        for (size_t i = 0; i < cost.size(); i++) {
            int from = original[i] - 'a'; // Convert char to index (0-25)
            int to = changed[i] - 'a';   // Convert char to index (0-25)
            // Update the graph with the minimum cost for conversion
            graph[from][to] = std::min(graph[from][to], cost[i]);
        }
        return graph;
    }

    // Optimize the conversion paths using Floyd-Warshall algorithm
    void optimizeConversionPaths(std::vector<std::vector<int>>& graph) {
        for (int k = 0; k < CHAR_COUNT; k++) {
            for (int i = 0; i < CHAR_COUNT; i++) {
                if (graph[i][k] < INF) {
                    for (int j = 0; j < CHAR_COUNT; j++) {
                        if (graph[k][j] < INF) {
                            // Update the shortest path cost
                            graph[i][j] = std::min(graph[i][j], graph[i][k] + graph[k][j]);
                        }
                    }
                }
            }
        }
    }

    // Compute the total cost to convert the source string to the target string
    long long computeTotalConversionCost(const std::string& source, const std::string& target, const std::vector<std::vector<int>>& graph) {
        long long totalCost = 0;
        for (size_t i = 0; i < source.length(); i++) {
            int sourceChar = source[i] - 'a'; // Convert char to index (0-25)
            int targetChar = target[i] - 'a'; // Convert char to index (0-25)
            if (sourceChar != targetChar) {
                if (graph[sourceChar][targetChar] == INF) {
                    return -1; // If conversion is not possible
                }
                totalCost += graph[sourceChar][targetChar];
            }
        }
        return totalCost;
    }

public:
    long long minimumCost(std::string source, std::string target, std::vector<char>& original, std::vector<char>& changed, std::vector<int>& cost) {
        auto conversionGraph = buildConversionGraph(original, changed, cost); // Build graph
        optimizeConversionPaths(conversionGraph); // Optimize paths
        return computeTotalConversionCost(source, target, conversionGraph); // Compute total cost
    }
};

/*
Approach:
1. **Graph Representation**:
   - **Graph Construction**: Create a graph where nodes represent characters ('a' to 'z'). Each edge between two nodes has a weight that represents the cost of converting one character to another.
   - **Floyd-Warshall Algorithm**: Apply this algorithm to find the shortest path between all pairs of nodes. This ensures that we account for both direct and indirect conversions.

2. **Conversion Calculation**:
   - **Cost Calculation**: After optimizing the graph with the shortest paths, compute the total cost required to convert the `source` string into the `target` string. This is done by summing the costs of converting each character using the optimized graph.

Complexity Analysis:
1. **Graph Construction**:
   - **Time Complexity**: O(C), where C is the number of conversions provided. Each conversion is processed in constant time.
   - **Space Complexity**: O(CHAR_COUNT^2) for the graph matrix, where CHAR_COUNT = 26 (one for each letter of the alphabet). This results in a fixed-size matrix (26x26).

2. **Path Optimization (Floyd-Warshall Algorithm)**:
   - **Time Complexity**: O(CHAR_COUNT^3). Since CHAR_COUNT is a constant (26), this effectively runs in O(1) time with respect to the size of the alphabet.
   - **Space Complexity**: O(CHAR_COUNT^2) for the graph matrix, which remains O(1) due to its fixed size.

3. **Total Conversion Cost Calculation**:
   - **Time Complexity**: O(N), where N is the length of the `source` or `target` string. Each character's conversion cost is computed once.
   - **Space Complexity**: O(1) additional space, as only a few variables are used for computation.

4. **Overall Complexity**:
   - **Time Complexity**: Dominated by the Floyd-Warshall algorithm, which is O(1) due to the fixed size of the graph. The conversion cost calculation is linear with respect to the length of the strings, so the overall time complexity is effectively O(N), where N is the length of the input strings.
   - **Space Complexity**: O(1) additional space, beyond the fixed-size graph matrix and input storage. The space complexity is dominated by the graph matrix, which is constant due to the fixed number of characters.
*/
