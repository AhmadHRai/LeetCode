/* 
Intuition

Since the constraints are small, we can solve this problem using a brute-force approach. For each item in the prices array, we need to find a price that is smaller or equal to it and appears later in the array. This price will be our discount amount. We then subtract this discount from the original price to get the final discounted price.

To implement this, let's start by creating a copy of the prices array called result. We'll loop through the prices array and apply the discount we find for each element to the corresponding element in the result array.

For each element in the prices array, we'll run another loop starting from the next element to the right. If we find a price that is less than or equal to the current element, we'll subtract this price from the original price in the result array and stop looking further. If we don't find any suitable discount after checking all subsequent prices, the item's price in the result array will remain unchanged.

After processing all the prices in this manner, the result array will contain the final discounted prices for each item. We can then return this array as our answer.
Algorithm

    Initialize a variable n to store the length of the input prices array.
    Initialize a result array by creating a copy of the input prices array. This ensures we have a copy of the original prices to work with.
    Start an outer loop that iterates from 0 to n - 1, with loop variable i:
        Start an inner loop that iterates from index i + 1 to n - 1, with loop variable j.
            If prices[j] is less than or equal to prices[i]:
                Calculate the discounted price by subtracting prices[j] from prices[i].
                Store the calculated discounted price in result[i].
                Break the inner loop as we have found the first valid discount.
    Return the result array containing all final prices after discounts.

 */

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        // Create a copy of original prices array to store discounted prices
        vector<int> answer  = prices;

        for(int i = 0; i < prices.size(); i++) {
            // Look for first smaller or equal price that comes after current item
            for(int j = i + 1; j < prices.size(); j++) {
                if( prices[j] <= prices[i] ) {
                    // Apply discount by subtracting prices[j] from current price
                    answer[i] = prices[i] - prices[j];
                    break;
                }
            }
        }
        return answer;
    }
};

/* 
Complexity Analysis

Let n be the length of the input array prices.

    Time complexity: O(n^2)

        The algorithm uses two nested loops. The outer loop iterates through each element of the array, and for each element, the inner loop can potentially
        iterate through all remaining elements. In the worst case, where prices are in strictly increasing order, for each element i, we need to check all 
        elements from i + 1 to n - 1. Thus, the time complexity is quadratic, O(n^2).

    Space complexity: O(n)

    The algorithm creates a new array result of the same size as the input array to store the final prices. Besides this, only a constant amount of extra 
    space is used for loop variables and temporary calculations.
    Therefore, the space complexity is O(n).
 */