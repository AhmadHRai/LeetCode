#include <vector>
#include <unordered_set>
#include <string>

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        // Result array to store answer for each query
        vector<int> ans(queries.size());
        
        // Set to store vowels for quick lookup
        unordered_set<char> vowels {'a', 'e', 'i', 'o', 'u'};
        
        // Prefix sum array, with an extra element to handle range queries easily
        vector<int> prefixSum(words.size() + 1, 0);

        // Calculate the prefix sum where prefixSum[i] is the count of words that start and end with vowels
        for (int i = 0; i < words.size(); i++) {
            // Check if the word starts and ends with a vowel
            if (vowels.count(words[i][0]) && vowels.count(words[i].back())) {
                prefixSum[i + 1] = prefixSum[i] + 1;
            } else {
                prefixSum[i + 1] = prefixSum[i];
            }
        }

        // Process each query and calculate the result
        for (int i = 0; i < queries.size(); i++) {
            int left = queries[i][0], right = queries[i][1];
            ans[i] = prefixSum[right + 1] - prefixSum[left];
        }

        return ans;
    }
};
