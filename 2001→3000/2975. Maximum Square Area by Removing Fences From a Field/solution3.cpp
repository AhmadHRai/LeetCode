#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        if (hFences.size() > vFences.size()) {
            swap(hFences, vFences);
        }

        int hSize = hFences.size();
        vector<int> hDiffs;
        hDiffs.reserve(hSize * (hSize - 1) / 2);

        for (int i = 0; i < hSize; ++i) {
            for (int j = i + 1; j < hSize; ++j) {
                hDiffs.push_back(hFences[j] - hFences[i]);
            }
        }
        sort(hDiffs.begin(), hDiffs.end());

        int max_side = 0;
        int vSize = vFences.size();

        for (int i = 0; i < vSize; ++i) {
            if (vFences.back() - vFences[i] <= max_side) break;

            for (int j = vSize - 1; j > i; --j) {
                int diff = vFences[j] - vFences[i];
                if (diff <= max_side) break;

                if (binary_search(hDiffs.begin(), hDiffs.end(), diff)) {
                    max_side = diff;
                    break;
                }
            }
        }

        return max_side == 0 ? -1 : (1LL * max_side * max_side) % 1000000007;
    }
};
