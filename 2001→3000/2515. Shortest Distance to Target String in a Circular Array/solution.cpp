class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int ans = n;

        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                int forwardDist = abs(i - startIndex);
                int backwardDist = n - forwardDist;
                ans = min(ans, min(forwardDist, backwardDist));
            }
        }

        return ans == n ? -1 : ans;
    }
};
