class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        // Step 1: Find the rightmost index where the array is still non-decreasing
        int right = arr.size() - 1;
        
        // Move right pointer leftward as long as the elements are non-decreasing
        while (right > 0 && arr[right] >= arr[right - 1]) {
            right--;
        }

        // Initialize the answer with the length of the removed subarray if we remove everything after 'right'
        int ans = right;

        int left = 0;  // Start with the left pointer at the beginning of the array
        // Step 2: Try to find a valid subarray to remove starting from the left
        while (left < right && (left == 0 || arr[left - 1] <= arr[left])) {
            // Find the next valid number that is greater than or equal to arr[left]
            while (right < arr.size() && arr[left] > arr[right]) {
                right++;  // Move the right pointer to the right to find a valid number
            }
            // Calculate the length of the subarray that can be removed
            ans = min(ans, right - left - 1);  // Subtract 1 to exclude arr[left] itself from the count
            left++;  // Move the left pointer to the right to consider the next subarray
        }
        
        return ans;  // Return the length of the shortest subarray that can be removed
    }
};

/*
    Approach:
    - We need to find the length of the shortest subarray that can be removed from the array `arr` to make the remaining array non-decreasing.
    - The algorithm follows a two-pointer approach:
        1. The `right` pointer initially identifies the longest suffix of the array that is already non-decreasing. This is done by moving `right` from the end of the array to the left as long as elements are non-decreasing.
        2. Then, the `left` pointer starts from the beginning of the array and tries to find subarrays that, when removed, make the remaining array non-decreasing.
        3. For each position of the `left` pointer, we attempt to find the smallest index `right` such that the subarray between `left` and `right` can be removed, ensuring that the remaining parts of the array are still non-decreasing.
        4. We keep track of the minimum length of such subarrays and return the result.

    Time Complexity:
    - The time complexity is `O(n)`, where `n` is the length of the array. This is because:
        - Both `left` and `right` pointers traverse the array at most once, leading to a linear scan of the array.
        - The inner while loop moves the `right` pointer rightward, and since each pointer only moves from one end of the array to the other, the total number of iterations remains linear.

    Space Complexity:
    - The space complexity is `O(1)` since the algorithm uses only a few extra variables (no extra data structures are used that grow with the input size).
*/
