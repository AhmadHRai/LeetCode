// Define maximum array size
const int MAX_N = 100000 + 1;

// Pointer to the input array of integers
int* nums;

// Array to store prefix sums and another to store positions in the deque
long long st_s[MAX_N];
int pos[MAX_N];

// Solution class containing the method to solve the problem
class Solution {
public:
    // Function to find the shortest subarray with a sum >= k
    int shortestSubarray(vector<int>& _nums, int k) {
        int n = _nums.size();         // Store the size of the input array
        nums = &_nums[0];             // Point to the start of the input array
        
        long long sp = 0LL;           // Variable to accumulate the prefix sum
        int res = n + 1;              // Initialize the result as the worst case (max length + 1)

        int b = 0, e = 0;             // Two pointers for the deque (begin and end)
        st_s[e] = 0;                  // Initialize the deque with the sum of 0
        pos[e++] = -1;                // Position corresponding to sum 0 is -1

        // Loop over the input array to calculate prefix sums
        for (int i = 0; i < n; i++) {
            sp += nums[i];            // Add the current element to the prefix sum

            // Check if we can pop elements from the deque to get a valid subarray
            while (b < e && sp - st_s[b] >= k) {
                res = std::min(res, i - pos[b]);  // Update the result with the shortest subarray length
                b++;  // Move the left pointer of the deque
            }

            // Ensure that the deque is in increasing order of prefix sums
            while (b < e && sp <= st_s[e - 1])
                e--;  // Pop elements from the end of the deque if necessary
            
            // Add the current prefix sum and its index to the deque
            st_s[e] = sp;
            pos[e++] = i;
        }

        // If no valid subarray was found, return -1
        if (res == n + 1)
            return -1;
        
        // Return the length of the shortest subarray
        return res;
    }
};

/*
    Approach Summary:
    - This problem is solved using a sliding window technique with a deque (double-ended queue).
    - We maintain a prefix sum and use a deque to efficiently track the sums encountered so far.
    - The idea is to find the shortest subarray such that the sum of the subarray is >= k.
    - The algorithm keeps track of the current prefix sum and uses the deque to store both prefix sums and their corresponding indices.
    - If at any point the difference between the current prefix sum and the oldest prefix sum in the deque is >= k, a valid subarray is found, and we attempt to update the result.
    - The deque helps in maintaining an ordered set of prefix sums, so we can efficiently find subarrays that satisfy the sum condition.
    
    Time Complexity:
    - The time complexity of this approach is O(n), where n is the number of elements in the input array.
    - Each element is pushed and popped from the deque at most once, ensuring the algorithm runs in linear time.

    Space Complexity:
    - The space complexity is O(n) due to the storage used for the prefix sums (`st_s`) and the positions (`pos`), both of size n.
*/
