class Solution {
public:
    // Function to perform addition of fractions given as a string expression
    string fractionAddition(string expression) {
        // Create an input string stream from the expression string
        istringstream in(expression);
        
        // Initialize the result fraction as 0/1
        int A = 0, B = 1;
        int a, b;
        char _;
        
        // Read each fraction from the input stream
        while (in >> a >> _ >> b) {
            // Compute the new numerator and denominator
            A = A * b + a * B;
            B *= b;
            
            // Compute the greatest common divisor (GCD) of the numerator and denominator
            int g = abs(__gcd(A, B));
            
            // Simplify the fraction by dividing both numerator and denominator by the GCD
            A /= g;
            B /= g;
        }
        
        // Return the result as a string in the format "numerator/denominator"
        return to_string(A) + '/' + to_string(B);
    }
};

/*
Approach Summary:
- Use an input string stream to parse and process each fraction in the expression.
- Initialize the result fraction as 0/1.
- For each fraction in the expression:
  - Update the result fraction by combining it with the current fraction.
  - Simplify the result fraction using the greatest common divisor (GCD).
- Return the final simplified fraction in the format "numerator/denominator".

Time Complexity:
- O(n), where n is the length of the input string. Each fraction is processed once, and the GCD computation is constant time for each pair of numerators and denominators.

Space Complexity:
- O(1), as the space used is constant and does not depend on the size of the input but only on a few integer variables.
*/
