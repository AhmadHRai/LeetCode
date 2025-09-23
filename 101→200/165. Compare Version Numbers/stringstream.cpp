class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream ss1(version1);
        stringstream ss2(version2);
        string item;
        
        int v1_rev, v2_rev;
        char dot_separator;
        
        while (ss1.peek() != EOF || ss2.peek() != EOF) {
            if (ss1.peek() != EOF) {
                ss1 >> v1_rev;
                if (ss1.peek() == '.') {
                    ss1 >> dot_separator;
                }
            } else {
                v1_rev = 0;
            }

            if (ss2.peek() != EOF) {
                ss2 >> v2_rev;
                if (ss2.peek() == '.') {
                    ss2 >> dot_separator;
                }
            } else {
                v2_rev = 0;
            }

            if (v1_rev < v2_rev) {
                return -1;
            }
            if (v1_rev > v2_rev) {
                return 1;
            }
        }
        
        return 0;
    }
};
