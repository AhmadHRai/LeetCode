/* 
Given an integer n, return true if it is possible to represent n as the sum of distinct powers of three. Otherwise, return false.

An integer y is a power of three if there exists an integer x such that y == 3^x.
*/

class Solution {
public:
    bool checkPowersOfThree(int n) {
        for (int i = n; i > 0; i /= 3) {
            if (i % 3 == 2)
                return false;
        }
        return true;
    }
};