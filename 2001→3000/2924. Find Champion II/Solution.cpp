class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        // Array to store the in-degree of each team
        vector<int> inDegree(n, 0);
        
        // Build the in-degree array from the edges
        for (const auto& edge : edges) {
            inDegree[edge[1]]++;
        }
        
        // List to store potential champions (teams with in-degree 0)
        vector<int> champions;
        
        // Check each team to see if it has in-degree 0
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                champions.push_back(i);
            }
        }
        
        // If there is exactly one champion, return it, otherwise return -1
        return (champions.size() == 1) ? champions[0] : -1;
    }
};

/*
Approach:
    1. We use an array `inDegree` to track the number of incoming edges for each team. A team with zero incoming edges is a potential champion.
    2. First, we iterate through the given `edges` and update the in-degree for each team (by incrementing the in-degree of the team that is defeated).
    3. Then, we check each team to see if it has no incoming edges (i.e., in-degree of zero). Teams with zero incoming edges are collected into the `champions` list.
    4. If there is exactly one team in the `champions` list, it is the champion. Otherwise, we return `-1`, indicating that there is no unique champion.

Complexity:
    Time Complexity:
    - Building the `inDegree` array takes O(m), where `m` is the number of edges in the graph.
    - Checking all the teams to identify potential champions takes O(n), where `n` is the number of teams.
    - Overall time complexity: O(m + n), where `m` is the number of edges and `n` is the number of teams.

    Space Complexity:
    - The `inDegree` array takes O(n) space to store the in-degree of each team.
    - The `champions` list stores at most `n` teams, so it takes O(n) space.
    - Overall space complexity: O(n), where `n` is the number of teams.
*/