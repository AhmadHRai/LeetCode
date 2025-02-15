class Solution {
    private:
        bool partition(string stringNum, int target) {
            // Base case: If the string is empty and the target is 0, it's a valid partition
            if (stringNum == "" && target == 0) return true;
            // If the target becomes negative, it's an invalid partition
            if (target < 0) return false;
    
            // Check all possible partitions of the string
            for (int index = 0; index < stringNum.size(); index++) {
                // Split the string into two parts: left and right
                string left = stringNum.substr(0, index + 1);
                string right = stringNum.substr(index + 1);
                int leftNum = stoi(left); // Convert the left part to an integer
    
                // Recursively check if the remaining part can be partitioned to reach the target
                if (partition(right, target - leftNum)) return true;
            }
            // If no valid partition is found, return false
            return false;
        }
    
    public:
        // Returns the sum of squares of numbers whose square can be partitioned into a sum equal to the number itself
        int punishmentNumber(int n) {
            int sum = 0; // Initialize sum to 0
    
            // Iterate through numbers from 1 to n
            for (int i = 1; i <= n; i++) {
                // Check if the square of the number can be partitioned into a sum equal to the number
                if (partition(to_string(i * i), i)) {
                    // If it can be partitioned, add the square to the sum
                    sum += i * i;
                }
            }
            return sum;
        }
    }

    /*
    Approach Summary:
        This solution checks each number up to n to see if its square can be partitioned into a sum equal to the number itself. It uses a recursive function to explore 
        all possible partitions of the square's digits.
    
    Complexity Analysis:
    - Time Complexity: O(N * 2^M), where N is the input number and M is the maximum number of digits in a square, because each digit can be part of a partition or not.
    - Space Complexity: O(M), for the recursive call stack.
    */
    