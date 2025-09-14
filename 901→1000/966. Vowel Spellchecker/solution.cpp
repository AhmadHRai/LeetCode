class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string> queries) {
        const unordered_set<string> exactWords(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseInsensitiveMap, vowelErrorMap;

        for (const auto& word : wordlist) {
            string lowerWord = toLower(word);
            string devoweledWord = devowel(lowerWord);
            caseInsensitiveMap.emplace(lowerWord, word);
            vowelErrorMap.emplace(devoweledWord, word);
        }

        for (auto& query : queries) {
            if (exactWords.count(query)) {
                continue; // exact match found
            }
            string lowerQuery = toLower(query);
            string devoweledQuery = devowel(lowerQuery);
            if (caseInsensitiveMap.count(lowerQuery)) {
                query = caseInsensitiveMap[lowerQuery];
            } else if (vowelErrorMap.count(devoweledQuery)) {
                query = vowelErrorMap[devoweledQuery];
            } else {
                query.clear();
            }
        }
        return queries;
    }

private:
    static string toLower(const string& str) {
        string result = str;
        for (auto& c : result) {
            c = tolower(c);
        }
        return result;
    }

    static string devowel(const string& str) {
        string result = toLower(str);
        for (auto& c : result) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                c = '#';
            }
        }
        return result;
    }
};
