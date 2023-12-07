// The class definition for the solution
class Solution {
public:
    // The function that takes a string of digits as input and returns the largest odd number that can be formed by removing some or all of the digits from the right of the input string, or an empty string if there is no such number
    string largestOddNumber(string num) {
        // A loop that iterates over the input string from the rightmost digit to the leftmost digit
        for (int i = num.size() - 1; i >= 0; --i)
            // If the current digit is odd, meaning the remainder of dividing it by 2 is 1
            if ((num[i] - '0') % 2)
                // Return the substring of the input string from the leftmost digit to the current digit, inclusive
                return num.substr(0, i + 1);
        // If the loop ends without finding any odd digit, return an empty string
        return string();
    }
};

/* 
    Approach:
        The approach is based on the idea of finding the largest odd number that can be formed by removing some or all of the digits from the right of the input 
        string. An odd number is a number that is not divisible by 2, meaning the remainder of dividing it by 2 is 1. To do this, we use a loop to iterate over 
        the input string from the rightmost digit to the leftmost digit and check if the current digit is odd. We use the ASCII code of the digits to convert them 
        to integers. For example, the ASCII code of ‘0’ is 48, so ‘0’ - ‘0’ is 0, ‘1’ - ‘0’ is 1, and so on. If the current digit is odd, we return the substring 
        of the input string from the leftmost digit to the current digit, inclusive. This is the largest odd number that can be formed by removing some or all of 
        the digits from the right of the input string, because it preserves the most significant digits and the rightmost odd digit. If the loop ends without 
        finding any odd digit, we return an empty string, because there is no odd number that can be formed by removing some or all of the digits from the right 
        of the input string.

    Complexity:
        Time: O(N), where N is the length of the input string. This is because we need to iterate over the input string once and perform constant time operations 
        on each digit.
        Space: O(1), where 1 is a constant. This is because we only need to store the loop variable and the return value, which take constant space.

 */