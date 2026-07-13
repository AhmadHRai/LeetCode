class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;

        int lowLen = to_string(low).size();
        int highLen = to_string(high).size();

        for (int len = lowLen; len <= highLen; len++) {
            for (int start = 1; start + len - 1 <= 9; start++) {
                int num = 0;
                for (int d = start; d < start + len; d++) {
                    num = num * 10 + d;
                }

                if (num >= low && num <= high)
                    ans.push_back(num);
            }
        }

        return ans;
    }
};
