class Solution {
public:
    // Define the totalMoney method that takes an integer n as a parameter and returns an integer
    int totalMoney(int n) {
        // Calculate the number of complete weeks by dividing n by 7 and store it in a variable named week_count
        int week_count = n / 7;
        // Calculate the number of remaining days by taking the modulus of n by 7 and store it in a variable named remaining_days
        int remaining_days = n % 7;
        
        // Initialize a variable named total to store the total money and set it to zero
        int total = 0;
        // Calculate the contribution from the complete weeks by using the formula for the sum of an arithmetic series with a common difference of 7 and a first term of 28, and add it to the total variable
        // This is equivalent to finding the sum of the money saved on each Sunday of the complete weeks
        total += ((week_count * (week_count - 1)) / 2) * 7; // Contribution from complete weeks
        // Calculate the contribution from the complete weeks by multiplying the week_count by 28 and add it to the total variable
        // This is equivalent to finding the sum of the extra money saved on each Monday of the complete weeks
        total += week_count * 28; // Contribution from complete weeks (additional on Mondays)
        // Calculate the contribution from the remaining days by using the formula for the sum of an arithmetic series with a common difference of 1 and a first term of week_count + 1, and add it to the total variable
        // This is equivalent to finding the sum of the money saved on each day of the last incomplete week
        total += ((remaining_days * (remaining_days + 1)) / 2) + (week_count * remaining_days); // Contribution from remaining days
        
        // Return the total variable as the final answer
        return total;
    }
};

/* 
The time complexity is O(1), because the calculations are done in constant time and do not depend on the value of n. 
The space complexity is O(1), because no extra space is used apart from the input parameter and some variables.
 */