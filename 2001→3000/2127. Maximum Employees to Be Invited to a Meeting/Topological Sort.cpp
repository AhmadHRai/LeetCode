class Solution {
    public:
        // Returns the maximum number of invitations based on cycles in the favorite graph
        int maximumInvitations(vector<int>& favorite) {
            int n = favorite.size();
            
            // Initialize in-degree array to track incoming edges for each node
            vector<int> inDegree(n, 0);
    
            // Calculate in-degree for each node
            for (int person = 0; person < n; ++person) {
                // Increment in-degree for the person favored by the current person
                inDegree[favorite[person]]++;
            }
    
            // Perform topological sorting to remove nodes not part of cycles
            queue<int> q;
            for (int person = 0; person < n; ++person) {
                // Add nodes with in-degree 0 to the queue (no incoming edges)
                if (inDegree[person] == 0) {
                    q.push(person);
                }
            }
    
            // Initialize depth array to track the depth of each node
            vector<int> depth(n, 1);  
            while (!q.empty()) {
                int currentNode = q.front();
                q.pop();
                int nextNode = favorite[currentNode];
                // Update the depth of the next node if necessary
                depth[nextNode] = max(depth[nextNode], depth[currentNode] + 1);
                // Decrement in-degree of the next node and add it to the queue if it becomes 0
                if (--inDegree[nextNode] == 0) {
                    q.push(nextNode);
                }
            }
    
            int longestCycle = 0;
            int twoCycleInvitations = 0;
    
            // Detect cycles and calculate invitations
            for (int person = 0; person < n; ++person) {
                // Skip nodes already processed (in-degree 0)
                if (inDegree[person] == 0) continue;  
    
                int cycleLength = 0;
                int current = person;
                while (inDegree[current] != 0) {
                    // Mark the current node as visited by setting its in-degree to 0
                    inDegree[current] = 0;  
                    cycleLength++;
                    current = favorite[current];
                }
    
                if (cycleLength == 2) {
                    // For cycles of length 2, add the depth of both nodes to invitations
                    twoCycleInvitations += depth[person] + depth[favorite[person]];
                } else {
                    // Update the longest cycle length if necessary
                    longestCycle = max(longestCycle, cycleLength);
                }
            }
    
            // Return the maximum between the longest cycle and invitations from cycles of length 2
            return max(longestCycle, twoCycleInvitations);
        }
    }
    /*
    Approach Summary:
    This solution involves calculating in-degrees, performing topological sorting to identify nodes not part of cycles, and then detecting cycles to calculate the maximum number of invitations. It considers both the longest cycle and additional invitations from cycles of length 2.
    
    Complexity Analysis:
    - Time Complexity: O(N + E), where N is the number of people and E is the number of edges (favorite relationships), because each node and edge is visited once.
    - Space Complexity: O(N), for storing in-degrees and depths of nodes.
    */
    