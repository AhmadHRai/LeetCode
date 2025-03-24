class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        int res = 0;
        int prevEnd = 0;

        for(auto& meeting: meetings) {
            int start = meeting[0], end = meeting[1];

            if (start > prevEnd + 1) res += start - prevEnd -1;

            prevEnd = max(prevEnd, end);
        }

        res += days - prevEnd;

        return res;
    }
};