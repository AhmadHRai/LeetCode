class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int count = 0;
        while (left <= right) {
            count += 665772 >> std::bitset<32>(left).count() & 1;
            left++;
        }
        return count;
    }
};
