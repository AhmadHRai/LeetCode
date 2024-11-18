class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) 
    {
        // Get the size of the input array 'code'
        int n = code.size();

        // Initialize the result array with zeros, the same size as the input array
        vector<int> res(n, 0);
        
        // If k is 0, all elements should be replaced by 0
        if(k == 0)
            return res;

        // Initialize 'start' and 'end' to denote the window of elements we need to sum
        int start = 1, end = k;

        // If k is negative, adjust the window to be from the last 'k' elements
        if(k < 0)
        {
            k *= -1;  // Convert k to positive to handle the sum of previous elements
            start = n - k;  // Start window from 'n-k' to the end
            end = n - 1;    // End window at the last element
        }

        // Variable to keep track of the sum of the current window of 'k' elements
        int sum = 0;

        // Initialize the first window by summing elements from 'start' to 'end'
        for(int i = start; i <= end; i++)
            sum += code[i];
        
        // Iterate over the entire array to compute the result
        for(int i = 0; i < n; i++)
        {
            // Set the sum of the current window to the result array
            res[i] = sum;

            // Slide the window to the right by removing the element at 'start'
            // and adding the element at 'end'
            sum -= code[(start++) % n];   // Subtract the element at 'start' and increment 'start'
            sum += code[(++end) % n];     // Add the element at 'end' and increment 'end'
        }
        
        // Return the result array
        return res;
    }
    
    /*
    Approach:
    1. First, we need to handle the case where k == 0, in which case the result array will just be all zeros.
    2. If k is positive, we need to replace each element at index i with the sum of the next k elements in the circular array.
    3. If k is negative, we replace each element with the sum of the previous k elements.
    4. We use a sliding window technique to maintain the sum of the current k elements, adjusting the window as we move from index to index in the array. 
    5. The circular nature of the array is handled using modulo operations when accessing elements that are out of bounds (i.e., when the indices wrap around the array).
    6. The overall time complexity of the algorithm is O(n), where n is the length of the array. This is because we initialize the sum in O(k) time, and then adjust the sum in constant time for each index as we slide the window.

    Complexity Analysis:
    - Time Complexity: O(n), where n is the length of the input array. We perform a sliding window operation, which requires a linear scan of the array.
    - Space Complexity: O(n), where n is the size of the input array, as we store the result in a new vector.
    */
};
