#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long countNonDecreasingSubarrays(const vector<int>& nums, int k) {
        const int n = nums.size();
        const int* __restrict a = nums.data(); // Direct pointer for compiler vectorization/caching
        
        // Stack-allocated array avoids heap allocation overhead completely (fits in 400KB L2/L1 cache)
        int starts[100005];
        int head = n, tail = n;
        int r = n - 1;
        
        long long ans = 0;
        long long water = 0;
        
        for (int l = n - 1; l >= 0; --l) {
            const int x = a[l];
            
            // Merge plateaus from the left that are <= x
            while (head < tail && a[starts[head]] <= x) {
                const int s = starts[head++];
                const int end = (head < tail) ? starts[head] : (r + 1);
                water += 1LL * (x - a[s]) * (end - s);
            }
            starts[--head] = l;
            
            // Shrink from the right when operations exceed k
            while (water > k) {
                const int last_start = starts[tail - 1];
                water -= a[last_start] - a[r];
                if (last_start == r) {
                    --tail;
                }
                --r;
            }
            
            ans += (r - l + 1);
        }
        
        return ans;
    }
};
