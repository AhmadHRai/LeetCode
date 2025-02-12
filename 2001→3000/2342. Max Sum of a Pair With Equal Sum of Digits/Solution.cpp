class Solution {
    public:
        int maximumSum(vector<int>& nums) {
            int result = -1; // Initialize result to -1 (no pair found)
    
            // Array to store the maximum number for each possible digit sum
            int digits[82] = {};
    
            for (int num : nums) {
                int sum = 0; // Calculate the sum of digits for the current number
    
                // Calculate the sum of digits
                for (int curr = num; curr; curr /= 10) {
                    int digit = curr % 10;
                    sum += digit;
                }
    
                // If there's already a number with the same digit sum, update the result
                if (digits[sum] > 0) {
                    result = max(result, digits[sum] + num);
                }
    
                // Update the maximum number for this digit sum
                digits[sum] = max(digits[sum], num);
            }
    
            return result;
        }
    }

    /*
    Approach Summary:
        This solution iterates through the array, calculating the sum of digits for each number and storing the maximum number for each digit sum. It updates the result 
        whenever it finds two numbers with the same digit sum, ensuring the maximum sum is returned.
    
    Complexity Analysis:
        
        Time Complexity: O(N * log M), where N is the number of elements and M is the maximum value in the array, because each number is processed once and its digits are 
        summed.
        
        Space Complexity: O(1), as only a fixed-size array is used to store the maximum numbers for each digit sum.
    */
    