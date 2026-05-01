#include <vector>
#include <algorithm>

class Solution {
public:
    int maxRotateFunction(const std::vector<int>& nums) {
        long long sum = 0;
        long long f = 0;
        long long n = nums.size();

        // Single pass to compute both sum and F(0)
        // Using 64-bit 'i' avoids overflow during i * nums[i]
        for (long long i = 0; i < n; ++i) {
            sum += nums[i];
            f += i * nums[i];
        }

        long long maxi = f;

        // Compute F(1), F(2), ..., F(n-1) in O(1) each
        for (long long i = n - 1; i > 0; --i) {
            f += sum - n * nums[i];
            if (f > maxi) {
                maxi = f;
            }
        }

        return static_cast<int>(maxi);
    }
};
