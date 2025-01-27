class Solution {
    public:
        vector<bool> checkIfPrerequisite(int numCourses,
                                         vector<vector<int>>& prerequisites,
                                         vector<vector<int>>& queries) {
            vector<vector<bool>> isPrerequisite(numCourses,
                                                vector<bool>(numCourses, false));
            for (auto edge : prerequisites) {
                isPrerequisite[edge[0]][edge[1]] = true;
            }
    
            for (int intermediate = 0; intermediate < numCourses; intermediate++) {
                for (int src = 0; src < numCourses; src++) {
                    for (int target = 0; target < numCourses; target++) {
                        // If src -> intermediate & intermediate -> target exists
                        // then src -> target will also exist.
                        isPrerequisite[src][target] =
                            isPrerequisite[src][target] ||
                            (isPrerequisite[src][intermediate] &&
                             isPrerequisite[intermediate][target]);
                    }
                }
            }
    
            vector<bool> answer;
            for (auto q : queries) {
                answer.push_back(isPrerequisite[q[0]][q[1]]);
            }
    
            return answer;
        }
    };

/* 
Algorithm

    Initialize a 2D boolean array isPrerequisite of size numCourses x numCourses to track direct prerequisite relationships between courses.

    Populate the isPrerequisite matrix based on the prerequisites:

    For each pair in prerequisites, mark isPrerequisite[edge[0]][edge[1]] as true to indicate that edge[0] is a prerequisite for edge[1].

    Compute transitive closure of the prerequisite relationships using the Floyd-Warshall algorithm:

    For each possible intermediate course intermediate:
        For each source course src:
            For each target course target:
                Update isPrerequisite[src][target] to include indirect relationships:
                    If src can reach intermediate and intermediate can reach target, then src can reach target.

    Initialize an empty list answer to store the results of the queries.

    For each query in queries:

    Add the value of isPrerequisite[query[0]][query[1]] to the answer list, indicating whether query[0] is a prerequisite for query[1].

    Return the answer list containing the results for all queries.

Complexity Analysis
    Let N be the number of courses (numCourses) and let Q be the size of the queries list. In the worst case, the size of the prerequisites list can grow up to N⋅(N−1)/2​, when every course is a prerequisite for every other course, forming a complete directed graph.

    Time complexity: O(N^3+Q).
        We iterate over each node in three nested loops, so this step takes O(N^3). To answer each query we need constant time to retrieve from the map and hence it's O(Q) to answer all queries. Hence, the total time complexity equals O(N^3+Q).

    Space complexity: O(N^2)
        We need a 2D array isPrerequisite with size O(N^2) to store the answer for every pair of nodes, hence the total space complexity is equal to O(N^2).
*/