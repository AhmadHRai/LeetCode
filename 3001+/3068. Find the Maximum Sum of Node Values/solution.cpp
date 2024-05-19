class Solution {
public:
    /**
     * This function calculates the maximum possible sum of node values in a graph after performing an XOR operation
     * on the nodes' values with a given integer k. The solution uses a greedy approach to find local maxima and minima.
     * 
     * @param nums A vector of integers representing the node values.
     * @param k An integer used for the XOR operation.
     * @param edges A vector of vectors representing the edges of the graph (not used in this implementation).
     * @return The maximum possible sum of the node values after the XOR operations.
     */
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        // Initialize the sum of node values, count of positive net changes,
        // minimum positive net change, and maximum negative net change.
        long long sum = 0;
        int count = 0, positiveMinimum = (1 << 30),
            negativeMaximum = -1 * (1 << 30);

        // Iterate over each node value
        for (int nodeValue : nums) {
            int operatedNodeValue = nodeValue ^ k; // Compute the new node value after XOR with k
            sum += nodeValue; // Add the original node value to the sum
            int netChange = operatedNodeValue - nodeValue; // Calculate the net change due to the XOR operation

            // If net change is positive, update the positive minimum and increment count
            if (netChange > 0) {
                positiveMinimum = min(positiveMinimum, netChange);
                sum += netChange;
                count++;
            } else { // If net change is negative or zero, update the negative maximum
                negativeMaximum = max(negativeMaximum, netChange);
            }
        }

        // If the count of positive net changes is even, return the sum
        if (count % 2 == 0) {
            return sum;
        }

        // If the count is odd, return the maximum of either subtracting the positive minimum or adding the negative maximum
        return max(sum - positiveMinimum, sum + negativeMaximum);
    }
};

/*
Intuition

The "effective operation" allows us to pick any two nodes and perform an operation on them. If for two nodes, the netChange values are positive, picking both nodes as a pair to perform the "effective operation" will increase the node sum value. If the number of elements with positive netChange values is even, all of them can be included in the final sum to maximize it.

If the number of elements with positive netChange values is odd, we consider positiveMinimum as the minimum positive value and negativeMaximum as the maximum non-positive value in the netChange array. Both these values will occur as a pair in the netChange array.

Two cases arise:
1. If the sum of positiveMinimum and negativeMaximum is greater than zero, the node value sum will be increased by including this pair.
2. If the sum is less than or equal to zero, including this pair will decrease the node value sum or have no effect. Thus, we exclude this pair.

We don't need the netChange array from the previous approach. Calculating positiveMinimum and negativeMaximum values is enough to determine the maximum possible node value sum.

Algorithm

1. Initialize positiveMinimum and negativeMaximum with INT_MAX and INT_MIN respectively. Initialize count and sum with 0.
2. Iterate through the nums array:
   - Add the unchanged node values to sum.
   - Calculate the netChange for the current node.
   - If netChange is positive, update positiveMinimum and add netChange to sum, increment count.
   - If netChange is non-positive, update negativeMaximum.
3. If the count of positive netChange values is even, return the current sum.
4. If the count is odd, return the maximum of either subtracting positiveMinimum or adding negativeMaximum.

Complexity Analysis

Let n be the number of elements in the node value list.

Time complexity: O(n)
- A single pass linear scan on the list takes O(n) time. All other operations are performed in constant time. Thus, the net time complexity is O(n).

Space complexity: O(1)
- No additional auxiliary memory proportional to the size of the given node list is allocated. Thus, the overall space complexity is O(1).
*/
