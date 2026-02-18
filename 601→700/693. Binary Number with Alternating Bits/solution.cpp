class Solution {
public:
    bool hasAlternatingBits(int n) { return !((n ^= n / 4) & n - 1); }
};
