class Solution {
    public:
        // Performs DFS and returns true if there's a path between src and target
        // and false otherwise.
        bool isPrerequisite(unordered_map<int, vector<int>>& adjList,
                            vector<bool>& visited, int src, int target) {
            visited[src] = 1;
    
            if (src == target) {
                return true;
            }
    
            int answer = false;
            for (auto adj : adjList[src]) {
                if (!visited[adj]) {
                    answer =
                        answer || isPrerequisite(adjList, visited, adj, target);
                }
            }
            return answer;
        }
    
        vector<bool> checkIfPrerequisite(int numCourses,
                                         vector<vector<int>>& prerequisites,
                                         vector<vector<int>>& queries) {
            unordered_map<int, vector<int>> adjList;
            for (auto edge : prerequisites) {
                adjList[edge[0]].push_back(edge[1]);
            }
    
            vector<bool> answer;
            for (auto q : queries) {
                // Reset the visited array for each query.
                vector<bool> visited(numCourses, false);
                answer.push_back(isPrerequisite(adjList, visited, q[0], q[1]));
            }
    
            return answer;
        }
    };

/* 
Algorithm

    Define a function isPrerequisite that takes the adjacency list of the graph, a visited array, and two nodes src and target, and returns whether a path exists from src to target:
        Mark the current node src as visited.
        If src is the same as target, return true (we found the path).
        For each neighboring node adj of src:
            If adj has not been visited yet, recursively call the DFS to check if a path exists from adj to target.
        Return the true if the result of at least one recursive call is true and false otherwise.

    Create the adjacency list adjList using the prerequisite pairs [u, v].

    For each query [u, v], check if there is a path from u to v using DFS:
        Initialize a visited array with all entries as false
        Call the isPrerequisite function to check if there exists a path from u to v.
        Store the result for each query in a result list answer.

    Return answer.

Complexity Analysis
    Let N be the number of courses (numCourses) and let Q be the size of the queries list. In the worst case, the size of the prerequisites list can grow up to 2N⋅(N−1)​, when 
    every course is a prerequisite for every other course, forming a complete directed graph.

    Time complexity: O(Q⋅N^2).

    Creating the adjacency list adjList takes O(N^2) time as we need to iterate over the list prerequisites. Then we iterate over queries and for each we perform DFS that can take O(V+E) which is equivalent to O(N^2). Hence, the total time complexity equals O(Q⋅N^2).

    Space complexity: O(N^2)

    The adjacency list requires O(N^2) as it stores every edge in the list prerequisites. For the DFS traversal, we need a visited array of size O(N) and the recursive stack for DFS calls requires O(N) space in the worsts case. Therefore, the total space complexity is equal to O(N^2)
*/