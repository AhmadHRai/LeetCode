unsigned freq[100001] = {0};
class Solution {
public:
    static bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        unsigned xmax = 0;
        for (unsigned x : asteroids) {
            freq[x]++;
            xmax = max(xmax, x);
        }
        long long planet = mass; // careful for overflow
        for (int x = 1; x <= xmax; x++) {
            if (freq[x] == 0)
                continue;
            if (x > planet) {
                memset(freq + x, 0, (xmax - x + 1) * sizeof(unsigned));
                return 0;
            }
            planet += (long long)x * freq[x];
            freq[x] = 0;
        }
        return 1;
    }
};
