class Solution {
    public:
        int tupleSameProduct(vector<int>& nums) {
            int numsLength = nums.size();
            sort(nums.begin(), nums.end());
    
            int totalNumberOfTuples = 0;
    
            // Iterate over all possible values for 'a'
            for (int aIndex = 0; aIndex < numsLength; aIndex++) {
                // Iterate over all possible values for 'b', starting from the end
                // of the array
                for (int bIndex = numsLength - 1; bIndex >= aIndex + 1; bIndex--) {
                    int product = nums[aIndex] * nums[bIndex];
    
                    // Use a hash set to store possible values of 'd'
                    unordered_set<int> possibleDValues;
    
                    // Iterate over all possible values for 'c' between 'a' and 'b'
                    for (int cIndex = aIndex + 1; cIndex < bIndex; cIndex++) {
                        // Check if the product is divisible by nums[cIndex]
                        if (product % nums[cIndex] == 0) {
                            int dValue = product / nums[cIndex];
    
                            // If 'dValue' is in the set, increment the tuple count
                            // by 8
                            if (possibleDValues.find(dValue) !=
                                possibleDValues.end()) {
                                totalNumberOfTuples += 8;
                            }
    
                            // Add nums[cIndex] to the set for future checks
                            possibleDValues.insert(nums[cIndex]);
                        }
                    }
                }
            }
    
            return totalNumberOfTuples;
        }
    };

/* 
Algorithm

    Initialize numsLength to the length of the nums array.
    Sort the array in increasing order.
    Initialize totalNumberOfTuples to 0.
    Iterate over nums to try out all possible values of a with aIndex from 0 to numsLength - 1.
        Iterate over the rest values of nums to try all possible values for b with bIndex from numsLength - 1 to aIndex + 1.
            Define product as nums[aIndex] * nums[bIndex].
            Initialize a hash map possibleDValues.
                Iterate over nums with cIndex from aIndex + 1 to bIndex - 1:
                    If the condition can be satisfied for some integer value of d, i.e. if product % nums[cIndex] == 0:
                        Define the desired value of d as dValue = product / nums[cIndex].
                        If dValue is in possibleDValues then add 8 (all possible tuples) to totalNumberOfTuples.
                        Add nums[cindex] to the possibleDValues.
    Return totalNumberOfTuples.

Complexity Analysis
    Let n be the length of the nums array.

    Time complexity: O(n^3)

        First, we sort the array in O(nlogn) time. Next, we use 3 nested loops to fix the values of a, b, and c, and for each combination, we check whether the required 
        value of d exists in the array. Using a hash set allows us to perform both insertion and lookup operations in constant time on average. Thus, the operations 
        within the innermost loop take constant time. As a result, the overall time complexity of the algorithm is O(n^3).

    Space complexity: O(n)

        We create a hash set to store the possible values variable d can take. This hash set can grow up to O(n) in size, so the algorithm requires O(n) extra space.

*/