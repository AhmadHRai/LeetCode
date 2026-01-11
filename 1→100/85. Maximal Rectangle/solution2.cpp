class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;

        int cols = matrix[0].size();
        vector<int> heights(cols + 1, 0);
        int maxArea = 0;

        for (const auto& row : matrix) {
            for (int i = 0; i < cols; i++) {
                heights[i] = (row[i] == '1') ? heights[i] + 1 : 0;
            }

            stack<int> s;
            for (int i = 0; i < heights.size(); i++) {
                while (!s.empty() && heights[i] < heights[s.top()]) {
                    int h = heights[s.top()];
                    s.pop();
                    int w = s.empty() ? i : i - s.top() - 1;
                    maxArea = max(maxArea, h * w);
                }
                s.push(i);
            }
        }

        return maxArea;
    }
};
