class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        // Sort arr2 to enable binary search
        sort(arr2.begin(), arr2.end());

        int count = 0;

        // Check each element in arr1
        for (int num : arr1) {
            // Find the first element in arr2 that is >= (num - d)
            // This gives us the lower bound of the range [num - d, num + d]
            auto iterator = lower_bound(arr2.begin(), arr2.end(), num - d);

            // If no element exists in arr2 within the range [num - d, num + d],
            // then this element from arr1 satisfies the distance requirement
            if (iterator == arr2.end() || *iterator > num + d) {
                count++;
            }
        }

        return count;
    }
};
