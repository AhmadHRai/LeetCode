class Solution {
public:
    int findTheWinner(int n, int k) { 
        // Find the winner's position in a 1-indexed system
        // by applying the Josephus problem solution and adding 1
        return winnerHelper(n, k) + 1; 
    }

private:
    int winnerHelper(int n, int k) {
        // Base case: when there is only one person, the position is 0
        // Recursive case: calculate the Josephus position for n - 1 people
        if (n == 1) return 0;
        return (winnerHelper(n - 1, k) + k) % n;
    }
};

/* 
Approach

    The solution uses a recursive approach to solve the Josephus problem, which determines the safe position in a circle where every k-th person is eliminated until only one person remains.
    - The `winnerHelper` method calculates the position of the winner for `n` people and step `k` using a recursive formula.
    - The `findTheWinner` method converts the 0-indexed result (from the `winnerHelper` method) to a 1-indexed result (as required by the problem) by adding 1.

Complexity

    Time complexity: O(n), due to the recursion depth and calls made to the `winnerHelper` method.
    
    Space complexity: O(n), due to the recursive call stack used in the `winnerHelper` method.
 */
