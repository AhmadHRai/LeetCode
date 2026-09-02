class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool hasOdd = false;
        bool hasEven = false;

        for (int x : nums1) {
            if (x % 2 == 0)
                hasEven = true;
            else
                hasOdd = true;
        }

        // If all elements already have the same parity.
        if (!hasOdd || !hasEven)
            return true;

        // If both parities exist:
        // Keep odd numbers as they are.
        // For every even number, subtract an odd number:
        // even - odd = odd.
        return true;
    }
};
