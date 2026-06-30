class Solution {
public:
    int numberOfSubstrings(string s) {
        int last[3] = {-1, -1, -1};
        int count = 0;

        for (int right = 0; right < s.size(); right++) {
            last[s[right] - 'a'] = right;

            int earliest = min({last[0], last[1], last[2]});
            if (earliest != -1) {
                count += earliest + 1;
            }
        }

        return count;
    }
};
