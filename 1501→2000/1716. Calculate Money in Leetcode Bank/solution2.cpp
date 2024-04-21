class Solution {
public:
    // Define the totalMoney method that takes an integer n as a parameter and returns an integer
    int totalMoney(int n) {
        // Calculate the number of complete weeks by dividing n by 7 and store it in a variable named w
        int w = n / 7;
        // Calculate the number of remaining days by taking the modulus of n by 7 and store it in a variable named d
        int d = n % 7;
        // Return the total money by using a formula that combines the contributions from the complete weeks and the remaining days
        // The formula is derived by using the arithmetic series formula for the sum of the money saved on each week and each day
        return (n * (w + 7) + d * (d + w - 6)) >> 1;
    }
};


/* The time complexity is O(1), because the calculations are done in constant time and do not depend on the value of n. 
The space complexity is O(1), because no extra space is used apart from the input parameter and some variables. */