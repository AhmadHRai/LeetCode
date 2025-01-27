class Solution {
    public:
        // Iterate over each node and perform BFS starting from it.
        // Mark the starting node as a prerequisite to all the nodes in the BFS
        // traversal.
        void preprocess(int numCourses, vector<vector<int>>& prerequisites,
                        unordered_map<int, vector<int>>& adjList,
                        vector<vector<bool>>& isPrerequisite) {
            for (int i = 0; i < numCourses; i++) {
                queue<int> q;
                q.push(i);
    
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
    
                    for (auto adj : adjList[node]) {
                        // If we have marked i as a prerequisite of adj it implies
                        // we have visited it. This is equivalent to using a visited
                        // array.
                        if (!isPrerequisite[i][adj]) {
                            isPrerequisite[i][adj] = true;
                            q.push(adj);
                        }
                    }
                }
            }
        }
    
        vector<bool> checkIfPrerequisite(int numCourses,
                                         vector<vector<int>>& prerequisites,
                                         vector<vector<int>>& queries) {
            unordered_map<int, vector<int>> adjList;
            for (auto edge : prerequisites) {
                adjList[edge[0]].push_back(edge[1]);
            }
    
            vector<vector<bool>> isPrerequisite(numCourses,
                                                vector<bool>(numCourses, false));
            // Store the prerequisite for each node in the array.
            preprocess(numCourses, prerequisites, adjList, isPrerequisite);
    
            vector<bool> answer;
            for (auto q : queries) {
                answer.push_back(isPrerequisite[q[0]][q[1]]);
            }
    
            return answer;
        }
    };

/* 
Algorithm

    Construct an adjacency list adjList from the prerequisites list where each course points to the courses that depend on it.

    Preprocessing (BFS from each node):
        For each node i (from 0 to N - 1):

            Start a BFS from i to explore all reachable nodes.

            Repeat the following while the queue is not empty:
                Pop the front in the queue as node.
                Iterate over the adjacent node and if the node i is not already marked as its prerequisite, mark it and add node to the queue.

    For each query [u, v] return isPrerequisite[u][v].

Complexity Analysis
    Let N be the number of courses (numCourses) and let Q be the size of the queries list. In the worst case, the size of the prerequisites list can grow up to N⋅(N−1)/2​, when every course is a prerequisite for every other course, forming a complete directed graph.

    Time complexity: O(N^3+Q).

    Creating the adjacency list adjList requires O(N^2) time, as we need to iterate over the prerequisites list. Next, we perform BFS starting from each of the N nodes. Each BFS traversal takes O(N^2) in the worst case, as the time complexity of BFS is O(V+E). Therefore, the total preprocessing is O(N⋅N^2)=O(N^3).

    To answer each query, we can retrieve results in constant time from a precomputed map, so answering all Q queries takes O(Q) time. Thus, the total time complexity will be O(N^3+Q).

    Space complexity: O(N^2)

    The adjacency list takes O(N^2) space as it will store every edge in the list prerequisites. For BFS, we need a 2D array isPrerequisite with size O(N^2) to store the answer for every pair of nodes. The queue required for the BFS will take O(N) size for each node, hence the total space complexity is equal to O(N^2).

*/