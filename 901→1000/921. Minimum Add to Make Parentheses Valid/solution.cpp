class Solution {
public:
    int minAddToMakeValid(string s) {
        int balance = 0; // Tracks the balance of parentheses
        int additions = 0; // Counts the number of additions needed

        for (char c : s) {
            if (c == '(') {
                balance++; // Increment balance for an opening parenthesis
            } else { // c is ')'
                if (balance > 0) {
                    balance--; // Decrement balance for a matching opening parenthesis
                } else {
                    additions++; // No matching opening, need to add one
                }
            }
        }
        
        // Remaining unmatched opening parentheses need closing ones
        return additions + balance; 
    }
};

/* 
Explanation

    Initialization:
        Two integer variables are initialized: balance to track the count of unmatched opening parentheses, 
        and additions to count how many parentheses need to be added.
    Iteration through the string:
        For each character in the string:
            If it is an opening parenthesis (, increment the balance.
            If it is a closing parenthesis ):
                If there is a matching opening parenthesis (i.e., balance > 0), decrement the balance.
                If there isn't (i.e., balance == 0), increment the additions counter since a new opening parenthesis is needed.
    Final Calculation:
        After processing all characters, any remaining unmatched opening parentheses (tracked by balance) indicate how many closing parentheses are needed. Thus, the total number of additions required to make the string valid is the sum of additions and balance.

Complexity

    Time Complexity: O(n), where nn is the length of the string, since we traverse it once.
    Space Complexity: O(1), as we only use a few integer variables.

 */