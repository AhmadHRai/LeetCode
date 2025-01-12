class Solution {
public:
    // Function to determine if the string can be valid based on locked and unlocked brackets
    bool canBeValid(string s, string locked) {
        const int n = s.size(); // Get the length of the string
        
        // If the length is odd, it's impossible to form valid pairs of brackets
        if (n & 1) return 0; 
        
        // Initialize minimum and maximum balance of brackets
        int bMin = 0, bMax = 0;
        
        // Iterate through the string to calculate bracket balance
        for (int i = 0; i < n; i++) {
            // Check if current character is an open bracket and if it's unlocked
            bool op = s[i] == '(', wild = locked[i] == '0';
            
            // Update minimum balance: decrease for unlocked or closing brackets, increase for open brackets
            bMin += (!op | wild) ? -1 : 1;
            // Update maximum balance: increase for open brackets or unlocked positions, decrease for closing brackets
            bMax += (op | wild) ? 1 : -1;
            
            // If maximum balance drops below zero, return false (more closing than opening)
            if (bMax < 0) return 0;
            // Ensure minimum balance does not go below zero
            bMin = max(bMin, 0);
        }
        
        // Return true if minimum balance is zero, indicating all brackets can be matched
        return bMin == 0;
    }
};

/*
Approach Summary:
The function checks whether the string `s` can be made valid by considering locked and unlocked brackets. It first checks if the length of `s` is odd, which cannot form valid pairs. The algorithm maintains two counters: `bMin` for the minimum possible balance of brackets and `bMax` for the maximum possible balance. As it iterates through the string, it adjusts these balances based on whether characters are open brackets or unlocked positions. Finally, it checks if `bMin` is zero to determine if all brackets can be matched.

Complexity Analysis:
- Time Complexity: O(n), where n is the length of the string `s`. The function makes a single pass through the string.
- Space Complexity: O(1), as only a fixed number of integer variables are used regardless of input size.
*/
