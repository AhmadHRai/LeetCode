#include <string>
#include <vector>

class Solution {
public:
    bool checkStrings(const string& s1, const string& s2) {
        if (s1.size() != s2.size()) return false;

        vector<int> evenCount1(26, 0), evenCount2(26, 0);
        vector<int> oddCount1(26, 0), oddCount2(26, 0);

        for (size_t i = 0; i < s1.size(); ++i) {
            if (i % 2 == 0) {
                evenCount1[s1[i] - 'a']++;
                evenCount2[s2[i] - 'a']++;
            } else {
                oddCount1[s1[i] - 'a']++;
                oddCount2[s2[i] - 'a']++;
            }
        }

        return evenCount1 == evenCount2 && oddCount1 == oddCount2;
    }
};
