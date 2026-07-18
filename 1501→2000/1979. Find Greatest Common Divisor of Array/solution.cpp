class Solution {
    public:
        int gcd(int a, int b) {
            if (b == 0) return a;
            return gcd(b, a % b);
        }
        int findGCD(vector<int> &nums) {
            int min = 1001;
            int max = 0;
            for (int e : nums) {
                if (e < min) min = e;
                if (e > max) max = e;
            }
            return gcd(min, max);
        }
};
