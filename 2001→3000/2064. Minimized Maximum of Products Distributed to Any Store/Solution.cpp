class Solution {
    private:
        // Helper function to check if it's possible to minimize the maximum number of items
        // per store such that the total number of stores does not exceed 'n'
        bool solve(int n, vector<int>& quantities, int item)
        {
            // If the item size is zero, it's impossible to distribute anything
            if(item == 0) return false;
            
            int store = 0;
            // Loop through each product quantity to determine how many stores are required
            for(auto product : quantities)
            {
                // The number of stores needed for each product is the ceiling of (product / item)
                // Which is equivalent to (product - 1) / item + 1
                store += (product - 1) / item + 1;
                
                // If the total stores exceed 'n', return false as we can't minimize within the limit
                if(store > n) return false;
            }
            return true; // If all products fit within 'n' stores, return true
        }

public:
    // Main function to find the minimized maximum number of items in each store
    int minimizedMaximum(int n, vector<int>& quantities) {
        // Low and high bounds for the binary search on the maximum number of items per store
        int low = 1;  // We need at least 1 item in each store
        int high = *max_element(quantities.begin(), quantities.end()); // The maximum number of items in any product
        
        int ans = -1;  // To store the answer, the minimized maximum value
        
        // Binary search to find the minimized maximum number of items per store
        while(low <= high)
        {
            int mid = (low + high) / 2;  // Midpoint representing the candidate maximum items per store
            
            // Check if it's possible to fit all the products into 'n' stores with 'mid' items per store
            if(solve(n, quantities, mid))
            {
                ans = mid;        // If possible, update the answer to 'mid'
                high = mid - 1;   // Try to minimize further by checking smaller values
            }
            else
            {
                low = mid + 1;    // If not possible, increase the number of items per store
            }
        }
        
        return ans;  // Return the minimized maximum number of items per store
    }
};

/*
    Approach:
    - The problem is solved using **binary search** to find the minimized maximum number of items that can be placed in each store, while ensuring the total number of stores does not exceed `n`.
    - We perform binary search on the possible values of the maximum number of items that can go into a store. The search range is from `1` to the maximum quantity of any product.
    - For each candidate value (mid), we check whether it's possible to distribute the items across `n` stores with `mid` items per store by using a greedy strategy in the `solve` helper function.
    - The `solve` function calculates how many stores are needed to accommodate the current `mid` number of items per store for each product and ensures the total number of stores does not exceed `n`.

    Time Complexity:
    - The time complexity of the solution is `O(m * log(max))`, where:
        - `m` is the number of products in the `quantities` vector.
        - `max` is the maximum product quantity (upper bound for the binary search).
    - This is because binary search runs in `O(log(max))`, and for each binary search iteration, the `solve` function iterates over the `quantities` array, which takes `O(m)` time.

    Space Complexity:
    - The space complexity is `O(m)`, where `m` is the number of products. This is the space required for the `quantities` input array and the constant space used in the `solve` function.
*/