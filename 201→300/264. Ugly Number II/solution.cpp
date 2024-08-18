class Solution {
public:
    int nthUglyNumber(int n) {
        // Handle edge case where n is less than or equal to 0
        if (n <= 0) return false; // invalid input
        
        // Base case where n is 1, the first ugly number is 1
        if (n == 1) return 1;
        
        // Initialize pointers for the indices corresponding to 2, 3, and 5
        int t2 = 0, t3 = 0, t5 = 0;
        // Create a vector to store the first n ugly numbers
        vector<int> k(n);
        // The first ugly number is 1
        k[0] = 1;
        
        // Compute the nth ugly number
        for (int i = 1; i < n; i++) {
            // Compute the next ugly number as the minimum of 2, 3, and 5 multiples
            k[i] = min(k[t2] * 2, min(k[t3] * 3, k[t5] * 5));
            
            // Update pointers based on which multiple was chosen
            if (k[i] == k[t2] * 2) t2++; 
            if (k[i] == k[t3] * 3) t3++;
            if (k[i] == k[t5] * 5) t5++;
        }
        
        // Return the nth ugly number
        return k[n - 1];
    }
};

/*
Approach Summary:
- Use three pointers to keep track of the indices for multiplying 2, 3, and 5.
- Start with the first ugly number (1).
- At each step, compute the next ugly number by taking the minimum of the values obtained by multiplying the numbers at the current pointers by 2, 3, and 5.
- Update the pointers based on which multiple was used to ensure all multiples are considered and no duplicates are included.
- The result after processing n elements is the nth ugly number.

Time Complexity:
- O(n), where n is the number of ugly numbers to be found. Each number is computed in constant time, and we iterate through the list once.

Space Complexity:
- O(n), where n is the number of ugly numbers. We use a vector of size n to store the ugly numbers.
*/
