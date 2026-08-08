class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> ans(m);

        // last[j] = index in word1 where word2[j] is matched
        // when greedily matching word2[j...m-1] from the right.
        vector<int> last(m, -1);

        int i = n - 1;
        int j = m - 1;

        while (i >= 0 && j >= 0) {
            if (word1[i] == word2[j]) {
                last[j] = i;
                --j;
            }
            --i;
        }

        // We are allowed to make at most one mismatch.
        bool canChange = true;

        j = 0;

        for (i = 0; i < n && j < m; ++i) {

            // Normal matching character.
            if (word1[i] == word2[j]) {
                ans[j] = i;
                ++j;
            }

            // Use the one allowed modification.
            else if (canChange &&
                     (j == m - 1 || i < last[j + 1])) {

                canChange = false;
                ans[j] = i;
                ++j;
            }
        }

        // Couldn't match all of word2.
        if (j != m)
            return {};

        return ans;
    }
};
