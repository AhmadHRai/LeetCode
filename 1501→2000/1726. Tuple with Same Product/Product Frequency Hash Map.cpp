class Solution {
    public:
        int tupleSameProduct(vector<int>& nums) {
            int numsLength = nums.size();
    
            // Initialize an unordered map to store the frequency of each product of
            // pairs
            unordered_map<int, int> pairProductsFrequency;
    
            int totalNumberOfTuples = 0;
    
            // Iterate through each pair of numbers in `nums`
            for (int firstIndex = 0; firstIndex < numsLength; firstIndex++) {
                for (int secondIndex = firstIndex + 1; secondIndex < numsLength;
                     secondIndex++) {
                    // Increment the frequency of the product of the current pair
                    pairProductsFrequency[nums[firstIndex] * nums[secondIndex]]++;
                }
            }
    
            // Iterate through each product value and its frequency in the map
            for (auto [productValue, productFrequency] : pairProductsFrequency) {
                // Calculate the number of ways to choose two pairs with the same
                // product
                int pairsOfEqualProduct =
                    (productFrequency - 1) * productFrequency / 2;
    
                // Add the number of tuples for this product to the total (each pair
                // can form 8 tuples)
                totalNumberOfTuples += 8 * pairsOfEqualProduct;
            }
    
            return totalNumberOfTuples;
        }
    };

/* 
Algorithm

    Initialize
        numsLength to the length of the nums array.
        a hash map, pairProductsFrequency.
        totalNumberOfTuples to 0.
    Iterate over nums with firstIndex from 0 to numsLength - 1:
        Iterate over nums with secondindex from firstIndex + 1 to numsLength - 1:
            Increment the frequency of the product: nums[firstIndex] * nums[secondindex] by 1.
    For each element [productValue, productFrequency] of pairProductsFrequency:
        Calculate the number of pairs of products with value productValue: pairsOfEqualProduct = (productFrequency - 1) * productFrequency / 2.
        Add all possible tuples for that product value to the total: increment totalNumberOfTuples by 8 * pairsOfEqualProduct.
    Return totalNumberOfTuples.

Complexity Analysis
    Let n be the length of the nums array.

    Time complexity: O(n^2)
        We begin by calculating all pairwise products in O(n^2) time. Next, for each of these product values, we find the number of pairs of products of this value and 
        then the number of tuples that can be formed. These calculations require constant time and therefore this part of the algorithm also takes O(n^2) in the 
        worst-case (when all product values are distinct). Therefore, the total time complexity of the algorithm is O(n^2).

    Space complexity: O(n^2)
        The pairProductsFrequency can grow up to 2n×(n−1)​=O(n^2) in size (when all pair products are different) and thus the algorithm requires O(n^2) extra space.

*/