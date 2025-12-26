class Solution {
public:
    int bestClosingTime(string customers) {
        int mp = 0, cp = 0;
        int res = 0;

        for (int i = 0; i < customers.size(); i++) {
            char ch = customers[i];
            if (ch == 'Y') {
                cp--;
            } else {
                cp++;
            }

            if (cp < mp) {
                res = i + 1;
                mp = cp;
            }
        }

        return res;
    }
};
