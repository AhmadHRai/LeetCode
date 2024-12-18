/* 
Intuition:

Let's focus on a key part of the problem: for any given item, we need to find the first price that is smaller or equal to it and comes after it. 
This is similar to a classic problem known as finding the "next smaller element," which can be efficiently solved using a stack. But why does a stack work so well here?

Imagine we are processing prices from left to right. At each step, we need to determine if the current price can serve as a discount for any previous prices. 
The stack helps us keep track of those previous prices that haven't found their discount yet.

The key intuition is that when we find a price that is smaller than some earlier prices, it must be the discount for those earlier prices that are larger than it. 
We only care about the most recent of these prices because we want the first available discount.

So, for each element, our stack must contain all the most recent prices before that element that are greater than it. 
This implies that each element present in the stack must be in increasing order of value. This is called a monotonic stack.

When we encounter an element that is smaller than the top of the stack, this means a discount can be applied to the stack element. 
We continue popping prices from the stack and applying the discount until the stack is empty or the top price is less than the current price. 
Then, we push the current price to the top of the stack, to wait for a discount which may come further down. 
This way, we can both apply discounts and also maintain the monotonic property of the stack.

To implement this idea, we'll maintain a stack of indices (not prices, since we need the positions to apply discounts). 
We iterate over the prices array and check if the current price is less than or equal to the price at the top of the stack. 
If it is, the current element can be used as a discount to the elements waiting in the stack. We remove each larger price from the stack and apply the discount,
then add the current price to the stack. Any prices left on the stack at the end of the main loop had no discount available.
 */

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        // Create a copy of prices array to store discounted prices
        vector<int> result = prices;

        stack<int> stack;

        for (int i = 0; i < prices.size(); i++) {
            // Process items that can be discounted by current price
            while (!stack.empty() && prices[stack.top()] >= prices[i]) {
                // Apply discount to previous item using current price
                result[stack.top()] -= prices[i];
                stack.pop();
            }
            // Add current index to stack
            stack.push(i);
        }

        return result;
    }
};

 /* 
 Algorithm

    Initialize:
        a result array by creating a copy of the input prices array to store the discounted prices.
        an empty stack that will store indices of prices.
    For each index i of the prices array:
        Start a while loop that continues as long as:
            The stack is not empty, AND
            The price at the index stored at the stack's top is greater than or equal to the current price
            Inside the while loop, pop the top index from the stack.
            Calculate the discounted price by subtracting the current price from the price at the popped index.
            Store the result in the result array at the popped index.
        Add the current index i to the stack.
    Return the result array containing all final prices after discounts.


Complexity Analysis
Let n be the length of the input array prices.

    Time complexity: O(n)

        The algorithm iterates through the array once with a single loop. Although there is a while loop inside, each element can be pushed and popped from the stack exactly once. This means the total number of operations on the stack across all iterations is at most 2⋅n (n pushes and n pops).

    Thus, the time complexity is O(2⋅n)=O(n).

    Space complexity: O(n)

        The algorithm uses a result array of size n to store the final prices. Additionally, in the worst case scenario (when prices are in strictly increasing order), the stack could store all n indices.

    Thus, the total space complexity is linear, O(n).

*/