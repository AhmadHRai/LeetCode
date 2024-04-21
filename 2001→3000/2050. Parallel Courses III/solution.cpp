class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> graph(n);

        for (const vector<int>& relation : relations) {
            int prev = relation[0] - 1;
            int next = relation[1] - 1;
            graph[prev].push_back(next);
        }

        vector<int> memo(n, -1);

        function<int(int)> calculateTime = [&](int course) {
            if (memo[course] != -1) {
                return memo[course];
            }

            if (graph[course].empty()) {
                memo[course] = time[course];
                return memo[course];
            }

            int maxPrerequisiteTime = 0;
            for (int prereq : graph[course]) {
                maxPrerequisiteTime = max(maxPrerequisiteTime, calculateTime(prereq));
            }

            memo[course] = maxPrerequisiteTime + time[course];
            return memo[course];
        };

        int overallMinTime = 0;
        for (int course = 0; course < n; course++) {
            overallMinTime = max(overallMinTime, calculateTime(course));
        }

        return overallMinTime;
    }
};

/*
DFS + Memoization (Top-Down DP): 
1. Create a graph to represent the prerequisites using an adjacency list.
2. Create a memoization table (an array) to store the minimum time needed to complete each course.
3. Define a recursive function to calculate the minimum time to complete a course:

    a. If the course has already been calculated, return its value from the memoization table.
    b. If the course has no prerequisites, its time is simply its own duration.
    c. Otherwise, calculate the time to complete this course as the maximum time among its prerequisites plus its own duration.
    d. Store this calculated time in the memoization table and return it.

4. Initialize a variable to keep track of the overall minimum time.
5. For each course, calculate its minimum time using the recursive function and update the overall minimum time if necessary.
6. The overall minimum time is the answer.


Time and Space Complexity Analysis: 
    Time Complexity: O(V+E), where V is the number of courses and E is the number of prerequisite relations. The memoization table ensures that each course's time is calculated only once.
    Space Complexity: O(V)) for the memoization table and O(E) for the graph.

 */