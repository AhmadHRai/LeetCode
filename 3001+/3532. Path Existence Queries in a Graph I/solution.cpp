class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // Precalculate connected components
        vector<int> componentId(n, 0);
        int currentId = 0;
        
        for (int i = 1; i < n; ++i) {
            if (nums[i] - nums[i - 1] > maxDiff) {
                currentId++;
            }
            componentId[i] = currentId;
        }
        
        // Answer queries in O(1) time each
        int q = queries.size();
        vector<bool> answer(q);
        for (int i = 0; i < q; ++i) {
            int u = queries[i][0];
            int v = queries[i][1];
            answer[i] = (componentId[u] == componentId[v]);
        }
        
        return answer;
    }
};
