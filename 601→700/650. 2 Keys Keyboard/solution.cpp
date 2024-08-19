class Solution {
public:
    // Function to find the minimum number of steps to reach number `n` using operations
    int minSteps(int n) {
        // Base case: If n is 1, no steps are needed
        if (n == 1) return 0;
        
        // Initialize the number of steps required
        int steps = 0;
        // Start with the smallest prime factor
        int factor = 2;
        
        // Process the number `n` to factorize it
        while (n > 1) {
            // While the current factor divides `n`, accumulate steps and reduce `n`
            while (n % factor == 0) {
                steps += factor;
                n /= factor;
            }
            // Move to the next potential factor
            factor++;
        }
        
        // Return the total number of steps required
        return steps;
    }
};

/*
Approach Summary:
- Factorize the number `n` by dividing it by all possible factors starting from 2.
- For each factor, add the factor to the total steps count as long as it divides `n`.
- After processing all factors, the total steps count will represent the minimum steps required to reach `n` using the allowed operations.

Time Complexity:
- O(sqrt(n)), where n is the number to be factorized. The inner loop runs in O(log n) time for each factor, and we check all factors up to sqrt(n).

Space Complexity:
- O(1), as only a few integer variables are used, regardless of the input size.
*/
