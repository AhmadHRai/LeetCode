// Prefix Sums

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int chunks = 0, prefixSum = 0, sortedPrefixSum = 0;

        for (int i = 0; i < n; i++) {
            // Update prefix sum of `arr`
            prefixSum += arr[i];
            // Update prefix sum of the sorted array
            sortedPrefixSum += i;

            // If the two sums are equal, the two prefixes contain the same
            // elements; a chunk can be formed
            if (prefixSum == sortedPrefixSum) {
                chunks++;
            }
        }
        return chunks;
    }
};

/*
Approach:
    - This approach utilizes prefix sums to efficiently determine how many chunks we can create.
    - We maintain two running sums: one for the `arr` array (`prefixSum`) and one for a sorted version of the array (`sortedPrefixSum`).
    - At each index, we update both prefix sums by adding the value at the current index of `arr` and the value of the current index in the sorted array (which is simply `i`).
    - Whenever the two prefix sums are equal, it means that the prefix of the current array up to index `i` matches the corresponding prefix of the sorted array, indicating that a chunk can be created.
    - This approach leverages the idea that, when the sum of elements in the prefix is the same as the sum of indices in the sorted version, we can partition the array at that point.

    Complexity Analysis:
    - Time complexity: O(n)
      We iterate through the array once, performing constant-time operations for each element. Thus, the overall time complexity is O(n).

    - Space complexity: O(1)
      We only use a fixed number of variables (`chunks`, `prefixSum`, `sortedPrefixSum`), which do not depend on the size of the input array, resulting in O(1) space complexity.
*/
