class Solution {
public:
    int romanToInt(string s) {
        int result = 0; // initialize result to zero
        // use an array to store the values of each symbol
        int values[256] = {0};
        values['I'] = 1;
        values['V'] = 5;
        values['X'] = 10;
        values['L'] = 50;
        values['C'] = 100;
        values['D'] = 500;
        values['M'] = 1000;

        // start from the end of the string and move backwards
        for (int i = s.length() - 1; i >= 0; i--) {
            // get the value of the current symbol
            int value = values[s[i]];
            // use a switch statement to handle each symbol
            switch (s[i]) {
                // if the symbol is I, X, or C, check if it is smaller than the previous one
                case 'I':
                case 'X':
                case 'C':
                    // if it is smaller, subtract it from the result
                    if (i < s.length() - 1 && value < values[s[i + 1]]) {
                        result -= value;
                    }
                    // otherwise, add it to the result
                    else {
                        result += value;
                    }
                    break;
                // otherwise, just add it to the result
                default:
                    result += value;
            }
        }
        // return the final result
        return result;
    }
};

/*
The time complexity of this code is O(m), where m is the length of the string, since it iterates over each character once. The space complexity is O(1), since it uses a constant amount of extra space for the array.
*/