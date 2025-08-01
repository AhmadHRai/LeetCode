class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> mem;
        
        for(int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1);

            for(int j = 1; j < i; j++) {
                row[j] =mem[j-1] + mem[j]; 
            }
            res.push_back(row);
            mem = row;
        }


        return res;
    }
};