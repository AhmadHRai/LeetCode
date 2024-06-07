class Solution {
public:
    bool judgeSquareSum(int c) {
        // Iterate through potential divisors up to the square root of c.
        for (int divisor = 2; divisor * divisor <= c; divisor++) {
            // Check if divisor divides c.
            if (c % divisor == 0) {
                int exponentCount = 0;
                // Count the exponent of the divisor in the factorization of c.
                while (c % divisor == 0) {
                    exponentCount++;
                    c /= divisor;
                }
                // If divisor % 4 == 3 and exponentCount is odd, return false.
                if (divisor % 4 == 3 && exponentCount % 2 != 0) {
                    return false;
                }
            }
        }
        // After all possible divisors, check if c itself is not of the form 4k + 3.
        return c % 4 != 3;
    }
};

/*

Explanation

The `judgeSquareSum` function determines if a given integer c can be expressed as the sum of two squares.

Approach:
- Iterate through potential divisors up to the square root of c.
- For each divisor that divides c, count its exponent in the factorization of c.
- Check the properties of divisors of the form 4k + 3. If any such divisor has an odd exponent, return false.
- Finally, check if c itself is not of the form 4k + 3.

Example:
If c = 25:
- Factorization: 25 = 5^2. Since 5 % 4 != 3, return true.

Complexity:

Time Complexity:
- O(sqrt(c)) in the worst case, iterating through potential divisors up to sqrt(c).
- The factorization and checks within each iteration are efficient.

Space Complexity:
- O(1), as only a few extra variables are used regardless of input size.

*/

