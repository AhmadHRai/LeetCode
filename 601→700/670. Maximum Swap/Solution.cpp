#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        // Convert the integer number to a string for easier manipulation of digits
        string numStr = to_string(num);
        int n = numStr.size();
        
        // Vector to store the last occurrence index of each digit (0-9)
        vector<int> last(10, -1);
        for (int i = 0; i < n; ++i) {
            last[numStr[i] - '0'] = i;
        }
        
        // Traverse the number from left to right
        for (int i = 0; i < n; ++i) {
            // Check from digit 9 down to the current digit if any appears later in the number
            for (int d = 9; d > numStr[i] - '0'; --d) {
                if (last[d] > i) {
                    // Swap the current digit with the larger one found later
                    swap(numStr[i], numStr[last[d]]);
                    return stoi(numStr); // Convert the string back to integer and return
                }
            }
        }
        
        // Return the original number if no swap was possible
        return num;
    }
};

/*
Approach:
1. Convert the Integer to a String:
   - This allows for easy digit manipulation since each character in the string represents a digit of the integer.

2. Record the Last Occurrence of Each Digit:
   - Use a vector `last` where `last[d]` stores the index of the last occurrence of the digit `d` in the number.
   - This helps in determining if a larger digit exists later in the number for potential swaps.

3. Traverse from Left to Right to Find the Optimal Swap:
   - For each digit, check if there is any higher digit from 9 down to the current digit that appears later in the number.
   - If found, swap the current digit with the highest possible digit that appears later, and immediately return the result (since only one swap is allowed).

4. Return the Original Number if No Swap Occurs:
   - If no advantageous swap is found, return the original number.

Complexity Analysis:
- Time Complexity: O(n), where n is the number of digits in the input number. The traversal and look-up operations are done in a single pass.
- Space Complexity: O(1), as the `last` vector has a fixed size of 10 for digits 0-9, regardless of the input size.
*/
