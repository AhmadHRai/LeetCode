class Solution {
public:
    // Function to determine if it's possible to provide change for all customers
    bool lemonadeChange(vector<int>& bills) {
        // Initialize counters for $5 and $10 bills
        int five_dollars = 0, ten_dollars = 0;
        
        // Iterate over each bill in the input vector
        for (int x : bills) {
            // If the bill is $5, increment the $5 bill counter
            if (x == 5) {
                five_dollars++;
            } 
            // If the bill is $10
            else if (x == 10) {
                // Check if there's at least one $5 bill available for change
                if (five_dollars > 0) {
                    // Provide change: decrement $5 bill counter and increment $10 bill counter
                    five_dollars--;
                    ten_dollars++;
                } else {
                    // Not enough $5 bills to give change, return false
                    return false;
                }
            } 
            // If the bill is $20
            else {
                // Prefer to use one $10 bill and one $5 bill if possible
                if (five_dollars > 0 && ten_dollars > 0) {
                    five_dollars--;
                    ten_dollars--;
                } 
                // If no $10 bill is available, check if there are at least three $5 bills
                else if (five_dollars > 2) {
                    five_dollars -= 3;
                } else {
                    // Not enough $5 or $10 bills to give change, return false
                    return false;
                }
            }
        }
        
        // If all bills are processed and change can be provided, return true
        return true;
    }
};

/*
Approach Summary:
- Maintain counters for $5 and $10 bills.
- Process each bill in sequence:
  - If it's $5, just increment the $5 bill counter.
  - If it's $10, decrement the $5 bill counter if available; otherwise, return false.
  - If it's $20, prefer giving one $10 and one $5 as change; if not possible, give three $5 bills if available; otherwise, return false.
- Return true if all bills are processed successfully with the required change.

Time Complexity:
- O(n), where n is the number of bills, as each bill is processed exactly once.

Space Complexity:
- O(1), as the space used is constant and does not depend on the input size.
*/
