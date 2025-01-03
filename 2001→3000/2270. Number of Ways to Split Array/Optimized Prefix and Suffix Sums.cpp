class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        // Keep track of sum of elements on left and right sides
        long long leftSum = 0, rightSum = 0;

        // Initially all elements are on right side
        for (int num : nums) {
            rightSum += num;
        }

        int count = 0;
        // Try each possible split position
        for (int i = 0; i < nums.size() - 1; i++) {
            // Move current element from right to left side
            leftSum += nums[i];
            rightSum -= nums[i];

            // Check if this creates a valid split
            if (leftSum >= rightSum) {
                count++;
            }
        }

        return count;
    }
};

/* 
Intuition

we can directly track the sums on the left and right sides of the split as we iterate through the array.

To do this, we maintain two variables:

    leftSum: This keeps track of the sum of elements to the left of the current split position. At the beginning, since no elements are to the left, this is initialized to 0.

    rightSum: This keeps track of the sum of elements to the right of the current split position. At the start, this is the total sum of the array, as all elements are initially on the right.

Now, each time we consider a new split position, the current element moves from the right side to the left side. So we update leftSum and add the current element to it. And to update rightSum, we subtract the current element from it.

After updating these variables, we compare leftSum and rightSum. If leftSum is greater than or equal to rightSum, the split is valid, and we increment a counter. And we repeat this until we exhaust the entire array.

Algorithm

    Initialize two variables leftSum and rightSum to 0 to track the sum of elements on the left and right sides of each split.
    Calculate the initial rightSum by iterating through the input array and adding all elements to it, as initially, all elements are on the right side.
    Initialize a variable count to 0 to track the number of valid splits.
    Iterate from index 0 to the length of nums minus 2:
        Add the current element to leftSum as it moves to the left side.
        Subtract the current element from rightSum as it leaves the right side.
        If leftSum is greater than or equal to rightSum, increment count.
    Return the final value of count as the result.

Complexity Analysis

Let n be the length of the input array nums.

    Time complexity: O(n)

    The algorithm has two main loops. The first loop calculates the initial rightSum by iterating through all elements once in O(n) time. The second loop checks each possible split position, also taking O(n) time. Since these operations are sequential, the total time complexity is O(n).

    Space complexity: O(1)

    The algorithm only uses two variables (leftSum and rightSum) regardless of the input size. No additional data structures that scale with input are used. Therefore, the space complexity is constant, O(1).
 */