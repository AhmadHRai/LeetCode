class Solution {
    public:
        int tupleSameProduct(vector<int>& nums) {
            int numsLength = nums.size();
    
            vector<int> pairProducts;
    
            int totalNumberOfTuples = 0;
    
            // Iterate over nums to calculate all pairwise products
            for (int firstIndex = 0; firstIndex < numsLength; firstIndex++) {
                for (int secondIndex = firstIndex + 1; secondIndex < numsLength;
                     secondIndex++) {
                    pairProducts.push_back(nums[firstIndex] * nums[secondIndex]);
                }
            }
    
            sort(pairProducts.begin(), pairProducts.end());
    
            int lastProductSeen = -1;
            int sameProductCount = 0;
    
            // Iterate over pairProducts to count how many times each product occurs
            for (int productIndex = 0; productIndex < pairProducts.size();
                 productIndex++) {
                if (pairProducts[productIndex] == lastProductSeen) {
                    // Increment the count of same products
                    sameProductCount++;
                } else {
                    // Calculate how many pairs had the previous product value
                    int pairsOfEqualProduct =
                        (sameProductCount - 1) * sameProductCount / 2;
    
                    totalNumberOfTuples += 8 * pairsOfEqualProduct;
    
                    // Update lastProductSeen and reset sameProductCount
                    lastProductSeen = pairProducts[productIndex];
                    sameProductCount = 1;
                }
            }
    
            // Handle the last group of products (since the loop ends without adding
            // it)
            int pairsOfEqualProduct = (sameProductCount - 1) * sameProductCount / 2;
            totalNumberOfTuples += 8 * pairsOfEqualProduct;
    
            return totalNumberOfTuples;
        }
    };

/* 
Algorithm

    Initialize
        numsLength to the length of the nums array.
        an array, pairProducts, to store the pairwise products of the elements.
        totalNumberOfTuples to 0.
    Iterate over nums with firstIndex from 0 to numsLength - 1:
        Iterate over nums with secondindex from firstIndex + 1 to numsLength - 1:
            Add the product nums[firstIndex] * nums[secondindex] to the pairProducts list.
    Sort pairProducts in increasing order.
    Initialize lastProductSeen to -1 and sameProductCount to 0.
    Iterate over pairProducts with productIndex from 0 to pairProducts.size - 1:
        If the current product is equal to the last seen:
            Increment sameProductCount by 1.
        Otherwise:
            Calculate the number of pairs of products with value lastProductSeen: pairsOfEqualProduct = (sameProductCount - 1) * sameProductCount / 2.
            Add all possible tuples for that product value to the total: increment totalNumberOfTuples by 8 * pairsOfEqualProduct.
            Set lastProductSeen to the pairProducts[productIndex] and sameProductCount to 1.
    Handle the last group of products:
        Calculate the number of pairs of products with value lastProductSeen: pairsOfEqualProduct = (sameProductCount - 1) * sameProductCount / 2.
        Add all possible tuples for that product value to the total: increment totalNumberOfTuples by 8 * pairsOfEqualProduct.
    Return totalNumberOfTuples.

Complexity Analysis
    Let n be the length of the nums array.

    Time complexity: O(n^2 log n)

        We iterate over the array with a nested loop to calculate all pairwise products, which takes O(n^2). Sorting the pairProducts array requires O(n^2logn^2) (2n^2logn)=O
        (n^2logn) time, as the length of the array is O(n^2). Then, we perform a final pass over the pairProducts array to count the frequency of each product and update 
        the total number of tuples. Each iteration only involves constant-time operations, and therefore this step costs O(n^2) time. Overall, the time complexity of the 
        algorithm is O(n^2+n^2logn+n^2)=O(n^2logn).

    Space complexity: O(n^2)
        
        The pairProducts array contains the products of all pairs of elements in nums. Since there exist 2n×(n−1)​=O(n^2) pairs of n elements, the pairProducts array 
        requires O(n^2) space.

*/