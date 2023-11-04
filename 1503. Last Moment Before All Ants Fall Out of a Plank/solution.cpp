class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int res = 0;
        for (int& i: left)
            res = max(res, i);
        for (int& i: right)
            res = max(res, n - i);
        return res;
    }
};

/* 
Explanation

For ants in direction of left, the leaving time is left[i]
For ants in direction of right, the leaving time is n - right[i]

Complexity

Time O(N)
Space O(1)
 */