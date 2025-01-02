class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans(queries.size());

        unordered_set<char> vowels {'a', 'e', 'i', 'o', 'u'};

        vector<int> prefixSum (words.size());

        int sum = 0;

        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            if(vowels.count(word[0]) && vowels.count(word[word.size()-1])) {
                sum++;
            }
            prefixSum[i] = sum;
        }

        for (int i = 0; i < queries.size(); i++) {
            vector<int> query = queries[i];
            ans[i] = prefixSum[query[1]] - (query[0] == 0 ? 0 : prefixSum[query[0]-1]);
        }

        return ans;
    }
};