class Solution {
public:
    int myAtoi(string s) {
        int len = s.size();
        long long num = 0; // Use a long long variable to store the number
        int i = 0;
        while (s[i] == ' ') {
            i++;
        }
        bool sign = true; // Use a boolean variable to store the sign
        if (s[i] == '+') {
            i++;
        } else if (s[i] == '-') {
            sign = false;
            i++;
        }
        while (i < len && s[i] >= '0' && s[i] <= '9') {
            num = num * 10 + (s[i] - '0');
            i++;
            if (num > INT_MAX) { // Use a break statement to exit the loop
                break;
            }
        }
        num = sign ? num : -num; // Apply the sign to the number
        num = min(num, (long long)INT_MAX); // Use the constants INT_MAX and INT_MIN directly
        num = max(num, (long long)INT_MIN);
        return (int)num; // Cast the number to int
    }
};

/* 
Time complexity: O(n) where n is the length of the string s. The function loops through each character in s once and performs constant time operations.
Space complexity: O(1) where 1 is a constant. The function uses a few variables of fixed size to store the number, the sign, and the index.
 */