const int MAX_NODES = 500005;
int nxt[MAX_NODES][26];
int best_len[MAX_NODES];
int best_idx[MAX_NODES];

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {
        int nodeCnt = 0;

        for (int i = 0; i < 26; i++) {
            nxt[0][i] = -1;
        }
        best_len[0] = 1e9;
        best_idx[0] = 1e9;
        nodeCnt++;

        for (int i = 0; i < wordsContainer.size(); i++) {
            int curr = 0;
            int len = wordsContainer[i].size();

            if (len < best_len[curr]) {
                best_len[curr] = len;
                best_idx[curr] = i;
            }

            for (int j = len - 1; j >= 0; j--) {
                int c = wordsContainer[i][j] - 'a';

                if (nxt[curr][c] == -1) {
                    for (int k = 0; k < 26; k++) {
                        nxt[nodeCnt][k] = -1;
                    }
                    best_len[nodeCnt] = 1e9;
                    best_idx[nodeCnt] = 1e9;

                    nxt[curr][c] = nodeCnt;
                    nodeCnt++;
                }

                curr = nxt[curr][c];

                if (len < best_len[curr]) {
                    best_len[curr] = len;
                    best_idx[curr] = i;
                }
            }
        }

        vector<int> ans;
        ans.reserve(wordsQuery.size());

        for (int i = 0; i < wordsQuery.size(); i++) {
            int curr = 0;
            for (int j = wordsQuery[i].size() - 1; j >= 0; j--) {
                int c = wordsQuery[i][j] - 'a';
                if (nxt[curr][c] == -1) {
                    break;
                }
                curr = nxt[curr][c];
            }
            ans.push_back(best_idx[curr]);
        }

        return ans;
    }
};
