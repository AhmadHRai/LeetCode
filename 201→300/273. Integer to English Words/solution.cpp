// Tafqeed in En
class Solution {
public:
    // Converts numbers from 1 to 9 into their English words
    string one(int num) {
        switch(num) {
            case 1: return "One";      
            case 2: return "Two";      
            case 3: return "Three";    
            case 4: return "Four";     
            case 5: return "Five";     
            case 6: return "Six";      
            case 7: return "Seven";    
            case 8: return "Eight";    
            case 9: return "Nine";     
        }
        return ""; // Return an empty string if num is not between 1 and 9
    }

    // Converts numbers from 10 to 19 into their English words
    string twoLessThan20(int num) {
        switch(num) {
            case 10: return "Ten";     
            case 11: return "Eleven";  
            case 12: return "Twelve";  
            case 13: return "Thirteen";
            case 14: return "Fourteen";
            case 15: return "Fifteen"; 
            case 16: return "Sixteen"; 
            case 17: return "Seventeen";
            case 18: return "Eighteen";
            case 19: return "Nineteen";
        }
        return ""; // Return an empty string if num is not between 10 and 19
    }

    // Converts multiples of ten (20, 30, ..., 90) into their English words
    string ten(int num) {
        switch(num) {
            case 2: return "Twenty";   
            case 3: return "Thirty";   
            case 4: return "Forty";    
            case 5: return "Fifty";    
            case 6: return "Sixty";    
            case 7: return "Seventy";  
            case 8: return "Eighty";   
            case 9: return "Ninety";   
        }
        return ""; // Return an empty string if num is not between 2 and 9
    }

    // Converts numbers from 1 to 99 into English words
    string two(int num) {
        if (num == 0)                // If num is 0, return an empty string
            return "";
        else if (num < 10)           // If num is less than 10, use the 'one' function
            return one(num);
        else if (num < 20)           // If num is between 10 and 19, use the 'twoLessThan20' function
            return twoLessThan20(num);
        else {
            int tenner = num / 10;   // Calculate the tens place digit
            int rest = num - tenner * 10; // Calculate the units place digit
            if (rest != 0)           // If there's a non-zero units place
                return ten(tenner) + " " + one(rest); // Combine tens and units words
            else
                return ten(tenner); // If units place is zero, return only the tens word
        }
    }

    // Converts numbers from 1 to 999 into English words
    string three(int num) {
        int hundred = num / 100;     // Calculate the hundreds place digit
        int rest = num - hundred * 100; // Calculate the remaining part after hundreds
        string res = "";
        if (hundred * rest != 0)    // If both hundreds and rest are non-zero
            res = one(hundred) + " Hundred " + two(rest); // Combine hundreds and rest
        else if ((hundred == 0) && (rest != 0)) 
            res = two(rest);        // If hundreds is zero but rest is non-zero
        else if ((hundred != 0) && (rest == 0)) 
            res = one(hundred) + " Hundred"; // If hundreds is non-zero but rest is zero
        return res;                 // Return the result string
    }

    // Converts any number into English words
    string numberToWords(int num) {
        if (num == 0)                // If num is 0, return "Zero"
            return "Zero";

        int billion = num / 1000000000;    // Extract billions place
        int million = (num - billion * 1000000000) / 1000000; // Extract millions place
        int thousand = (num - billion * 1000000000 - million * 1000000) / 1000; // Extract thousands place
        int rest = num - billion * 1000000000 - million * 1000000 - thousand * 1000; // Remaining part

        string result = "";
        if (billion != 0)              // If billion part is non-zero
            result = three(billion) + " Billion"; // Convert and append billion part
        if (million != 0) {
            if (result.size() != 0)   // If result is not empty, add a space
                result += " ";
            result += three(million) + " Million"; // Convert and append million part
        }
        if (thousand != 0) {
            if (result.size() != 0)   // If result is not empty, add a space
                result += " ";
            result += three(thousand) + " Thousand"; // Convert and append thousand part
        }
        if (rest != 0) {
            if (result.size() != 0)   // If result is not empty, add a space
                result += " ";
            result += three(rest);    // Convert and append rest part
        }
        return result;               // Return the final result string
    }
};

/*
Approach:
1. The solution consists of multiple helper functions to convert numbers into English words.
2. The `one`, `twoLessThan20`, and `ten` functions handle the conversion of numbers in specific ranges.
3. The `two` function manages numbers from 1 to 99 by combining the results from the above helper functions.
4. The `three` function handles numbers from 1 to 999, considering hundreds and the remaining part.
5. The `numberToWords` function handles numbers from 0 to 999,999,999,999 by dividing the number into billions, millions, thousands, and the rest. Each part is converted and concatenated with appropriate labels.

Complexity Analysis:
1. Time Complexity: O(1) - The solution processes each number in constant time, as the operations are based on fixed divisions and condition checks.
2. Space Complexity: O(1) - The space used is constant as it only involves a few integer variables and strings for storing results.
*/
