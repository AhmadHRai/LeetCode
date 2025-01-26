class Solution {
    public:
        // Returns the maximum number of invitations based on cycles in the favorite graph
        int maximumInvitations(vector<int>& favorite) {
            int n = favorite.size();
            
            // Build a reversed graph where each node points to those who favor it
            vector<vector<int>> reversedGraph(n);
            for (int person = 0; person < n; ++person) {
                reversedGraph[favorite[person]].push_back(person);
            }
    
            // Helper function for BFS to find the maximum distance from a node
            auto bfs = [&](int startNode, unordered_set<int>& visitedNodes) -> int {
                queue<pair<int, int>> q;
                q.push({startNode, 0});
                int maxDistance = 0;
                while (!q.empty()) {
                    auto [currentNode, currentDistance] = q.front();
                    q.pop();
                    for (int neighbor : reversedGraph[currentNode]) {
                        if (visitedNodes.count(neighbor)) continue; // Skip visited nodes
                        visitedNodes.insert(neighbor);
                        q.push({neighbor, currentDistance + 1});
                        maxDistance = max(maxDistance, currentDistance + 1);
                    }
                }
                return maxDistance;
            };
    
            int longestCycle = 0, twoCycleInvitations = 0;
            vector<bool> visited(n, false);
    
            // Find all cycles in the graph
            for (int person = 0; person < n; ++person) {
                if (!visited[person]) {
                    unordered_map<int, int> visitedPersons;
                    int current = person;
                    int distance = 0;
                    while (true) {
                        if (visited[current]) break; // Already visited, stop exploring
                        visited[current] = true;
                        visitedPersons[current] = distance++;
                        int nextPerson = favorite[current];
                        if (visitedPersons.count(nextPerson)) {  // Cycle detected
                            int cycleLength = distance - visitedPersons[nextPerson];
                            longestCycle = max(longestCycle, cycleLength);
                            if (cycleLength == 2) {
                                // For cycles of length 2, calculate additional invitations
                                unordered_set<int> visitedNodes = {current, nextPerson};
                                twoCycleInvitations +=
                                    2 + bfs(nextPerson, visitedNodes) +
                                    bfs(current, visitedNodes);
                            }
                            break;
                        }
                        current = nextPerson;
                    }
                }
            }
    
            // Return the maximum between the longest cycle and invitations from cycles of length 2
            return max(longestCycle, twoCycleInvitations);
        }
    }
    /*
    Approach Summary:
    This solution involves building a reversed graph from the favorite relationships and then detecting cycles within it. It calculates the maximum number of invitations by 
    considering both the longest cycle and the additional invitations from cycles of length 2.
    
    Complexity Analysis:
    - Time Complexity: O(N + E), where N is the number of people and E is the number of edges (favorite relationships), because each node and edge is visited once.
    - Space Complexity: O(N), for storing the reversed graph and visited nodes.
    */
    