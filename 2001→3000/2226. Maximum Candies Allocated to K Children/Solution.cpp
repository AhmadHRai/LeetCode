class Solution {
public:
    bool helper(vector<int>& candies, long long mid, long long k) {
        int n = candies.size();
        long long count = 0;
        for (int i = 0; i < n; i++) {
            count += (candies[i] / mid);
            if (count >= k)
                return true;
        }
        return false;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        int mx = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, candies[i]);
        }

        long long left = 1, right = mx;
        long long ans = 0;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (helper(candies, mid, k)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};