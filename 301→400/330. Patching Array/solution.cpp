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

Explanation

Let miss be the smallest sum in [0,n] that we might be missing. Meaning we already know we can build all sums in [0,miss). Then if we have a number num <= miss in the given array, we can add it to those smaller sums to build all sums in [0,miss+num). If we don't, then we must add such a number to the array, and it's best to add miss itself, to maximize the reach.

Example: Let's say the input is nums = [1, 2, 4, 13, 43] and n = 100. We need to ensure that all sums in the range [1,100] are possible.

Using the given numbers 1, 2 and 4, we can already build all sums from 0 to 7, i.e., the range [0,8). But we can't build the sum 8, and the next given number (13) is too large. So we insert 8 into the array. Then we can build all sums in [0,16).

Do we need to insert 16 into the array? No! We can already build the sum 3, and adding the given 13 gives us sum 16. We can also add the 13 to the other sums, extending our range to [0,29).

And so on. The given 43 is too large to help with sum 29, so we must insert 29 into our array. This extends our range to [0,58). But then the 43 becomes useful and expands our range to [0,101). At which point we're done.

Complexity:

Time Complexity:
    Sorting takes O(n log n) time.
    Each of the k iterations involves operations on the heap, each of which takes O(log n) time.
    Overall time complexity is dominated by the sorting operation, O(n log n).

Space Complexity:
    O(n) for storing the pairs of (capital, profit) and the max-heap.
 */

