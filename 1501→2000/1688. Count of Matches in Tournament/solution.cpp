// The class definition for the solution
class Solution {
public:
    // The function that takes an integer n as input and returns the number of matches played in a tournament where n teams compete
    int numberOfMatches(int n) {
        // If n is greater than 1, there are n / 2 matches played in the current round, and the number of teams advanced to the next round is (n + 1) / 2
        // Recursively call the function with the number of teams in the next round and add the number of matches in the current round
        // If n is equal to 1, there are no more matches played and return 0
        return n > 1 ? n / 2 + numberOfMatches((n + 1) / 2) : 0;
    }
};

/*
// Another way to write the function using a loop instead of recursion
int numberOfMatches(int n) {
    // A variable that stores the number of matches played, initialized to 0
    int cnt = 0;
    // A loop that runs until n is equal to 1
    while (n > 1) {
        // Add n / 2 to the number of matches played in the current round
        cnt += n / 2;
        // Update n to the number of teams advanced to the next round
        n = (n + 1) / 2;
    }
    // Return the number of matches played
    return cnt;
}
*/

/* 
The time complexity of both solutions is O(log n), where n is the input integer. This is because we need to divide n by 2 in each round until it becomes 1, which takes O(log n) steps. 
The space complexity of the recursive solution is O(log n), where n is the input integer. This is because we need to store the recursive call stack, which takes O(log n) space. 
The space complexity of the loop solution is O(1), where 1 is a constant. This is because we only need to store the variable, which takes constant space.
 */