class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int l = 0;
        int res = 0;

        for (int r = 1; r < n + k - 1; r++) {
            if(colors[r % n] == colors[(r-1) % n]) {
                // not alternating, shift pointer
                l = r;
            }

            if (r - l + 1 > k) {
                l++; // shrink the window by 1 if it's greater than k 
            }

            if (r - l + 1 == k) {
                // size of the window, and assume it's alternating (unless it is shrinked ^)
                res++;
            }
        }

        return res;
    }
};