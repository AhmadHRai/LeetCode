class Solution {
public:
    int countVowelPermutation(int n) {
        // Initialize variables
        long a = 1, e = 1, i = 1, o = 1, u = 1, mod = pow(10, 9)+7;
        long a2, e2, i2, o2, u2; 
        
        // Loop through all values of n
        for (int j = 2; j <= n; j++) {
            // Calculate new values for each vowel
            a2 = (e + i + u) % mod;
            e2 = (a + i) % mod;
            i2 = (e + o) % mod;
            o2 = i;
            u2 = (o + i) % mod;
            
            // Update values for each vowel
            a = a2, e = e2, i = i2, o = o2, u = u2;
        }
        
        // Return sum of all vowel counts modulo mod
        return (a + e + i + o + u) % mod;
    }
};

/* The `countVowelPermutation` function takes an integer `n` as input and returns an integer. The function calculates the number of strings of length `n` that can be formed 
using vowels such that each vowel appears at most once in each string. The function uses dynamic programming to calculate the result.

The time complexity of this function is O(n), since it loops through all values of n exactly once. The space complexity is O(1), since it only uses a constant amount of 
memory regardless of the value of n. */
