class Solution {
    public:
        // Returns the results of queries on painting balls with different colors
        vector<int> queryResults(int limit, vector<vector<int>>& queries) {
            int n = queries.size();
            vector<int> result(n); // Store results of each query
    
            // Maps to track colors and balls
            unordered_map<int, int> colorMap, ballMap;
    
            // Iterate through each query
            for (int i = 0; i < n; i++) {
                // Extract ball label and color from the current query
                int ball = queries[i][0], color = queries[i][1];
    
                // Check if the ball is already painted
                if (ballMap.find(ball) != ballMap.end()) {
                    // Decrement count of the previous color on the ball
                    int prevColor = ballMap[ball];
                    colorMap[prevColor]--;
    
                    // If no balls are left with the previous color, remove it from the color map
                    if (colorMap[prevColor] == 0) colorMap.erase(prevColor);
                }
                // Update the color of the ball
                ballMap[ball] = color;
    
                // Increment the count of the new color
                colorMap[color]++;
    
                // Record the number of distinct colors after this query
                result[i] = colorMap.size();
            }
    
            return result;
        }
    }
    /*
    Approach Summary:
    This solution iterates through queries, updating the colors of balls and tracking the number of distinct colors after each query. It uses two maps to efficiently manage ball colors and count distinct colors.
    
    Complexity Analysis:
    - Time Complexity: O(Q), where Q is the number of queries, because each query is processed once.
    - Space Complexity: O(Q), for storing the results and maps to track colors and balls.
    */
    