class Solution {
public:
    long long countSubarrays(vector<int>& A, int k) {
        // Find the maximum element in the array
        int a = *max_element(A.begin(), A.end());
        // Get the size of the array
        int n = A.size();
        // Initialize variables for the current count of the maximum element, the start pointer, and the result
        int cur = 0, i = 0;
        long long res = 0;

        // Iterate through the array
        for (int j = 0; j < n; ++j) {
            // Increment the current count if the current element is the maximum element
            cur += A[j] == a;
            // While the current count is greater than or equal to k, shrink the subarray by moving the start pointer to the right
            while (cur >= k)
                cur -= A[i++] == a;
            // Increment the result by the number of subarrays that satisfy the condition
            res += i;
        }

        // Return the total count of subarrays where the maximum element appears at least k times
        return res;
    }
};

/* 
Approach Summary

    The algorithm counts the number of subarrays where the maximum element appears at least `k` times. It does this by iterating through 
    the array and maintaining a count of how many times the maximum element appears in the current subarray. If the count of the maximum 
    element in the current subarray is greater than or equal to `k`, it shrinks the subarray by moving the start pointer to the right 
    until the count is less than `k`. The number of subarrays that satisfy the condition is maintained and returned at the end.

    The algorithm starts by finding the maximum element in the array and initializing variables for the current count of the maximum 
    element (`cur`), the start pointer (`i`), and the result (`res`). It then enters a loop that continues until the end of the array is 
    reached. Inside the loop, `cur` is incremented if the current element is the maximum element, and a while loop checks if `cur` is 
    greater than or equal to `k`. If it is, `cur` is decremented by moving the start pointer to the right and checking if the element at 
    the new start pointer is the maximum element. After each iteration of the outer loop, the number of subarrays that satisfy the 
    condition is incremented by the value of `i`.

Time Complexity Analysis

    The time complexity of this algorithm is O(n), where n is the length of the input array `A`. This is because each element in the 
    array is visited at most twice: once by the end pointer and once by the start pointer.

Space Complexity Analysis

    The space complexity is O(1), as the algorithm uses a constant amount of space to store variables and does not use any additional 
    data structures that grow with the size of the input array.

 */