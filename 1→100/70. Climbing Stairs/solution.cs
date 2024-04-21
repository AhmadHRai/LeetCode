public class Solution {
    // This function takes an integer n and returns the number of distinct ways to climb a staircase of n steps
    public int ClimbStairs(int n) {
        // If n is less than or equal to 2, return the maximum of 1 and n as the base case
        if (n <= 2)
        {
            return Math.Max(1, n);
        }

        // Create an array of size n to store the number of ways to climb i steps for each i from 0 to n-1
        var fibonacci = new int[n];

        // Initialize the first two elements of the array as 1 and 2, corresponding to the base cases
        fibonacci[0] = 1;
        fibonacci[1] = 2;

        // Loop over the array from the third element
        for (int i = 2; i < fibonacci.Length; i++)
        {
            // Calculate the number of ways to climb i steps as the sum of the number of ways to climb i-1 and i-2 steps
            // This is because at each step, we can either climb 1 or 2 steps, so we can use the previous results
            fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
        }

        // Return the last element of the array as the answer
        return fibonacci[n - 1];
    }
}

/* 
    Complexity:
        The time complexity is O(n), where n is the number of steps. This is because the code uses a loop to iterate over the array of size n, and performs constant-time 
        operations in each iteration.
    
         The space complexity is O(n), because the code uses an array of size n to store the results of the subproblems.
*/

/* 
    Some key notes:
    - The code uses a dynamic programming approach to solve the problem of climbing stairs. Dynamic programming is a technique that breaks down a complex problem into smaller subproblems and stores the results of the subproblems to avoid recomputation.

    - The code uses an array to store the results of the subproblems, which are the number of ways to climb i steps for each i from 0 to n-1. The array is initialized with the base cases, which are 1 and 2 for 0 and 1 steps respectively.

    - The code uses a loop to fill the array with the results of the subproblems, which are calculated by adding the previous two results. This is based on the observation that at each step, we can either climb 1 or 2 steps, so the number of ways to climb i steps is equal to the number of ways to climb i-1 steps plus the number of ways to climb i-2 steps.

    - The code returns the last element of the array as the final answer, which is the number of ways to climb n steps.
*/