// PrefixMax and SuffixMin Arrays
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefixMax = arr;
        vector<int> suffixMin = arr;

        // Fill the prefixMax array
        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i - 1], prefixMax[i]);
        }

        // Fill the suffixMin array in reverse order
        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(suffixMin[i + 1], suffixMin[i]);
        }

        int chunks = 0;
        for (int i = 0; i < n; i++) {
            // A new chunk can be created
            if (i == 0 || suffixMin[i] > prefixMax[i - 1]) chunks++;
        }

        return chunks;
    }
};

/*
Approach:
    - This approach relies on creating two auxiliary arrays: `prefixMax` and `suffixMin`.
    - `prefixMax[i]` holds the maximum value in the subarray arr[0:i], while `suffixMin[i]` holds the minimum value in the subarray arr[i:n].
    - We iterate over the array to fill these arrays. After that, we iterate through the array to check when we can form a chunk. Specifically, we check if `suffixMin[i] > prefixMax[i - 1]` to determine if we can create a new partition at index `i`.
    - The key idea is that for each index `i`, if the maximum element in the left subarray (from arr[0] to arr[i-1]) is smaller than the minimum element in the right subarray (from arr[i] to arr[n-1]), a new chunk can be formed.
    
    This is a more structured and clear approach than the simple max element method, but it requires extra space for the auxiliary arrays.

    Complexity Analysis:
    - Time complexity: O(n)
      The initialization of the `prefixMax` and `suffixMin` arrays, as well as the computation of chunks, each requires a single pass through the array arr, taking O(n) time. Therefore, the total time complexity is O(n) + O(n) + O(n) = O(n).

    - Space complexity: O(n)
      The `prefixMax` and `suffixMin` arrays require O(n) space.
*/
