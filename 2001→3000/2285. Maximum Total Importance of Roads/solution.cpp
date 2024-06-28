class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long ans = 0, x = 1;  // Initialize variables ans (to store the maximum importance) and x (incremental factor)
        vector<int> degree(n, 0);  // Create a vector to store degrees (number of connections) for each city
        
        // Count degrees for each city based on the roads
        for (auto road : roads) {
            degree[road[0]]++;
            degree[road[1]]++;
        }
        
        // Sort degrees vector in ascending order
        sort(degree.begin(), degree.end());
        
        // Calculate the maximum importance
        for (auto i : degree)
            ans += i * (x++);  // Multiply each degree by its position in sorted order and accumulate to ans // This is genuis
        
        return ans;  // Return the maximum importance
    }
};

/*
Approach:
- Initialize variables ans to store the maximum importance and x as an incremental factor.
- Create a degree vector initialized to zero to store the number of connections (degrees) for each city.
- Iterate through each road pair in the roads vector and increment the degree for both cities involved in the road.
- Sort the degree vector in ascending order to prioritize cities with fewer connections.
- Calculate the maximum importance by iterating through the sorted degree vector. Multiply each degree by its position in the sorted order incremented by x, and accumulate to ans.
- Return ans as the maximum importance.

Complexity Analysis:
- Time Complexity: O(n log n), where n is the number of cities.
  - Counting degrees for each city takes O(m) time, where m is the number of roads.
  - Sorting the degree vector takes O(n log n) time.
  - Calculating ans by iterating through the sorted degree vector takes O(n) time.
  - Overall, the time complexity is dominated by the sorting step.
  
- Space Complexity: O(n), where n is the number of cities.
  - Extra space is used for the degree vector, which stores the degree of each city.
  - Sorting the degree vector takes O(n) space in place.

*/

