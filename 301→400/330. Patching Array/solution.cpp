class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        // Initialize miss as 1, representing the smallest sum that cannot be formed with the current set of patches.
        long miss = 1;
        // Initialize added to count the number of patches added.
        long added = 0;
        // Initialize index i to iterate through nums.
        long i = 0;
        
        // Continue while miss is less than or equal to n.
        while (miss <= n) {
            // If i is within bounds and nums[i] is less than or equal to miss,
            // update miss by adding nums[i] to it and move to the next element in nums.
            if (i < nums.size() && nums[i] <= miss) {
                miss += nums[i++];
            } else {
                // If nums[i] is greater than miss or we've exhausted nums,
                // add miss itself to the patches and double miss to maximize the reach.
                miss += miss;
                added++;
            }
        }
        
        // Return the total number of patches added.
        return added;
    }
};

/*
Complexity:

Time Complexity:
    Sorting takes O(n log n) time.
    Each of the k iterations involves operations on the heap, each of which takes O(log n) time.
    Overall time complexity is dominated by the sorting operation, O(n log n).

Space Complexity:
    O(n) for storing the pairs of (capital, profit) and the max-heap.
 */

