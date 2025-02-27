class Solution {
    public:
        int lenLongestFibSubseq(vector<int>& arr) {
            int n = arr.size(); // Number of elements in the array
    
            // Store array elements in a set for O(1) lookup
            unordered_set<int> numSet(arr.begin(), arr.end());
    
            int maxLen = 0; // Maximum length of Fibonacci-like subsequence found
    
            // Try all possible first two numbers of the sequence
            for (int start = 0; start < n; ++start) {
                for (int next = start + 1; next < n; ++next) {
                    // Start with the first two numbers
                    int prev = arr[next];
                    int curr = arr[start] + arr[next];
                    int len = 2; // Initial length of the sequence
    
                    // Keep finding the next Fibonacci number
                    while (numSet.find(curr) != numSet.end()) {
                        // Update values for the next iteration
                        int temp = curr;
                        curr += prev;
                        prev = temp;
                        len++; // Increment the length of the sequence
                        maxLen = max(maxLen, len); // Update the maximum length
                    }
                }
            }
    
            // Return the maximum length found, but only if it's greater than 2
            return maxLen > 2 ? maxLen : 0;
        }
    }
    /*
    Approach Summary:
        This solution uses a brute-force approach to find the longest Fibonacci-like subsequence by trying all possible pairs of starting numbers and checking if they can 
        form a Fibonacci sequence within the given array. It leverages a set for efficient lookup of numbers in the array.
    
    Complexity Analysis:
    - Time Complexity: O(N^2 * M)
        where N is the number of elements in the array and M is the maximum length of a Fibonacci sequence that can be formed. This is because for each pair of starting 
        numbers, we potentially iterate through the sequence.
    
    - Space Complexity: O(N), for storing the set of numbers.
    */
    