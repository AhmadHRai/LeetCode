class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiagSq = 0;
        int maxArea = 0;

        for(int i = 0; i < dimensions.size(); i++) {
            int x = dimensions[i][0];
            int y = dimensions[i][1];
            int diagSq = x * x + y * y;
            int area = x * y;

            if (diagSq > maxDiagSq || (diagSq == maxDiagSq && area > maxArea)) {
                maxDiagSq = diagSq;
                maxArea = area;
            }
        }

        return maxArea;
    }
};
