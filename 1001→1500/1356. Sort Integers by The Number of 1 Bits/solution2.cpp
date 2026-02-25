class Solution {
public:
    static bool compare(int a, int b) {
        int bitCountA = __builtin_popcount(a);
        int bitCountB = __builtin_popcount(b);

        if (bitCountA == bitCountB) {
            return a < b;
        }

        return bitCountA < bitCountB;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};
