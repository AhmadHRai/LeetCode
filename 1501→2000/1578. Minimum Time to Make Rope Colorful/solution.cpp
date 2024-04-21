class Solution {
public:
    // This function returns the minimum time needed to remove some balloons from a rope
    // The rope has n balloons with different colors
    // The time needed to remove the i-th balloon is neededTime[i]
    // The rope should have no more than two consecutive balloons with the same color
    int minCost(string colors, vector<int>& neededTime) {
        int result = 0; // initialize the result to zero
        int max_cost = 0; // initialize the maximum time of the previous color to zero
        int n = colors.size(); // get the number of balloons

        for (int i=0; i < n; i++) // loop through the balloons
        {
            if (i > 0 && colors[i] != colors[i-1]) // if the current color is different from the previous color
                max_cost = 0; // reset the maximum time to zero
            result += min(max_cost, neededTime[i]); // add the minimum of the maximum time and the current time to the result
            max_cost = max(max_cost, neededTime[i]); // update the maximum time to be the maximum of the previous and current time
        }

        return result; // return the final result
    }
};

/* 
Approach:
    The approach is to use a greedy algorithm to find the minimum time needed to remove some balloons from the rope. The idea is to maintain a 
    variable max_cost that stores the maximum time of the previous color, and update it by comparing it with the current time. The result is 
    updated by adding the minimum of the max_cost and the current time. The algorithm ensures that no more than two consecutive balloons have 
    the same color by resetting the max_cost to zero when the color changes.

Complexity:
    The time complexity is O(n) as we only traverse the array once. 
    The space complexity is O(1) as we only use constant extra space. 
*/