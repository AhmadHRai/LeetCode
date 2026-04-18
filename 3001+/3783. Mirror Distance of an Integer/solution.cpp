class Solution {
public:
    int mirrorDistance(int n) {

        int og = n, reversedNumber = 0, remainder;

        while (n != 0) {
            remainder = n % 10;
            reversedNumber = reversedNumber * 10 + remainder;
            n /= 10;
        }

        return std::abs(og - reversedNumber);
    }
};
