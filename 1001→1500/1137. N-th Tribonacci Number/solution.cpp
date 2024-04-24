class Solution {
public:
    int tribonacci(int n) {
        // Base cases: if n is 0, return 0; if n is 1 or 2, return 1
        if(n == 0)
            return 0;
        if(n == 1 || n == 2)
            return 1;
        // Initialize a vector to store the tribonacci numbers up to n
        vector<int> Tribonacci(n+1);
        // Set the initial values for the tribonacci sequence
        Tribonacci[0] = 0;
        Tribonacci[1] = 1;
        Tribonacci[2] = 1;
        // Calculate the tribonacci numbers for n > 2
        for(int i = 3; i < n+1; i++){
            // Each tribonacci number is the sum of the three preceding ones
            Tribonacci[i] = Tribonacci[i-1] + Tribonacci[i-2] + Tribonacci[i-3];
        }
        // Return the tribonacci number for n
        return Tribonacci[n];
    }
};

/* 
Approach:

This solution uses dynamic programming to calculate the tribonacci number for a given index n. The tribonacci sequence is defined as T[n] = T[n-1] + T[n-2] + T[n-3], 
with base cases T[0] = 0, T[1] = 1, and T[2] = 1.

    1. Initialize a vector `Tribonacci` with size `n+1` to store the tribonacci numbers up to `n`.
    2. Set the base cases for the tribonacci sequence: `Tribonacci[0] = 0`, `Tribonacci[1] = 1`, and `Tribonacci[2] = 1`.
    3. Iterate from `i = 3` to `n+1`, calculating each tribonacci number as the sum of the three preceding ones.
    4. Return the tribonacci number for `n`.

Complexity Analysis:

Time Complexity: O(n), where n is the input number. This is because the algorithm iterates through the sequence up to `n` once.
Space Complexity: O(n), where n is the input number. This is due to the storage required for the `Tribonacci` vector, which stores the tribonacci numbers up to `n`.

This approach is efficient for solving the problem within the given constraints, as it systematically calculates the tribonacci numbers using a bottom-up approach.
*/