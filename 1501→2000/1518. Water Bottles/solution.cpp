class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        // Return the total number of bottles that can be drunk:
        // - numBottles: initial full bottles
        // - (numBottles - 1) / (numExchange - 1): calculates the number of additional bottles that can be obtained through exchanges
        return numBottles + (numBottles - 1) / (numExchange - 1);
    }
};

/* 
Approach

    The solution calculates the maximum number of bottles that can be drunk by combining the initial full bottles with additional bottles obtained through exchanges. 
    - The initial number of bottles drunk is given by `numBottles`.
    - To find the number of additional bottles that can be drunk through exchanges, the formula `(numBottles - 1) / (numExchange - 1)` is used. This formula calculates how many full bottles can be obtained from the empty bottles and adds to the total.

Complexity

    Time complexity: O(1), since the solution involves only arithmetic operations.
    Space complexity: O(1), as no extra space is used beyond the input variables.
 */
