#include <bitset>
#include <cmath> // For sqrt() function

class Solution {
public:
    // Function to check if a number is prime
    bool isPrime(int n) {
        if (n <= 1) {
            return false; // Handle edge cases for 1 and numbers less than 1
        }
        for (int i = 2; i * i <= n; ++i) { // Optimized loop for prime checking
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    // Function to count numbers with a prime number of set bits in their binary
    // representation
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for (int i = left; i <= right; i++) {
            // Use std::bitset to count set bits (1's) in the binary
            // representation of i
            if (isPrime(
                    std::bitset<32>(i).count())) { // Replace __builtin_popcount
                                                   // with std::bitset
                ans++;
            }
        }
        return ans;
    }
};
