// The class definition for the solution
class Solution {
public:
    // The function that takes a string of digits as input and returns the largest good integer that can be formed by three consecutive digits in the input string, or an empty string if there is no such integer
    string largestGoodInteger(string num) {
        // A variable that stores the result, initialized to -1
        int result = -1;
        // A loop that iterates over the input string until the third last digit
        for (int i = 0; i + 2 < num.length(); i++) {
            // If the current digit and the next two digits are the same, they form a good integer
            if (num[i] == num[i + 1] && num[i] == num[i + 2]) {
                // Update the result with the maximum of the current result and the numerical value of the current digit
                result = std::max(result, num[i] - '0');
            }
        }
        // Return the result as a string of three digits, or an empty string if the result is -1
        return (result == -1) ? "" : std::string(3, '0' + result);
    }
};

/* 
The time complexity of this solution is O(N), where N is the length of the input string. This is because we need to iterate over the input string once and perform constant time 
operations on each digit. 
The space complexity is O(1), where 1 is a constant. This is because we only need to store the result variable, which takes constant space.
 */