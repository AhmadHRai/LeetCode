class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();
        
        vector<vector<int>> result;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                
                //We have to deal with 1s only
                if(land[i][j] == 0) continue;

                //Find right most column of rectangle
                int c1 = j;
                while(c1 < n && land[i][c1] == 1) {
                    c1++;
                }

                //Find bottom most row of rectangle
                int r2 = i;
                while(r2 < m && land[r2][j] == 1) {
                    r2++;
                }
                
                //Then you can find bottom right most of rectangle
                c1 = c1==0 ? c1 : c1-1;
                r2 = r2==0 ? r2 : r2-1;

                //Use them as your answer
                //{r1, c1} = {i, j}
                //{r2, c2} = {r2, c1}
                result.push_back({i, j, r2, c1});
                
                //Now, mark the covered land with 0 so that you don't consider them later
                for(int k = i; k<=r2; k++) {
                    for(int l = j; l<=c1; l++) {
                        land[k][l] = 0;
                    }
                }
                
            }
        }
        return result;
    }
};

/* 
Approach:

    The algorithm iterates through each cell in the given 2D grid (land). For each cell with a value of 1, it attempts to find the largest rectangle that can be formed 
    starting from that cell. The rectangle is defined by the top-left corner (i, j) and the bottom-right corner (r2, c1). The algorithm works by first finding the 
    rightmost column (c1) of the rectangle by checking cells to the right of the current cell (i, j) until it encounters a cell with a value of 0. Similarly, it finds 
    the bottom-most row (r2) by checking cells below the current cell (i, j) until it encounters a cell with a value of 0. After determining the corners of the 
    rectangle, it adds the rectangle's coordinates to the result vector and marks all cells within the rectangle as 0 to avoid considering them again in future 
    iterations.

Complexity Analysis:

    The time complexity of this algorithm is O(mn), where m is the number of rows and n is the number of columns in the grid. This is because, in the worst case, the 
    algorithm needs to visit every cell in the grid once. 

    The space complexity is also O(mn) because, in the worst case, the result vector could potentially store all cells in the grid as separate rectangles. However, in 
    practice, the number of rectangles stored in the result vector is likely to be much smaller than the total number of cells in the grid, especially if the grid 
    contains a lot of 0s.
 */