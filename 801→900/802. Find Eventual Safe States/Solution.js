/**
 * Finds all eventual safe nodes in a graph.
 * @param {number[][]} graph
 * @return {number[]}
 */
var eventualSafeNodes = function (graph) {
  // Initialize an array to store safe nodes
  let results = [];

  // Use an object to keep track of visited nodes
  let visited = {};

  // Iterate over each node in the graph
  for (let i = 0; i < graph.length; i++) {
    // Check if the current node is safe
    if (isNodeSafe(graph, i, visited)) {
      // If safe, add it to the results array
      results.push(i);
    }
  }

  // Return the sorted array of safe nodes
  return results.sort((a, b) => a - b);
};

// Checks if a node is safe by performing DFS
function isNodeSafe(graph, node, visited) {
  // If the node is marked as visited (part of a cycle), it's not safe
  if (visited[node] === true) {
    return false;
  }

  // If the node is marked as safe, return true
  if (visited[node] === "safe") {
    return true;
  }

  // Mark the node as visited (part of the current path)
  visited[node] = true;

  // Check all neighbors of the node
  for (let i = 0; i < graph[node].length; i++) {
    // If any neighbor is not safe, the current node is not safe
    if (!isNodeSafe(graph, graph[node][i], visited)) {
      return false;
    }
  }

  // If all neighbors are safe, mark the node as safe
  visited[node] = "safe";

  return true;
}
/*
Approach Summary:
This solution uses DFS to identify safe nodes in a graph. A node is considered safe if it does not lead to a cycle. The `isNodeSafe` function checks each node's neighbors recursively and marks nodes as safe or part of a cycle based on the results.

Complexity Analysis:
- Time Complexity: O(N + E), where N is the number of nodes and E is the number of edges, because each node and edge is visited once.
- Space Complexity: O(N), for the `visited` object.
*/
