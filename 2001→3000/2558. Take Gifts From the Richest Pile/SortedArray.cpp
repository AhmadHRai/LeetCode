// Sorted Array Approach
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n = gifts.size();  // Get the size of the 'gifts' array

        // Create a copy of the gifts array and sort it
        vector<int> sortedGifts = gifts;
        sort(sortedGifts.begin(), sortedGifts.end());

        // Perform the operation k times
        for (int i = 0; i < k; i++) {
            int maxElement = sortedGifts[n - 1];  // Get the largest element (last element in sorted array)
            sortedGifts.pop_back();  // Remove the largest element

            // upper_bound returns the first element greater than sqrt(maxElement)
            auto spotOfSqrt = upper_bound(sortedGifts.begin(), sortedGifts.end(), sqrt(maxElement));

            // Insert the square root value at the found position
            sortedGifts.emplace(spotOfSqrt, sqrt(maxElement));
        }

        // Calculate the sum of the remaining gifts in the array
        long long int numberOfRemainingGifts = accumulate(sortedGifts.begin(), sortedGifts.end(), 0LL);

        return numberOfRemainingGifts;
    }
};

/*
Approach:
1. First, create a sorted copy of the `gifts` array to facilitate efficient insertion and searching.
2. In each of the `k` iterations, extract the largest element (the last element in the sorted array).
3. Compute the square root of the maximum element and remove it from the array.
4. Insert the square root of the largest element into the correct position in the sorted array using `upper_bound`.
5. After performing the operation `k` times, the function calculates and returns the sum of the remaining gifts in the array.

Complexity Analysis:
- Time Complexity: O(k×(n+logn)),At each step, we use the upper bound function to find the correct position for the square root of the maximum element. This function is implemented using binary search, so its time complexity is O(logn). Additionally, we insert a value into the array at the correct position, which has a time complexity of O(n), because all elements after the insertion point need to be shifted to the right. Since we are performing k operations in total, the overall time complexity becomes O(k×(n+logn)).
- Space Complexity: O(n), as we create a copy of the `gifts` array (`sortedGifts`), which requires O(n) additional space. If we were allowed to modify the input in place, the space complexity could be reduced to O(1).
*/
