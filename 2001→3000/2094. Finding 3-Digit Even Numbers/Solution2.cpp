class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        int A[10] = {0};

        for (auto& x : digits)
            A[x]++;

        for (int i = 100; i < 999; i += 2) {
            int d1 = i / 100, d2 = i / 10 % 10, d3 = i % 10;
            if (--A[d1] >= 0 & --A[d2] >= 0 & --A[d3] >= 0)
                ans.push_back(i);
            A[d1]++, A[d2]++, A[d3]++;
        }

        return ans;
    }
};