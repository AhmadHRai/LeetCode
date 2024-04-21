// The class definition for the solution
class Solution {
public:
    // A constant value that represents the modulo operation
    const int MOD = (int)1e9 + 7;
    // A two-dimensional array that stores the intermediate results of the subproblems
    long long dp[100001][3];
    // A recursive function that takes a reference to a string and two integers as input and returns the number of ways to arrange the plants and seats in the corridor from the current position to the end
    long long getAns(string & a, int i, int k) {
        // If the current position is equal to or greater than the length of the string, return 1 if the current number of seats is 2, otherwise return 0
        if(i >= a.size()) {
            return k == 2;
        }
        
        // If the subproblem is already solved, return the stored result
        if(dp[i][k] != -1)return dp[i][k];
        
		//if total number of seats in current segment is 2
        // If the current number of seats is 2, check the current character in the string
        if(k == 2) {
            // If the current character is 'P', meaning a plant, there are two choices: either to add a divider before the current plant or not
            if(a[i] == 'P') {
				//choice either to add divider before current plant or not.
                // Return the sum of the number of ways to arrange the rest of the corridor with a divider before the current plant (resetting the number of seats to 0) and the number of ways to arrange the rest of the corridor without a divider before the current plant (keeping the number of seats as 2), modulo the constant value
                return dp[i][k] = (getAns(a, i + 1, 0) % MOD + getAns(a, i + 1, k) % MOD) % MOD;
            }
            else {
				//necessary to put a divider before current seat, as current count of seat is 2
                // If the current character is 'S', meaning a seat, it is necessary to put a divider before the current seat, as the current number of seats is 2
                // Return the number of ways to arrange the rest of the corridor with a divider before the current seat (resetting the number of seats to 1), modulo the constant value
                return dp[i][k] = getAns(a, i + 1, 1) % MOD;
            }
        }
        else {
			//current seat is less than 2 so, move ahead
            // If the current number of seats is less than 2, move ahead to the next character in the string
            // Return the number of ways to arrange the rest of the corridor, incrementing the number of seats by 1 if the current character is 'S', modulo the constant value
            return dp[i][k] = getAns(a, i + 1, k + (a[i] == 'S')) % MOD;
        }
        
        
    }
    // The main function that takes a string as input and returns the number of ways to arrange the plants and seats in the corridor
    int numberOfWays(string corridor) {
        // Initializing the array with -1 values, indicating that the subproblems are not solved yet
        memset(dp, -1, sizeof(dp));
        // Calling the recursive function with the input string, the starting position 0, and the initial number of seats 0
        return getAns(corridor, 0, 0); 
    }
};

/* 
Approach:

The approach is based on the idea of using a dynamic programming technique to solve the problem of arranging the plants and seats in the corridor. We use a two-dimensional array to 
store the intermediate results of the subproblems, where the first dimension represents the current position in the string and the second dimension represents the current number of 
seats in the segment. We define a segment as a part of the corridor that is separated by dividers. We use a recursive function to find the number of ways to arrange the plants and 
seats in the corridor from the current position to the end, given the current number of seats. The base case of the recursion is when the current position is equal to or greater 
than the length of the string, in which case we return 1 if the current number of seats is 2, otherwise we return 0. The recursive case is when the current position is less than 
the length of the string, in which case we check the current character in the string. If the current character is ‘P’, meaning a plant, we have two choices: either to add a divider 
before the current plant or not. If we add a divider, we reset the number of seats to 0 and move to the next position. If we do not add a divider, we keep the number of seats as it 
is and move to the next position. We add the number of ways for both choices and modulo the constant value. If the current character is ‘S’, meaning a seat, we check the current 
number of seats. If the current number of seats is 2, we have to add a divider before the current seat, as the maximum number of seats in a segment is 2. We reset the number of 
seats to 1 and move to the next position. If the current number of seats is less than 2, we do not have to add a divider before the current seat. We increment the number of seats 
by 1 and move to the next position. We return the number of ways for the current choice and modulo the constant value. We memoize the results of the subproblems in the array and 
return the final result.
 
 */

 /* 
 The time complexity of this solution is O(N), where N is the length of the input string. This is because we need to visit each character in the string once and perform constant 
 time operations on each character. 
 The space complexity is O(N), where N is the length of the input string. This is because we need to store the array of size N * 3, which takes O(N) space.
  */