class Solution {
public:
    // Method to process queries on the prefix XOR array
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        // Vector to store results for each query
        vector<int> result;

        // Step 1: Convert arr into an in-place prefix XOR array
        // Compute prefix XOR array such that arr[i] holds the XOR of all elements from arr[0] to arr[i]
        for (int i = 1; i < arr.size(); ++i) {
            // Update arr[i] to be the XOR of arr[i] and arr[i - 1]
            arr[i] ^= arr[i - 1];
        }

        // Step 2: Resolve each query using the prefix XOR array
        // Iterate through each query
        for (const auto& q : queries) {
            // If the left index of the query is greater than 0
            if (q[0] > 0) {
                // Compute the XOR for the range [q[0], q[1]]
                // XOR of range [0, q[1]] is arr[q[1]] and XOR of range [0, q[0] - 1] is arr[q[0] - 1]
                // XOR of these two results gives the XOR for the range [q[0], q[1]]
                result.push_back(arr[q[0] - 1] ^ arr[q[1]]);
            } else {
                // If the left index of the query is 0, the result is simply arr[q[1]]
                result.push_back(arr[q[1]]);
            }
        }

        // Return the result vector containing answers for all queries
        return result;
    }
};

/*
Approach:
1. Convert the input array `arr` into a prefix XOR array. This means that each element at index `i` in `arr` will be the XOR of all elements from index 0 to `i`.
2. For each query `[L, R]`, compute the XOR of the subarray from index `L` to `R`. This can be efficiently computed using the prefix XOR array:
   - If `L > 0`, the XOR of the subarray [L, R] can be derived as `arr[R] ^ arr[L-1]`.
   - If `L == 0`, the XOR of the subarray [L, R] is simply `arr[R]`.
3. Use the prefix XOR array to quickly resolve each query in constant time.

Time Complexity:
- O(n + q), where `n` is the number of elements in `arr` and `q` is the number of queries. Building the prefix XOR array takes O(n) time, and resolving each query takes O(1) time, making the total time complexity O(n + q).

Space Complexity:
- O(1) if we disregard the space required for the input and output, since the solution uses the input array itself for the prefix XOR computation and only a fixed amount of additional space is used for the result vector.
*/
