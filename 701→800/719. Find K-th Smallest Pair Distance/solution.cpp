class Solution {
public:
    
    // Helper function to count how many pairs have a difference <= mid
    int helper(vector<int>& nums, int k, int mid) { // mid is the target difference
        int count = 0; // To store the count of valid pairs
        int j = 0;     // Second pointer in the pair
        int n = nums.size();

        // Iterate over the array with the first pointer `i`
        for (int i = 0; i < n; i++) {
            // Move the second pointer `j` until the difference between nums[j] and nums[i] exceeds mid
            while (j < n && (nums[j] - nums[i]) <= mid) {
                j++;
            }
            
            // Add the number of valid pairs starting from index `i` to `j-1`
            count += (j - i - 1); // (j - i - 1) gives the count of valid pairs starting from index `i`
        }

        return count; // Return the total count of pairs with difference <= mid
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        
        // Sort the array to make binary search and pair counting possible
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int low = 0; // Minimum possible difference
        int high = nums[n-1] - nums[0]; // Maximum possible difference
        int ans = -1; // To store the answer

        // Perform binary search to find the smallest distance for which there are at least k pairs
        while (low <= high) {
            int mid = low + (high - low) / 2; // Calculate the mid difference

            // Count how many pairs have a difference <= mid
            int count = helper(nums, k, mid);

            if (count >= k) {
                // If there are at least k pairs, update the answer and search for a smaller distance
                ans = mid;
                high = mid - 1;
            } else {
                // If there are fewer than k pairs, search for a larger distance
                low = mid + 1;
            }
        }

        return ans; // Return the smallest distance for which there are at least k pairs
        
        /* This approach gives TLE for large test-cases
        int n = nums.size();
        vector<int> res;

        // Brute-force approach: Calculate the difference for all pairs
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                res.push_back(abs(nums[i] - nums[j]));
            }
        }

        // Sort all differences and return the k-th smallest
        sort(res.begin(), res.end());
				
        return res[k-1];
        */
    }
};

/*
Approach:
1. **Sorting and Binary Search**:
   - The main idea is to use binary search to find the smallest distance between pairs such that there are at least `k` pairs with that distance or less.
   - The array is first sorted, which allows us to efficiently count pairs with differences less than or equal to a certain value.
   
2. **Binary Search on Answer**:
   - We initialize `low` to 0 (minimum possible difference) and `high` to the difference between the maximum and minimum elements in the sorted array.
   - We then perform binary search on this range to find the smallest distance that satisfies the condition of having at least `k` pairs.
   - For each mid value in our binary search, we count how many pairs have a difference <= mid using the helper function.

3. **Helper Function**:
   - The helper function iterates over the array with two pointers (`i` and `j`) to count the number of valid pairs with a difference <= mid.
   - For each `i`, it finds the farthest `j` such that the difference between `nums[j]` and `nums[i]` is <= mid.

4. **Time Complexity**:
   - The sorting step takes O(n log n).
   - The binary search runs in O(log(max difference)), and for each mid value, counting pairs takes O(n). Therefore, the total time complexity is O(n log n + n log(max difference)).

5. **Space Complexity**:
   - The space complexity is O(1) extra space, excluding the input and the helper function call stack.
*/
