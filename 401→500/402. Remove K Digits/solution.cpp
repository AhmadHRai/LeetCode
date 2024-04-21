class Solution {
public:
    string removeKdigits(string num, int k) {
        // If the number of digits to remove is greater than or equal to the length of the number,
        // return "0" because it's impossible to remove all digits.
        if(num.length() <= k)   
            return "0";
        
        // If no digits need to be removed, return the original number.
        if(k == 0)
            return num;
        
        string res = ""; // Initialize the result string.
        stack<char> s; // Initialize a stack to keep track of the digits.
        
        // Push the first character of the number into the stack.
        s.push(num[0]);
        
        // Iterate through the rest of the number.
        for(int i = 1; i < num.length(); ++i) {
            // While there are still digits to remove and the current digit is less than the top of the stack,
            // remove the top of the stack.
            while(k > 0 && !s.empty() && num[i] < s.top()) {
                --k;
                s.pop();
            }
            
            // Push the current digit onto the stack.
            s.push(num[i]);
            
            // If the stack size is 1 and the current digit is '0', pop it from the stack.
            if(s.size() == 1 && num[i] == '0')
                s.pop();
        }
        
        // If there are still digits to remove, pop them from the stack.
        while(k && !s.empty()) {
            --k;
            s.pop();
        }
        
        // Build the result string by popping elements from the stack.
        while(!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }
        
        // Reverse the result string since the digits were added in reverse order.
        reverse(res.begin(), res.end());
        
        // If the result string is empty, return "0".
        if(res.length() == 0)
            return "0";
        
        // Return the result string.
        return res;
    }
};

/* 
Approach

    The solution uses a stack to keep track of the digits in the number. It iterates through the number, pushing each digit onto the stack. If the current digit is less than the top 
    of the stack and there are still digits to remove, it pops the top of the stack. This process ensures that the digits in the stack are in non-decreasing order. After iterating 
    through the number, if there are still digits to remove, it pops them from the stack. Finally, it builds the result string by popping elements from the stack and reversing the 
    string. If the result string is empty, it returns "0".

Complexity

    Time complexity: O(n), where n is the length of the number. This is because each digit in the number is processed exactly once.
    
    Space complexity: O(n), due to the use of a stack to store the digits. In the worst-case scenario, the stack could contain all digits from the number.
*/
