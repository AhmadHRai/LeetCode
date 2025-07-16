class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();

        int maxLength = 0;

        // all even numbers
        int evenCount = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                evenCount++;
            }
        }
        maxLength = max(maxLength, evenCount);

        // all odd numbers
        int oddCount = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 != 0) {
                oddCount++;
            }
        }
        maxLength = max(maxLength, oddCount);

        // alternating even odd
        int evenOddCount1 = 0;
        bool expectEven = true;
        for (int i = 0; i < n; i++) {
            if ((expectEven && nums[i] % 2 == 0) ||
                (!expectEven && nums[i] % 2 != 0)) {
                evenOddCount1++;
                expectEven = !expectEven; // flip expected Parity
            }
        }
        maxLength = max(maxLength, evenOddCount1);

        // alternating odd even
        int oddEvenCount1 = 0;
        expectEven = false;
        for (int i = 0; i < n; i++) {
            if ((expectEven && nums[i] % 2 == 0) || (!expectEven && nums[i] % 2 != 0)) {
                oddEvenCount1++;
                expectEven = !expectEven; // flip expected Parity
            }
        }
        maxLength = max(maxLength, oddEvenCount1);

        return maxLength;
    }
};