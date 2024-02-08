class Solution {
public:
    int numSquares(int n) {
        // Divide n by 4 as many times as possible, because 4 is a perfect square
        while(n % 4 == 0){
            n /= 4;
        }
        
        // If n is 7 modulo 8, then it is a sum of 4 squares, by the theorem
        if(n%8 == 7) return 4;
        
        // Initialize a boolean variable to indicate if n has a factor whose exponent is odd
        bool min2 = false;
        
        // Loop over the possible factors of n from 2 to n
        for(int factor = 2; factor <= n; ++factor){
            // If factor is larger than the square root of n, then n is a prime factor
            if(factor > n/factor){
                factor = n;
            }
            
            // Initialize an integer variable to store the exponent of the current factor
            int exp = 0;
            // Divide n by the factor as many times as possible, and increment the exponent
            while(n % factor == 0){
                n /= factor;
                ++exp;
            }
            
            // If the factor is 3 modulo 4, and the exponent is odd, then n is a sum of 3 squares, by the theorem
            if(factor%4 == 3 && exp%2 == 1){
                return 3;
            }
            
            // If the exponent is odd, set min2 to true, because n has at least two squares in its sum
            min2 |= exp%2;
        }
        
        // If min2 is true, return 2, otherwise return 1, because n is either a perfect square or a sum of two squares
        return 1 + min2;
    }
};

/* 
Complexity:
    The time complexity of the code is O(sqrt(n)), where n is the input integer. This is because we need to loop over the possible factors of n up to its square root, and each 
    operation is constant time. The division by 4 and the modulo 8 operations are also constant time.
    
    The space complexity of the code is O(1), because we only use a few variables, and they do not depend on the input size.
 */