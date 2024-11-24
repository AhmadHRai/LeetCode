class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int minVal = INT_MAX;
        int negativeCount = 0;
        
        for (const auto& row : matrix) {
            for (int num : row) {
                sum += abs(num); // Add the absolute value of each number to the sum
                minVal = min(minVal, abs(num)); // Update the minimum absolute value
                negativeCount += (num >> 31) & 1; // Increment negativeCount if the number is negative (using bitwise operation)
            }
        }
        
        // If the number of negative numbers is odd, subtract twice the smallest absolute value
        // to maximize the sum, since flipping a negative number to positive gives the largest increase
        return (negativeCount & 1) ? sum - (minVal << 1) : sum;
    }
};

/*
Approach Summary:
- The solution calculates the maximum possible sum of a matrix by flipping negative elements to positive.
- It first calculates the sum of absolute values of all elements in the matrix.
- It keeps track of the smallest absolute value and counts the number of negative values in the matrix.
- If the count of negative values is odd, flipping one negative value to positive decreases the sum, so the smallest absolute value is subtracted twice to correct the sum.
- The answer is the sum of absolute values, adjusted based on the count of negative values.

Complexity Analysis:
- Time Complexity: O(m * n), where m is the number of rows and n is the number of columns in the matrix.
  - We iterate through each element of the matrix exactly once to calculate the sum of absolute values, track the minimum absolute value, and count negative numbers.
- Space Complexity: O(1), as we only use a few additional variables (sum, minVal, negativeCount) and do not use any extra space proportional to the input size.
*/
