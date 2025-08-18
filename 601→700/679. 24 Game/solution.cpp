#include <vector>
#include <cmath>
using namespace std;

class Solution {
    const double TARGET = 24.0;
    const double EPS = 1e-6;

    bool solve(vector<double>& nums) {
        if (nums.size() == 1) {
            return fabs(nums[0] - TARGET) < EPS;
        }

        int n = nums.size();
        // Try every pair (i, j) and every operation between them
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                vector<double> nextNums;
                // add all other numbers except i and j
                for (int k = 0; k < n; ++k) {
                    if (k != i && k != j) {
                        nextNums.push_back(nums[k]);
                    }
                }

                // For each operation, create a new vector with the result and recurse
                vector<double> candidates;
                double a = nums[i], b = nums[j];

                candidates.push_back(a + b);
                candidates.push_back(a - b);
                candidates.push_back(b - a);
                candidates.push_back(a * b);
                if (fabs(b) > EPS) candidates.push_back(a / b);
                if (fabs(a) > EPS) candidates.push_back(b / a);

                for (double c : candidates) {
                    nextNums.push_back(c);
                    if (solve(nextNums)) return true;
                    nextNums.pop_back();
                }
            }
        }
        return false;
    }

public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(), cards.end());
        return solve(nums);
    }
};
