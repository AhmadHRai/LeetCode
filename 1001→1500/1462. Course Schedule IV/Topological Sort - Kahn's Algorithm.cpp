class Solution {
    public:
        vector<bool> checkIfPrerequisite(int numCourses,
                                         vector<vector<int>>& prerequisites,
                                         vector<vector<int>>& queries) {
            unordered_map<int, vector<int>> adjList;
            vector<int> indegree(numCourses, 0);
            for (auto edge : prerequisites) {
                adjList[edge[0]].push_back(edge[1]);
                indegree[edge[1]]++;
            }
    
            queue<int> q;
            for (int i = 0; i < numCourses; i++) {
                if (!indegree[i]) {
                    q.push(i);
                }
            }
    
            // Map from the node as key to the set of prerequisite nodes.
            unordered_map<int, unordered_set<int>> nodePrerequisites;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
    
                for (auto adj : adjList[node]) {
                    // Add node and prerequisite of node to the prerequisites of adj
                    nodePrerequisites[adj].insert(node);
                    for (auto prereq : nodePrerequisites[node]) {
                        nodePrerequisites[adj].insert(prereq);
                    }
    
                    indegree[adj]--;
                    if (!indegree[adj]) {
                        q.push(adj);
                    }
                }
            }
    
            vector<bool> answer;
            for (auto q : queries) {
                answer.push_back(nodePrerequisites[q[1]].contains(q[0]));
            }
    
            return answer;
        }
    };

/* 
Algorithm

    Create an adjacency list (adjList) to store the directed graph representing course dependencies.

    Initialize an array (indegree) to track the number of prerequisites (in-degree) for each course.

    Iterate over the prerequisites array to populate the adjacency list and update the indegree for each course.

    Initialize a queue (q) to process courses with zero in-degree (no prerequisites).

    While the queue is not empty:
        Dequeue a course (node).
        For each adjacent course (adj) in the adjacency list of nodes, add the prerequisites of node to the list nodePrerequisites[adj].
        Decrement the in-degree of the node adj, and if the in-degree becomes zero, enqueue it for further processing.

    For each query (u, v), check if course u is in the prerequisite list of course v by checking nodePrerequisites[v].

Complexity Analysis
    Let N be the number of courses (numCourses) and let Q be the size of the queries list. In the worst case, the size of the prerequisites list can grow up to N⋅(N−1)/2​, when 
    every course is a prerequisite for every other course, forming a complete directed graph.

    Time complexity: O(N^3+Q).

    Creating the adjacency list adjList takes O(N^2) time as we need to iterate over the list prerequisites. The array indegree will be of size O(N). In Kahn's algorithm, we 
    iterate over each node and edge of the vertex which is O(N^2) and for each edge traversed we will also add the prerequisites to the next node which is another O(N). To 
    answer each query we need constant time to retrieve from the map and hence it's O(Q) to answer all queries. Hence, the total time complexity equals O(N^3+Q).

    Space complexity: O(N^2)

    List adjList takes O(N^2) as it will store every edge in the list prerequisites. Array indegree will take O(N) space and the queue for Kahn's algorithm will also be O(N) 
    size. Map nodePrerequisites will be from the node to its prerequisites and thus the total number of entries can be equal to O(N^2). Hence the total space complexity equals O
    (N^2).

*/