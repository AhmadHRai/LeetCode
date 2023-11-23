// Solution 2: Count Pattern
/* 
This is a bit more complicated, but helps avoid sorting the array. For each subarray, we determine the min and max elements. This will allow us to determine the pattern: pat = (max 
- min) / (len - 1). Then, for the arithmetic sequence, (nums[j] - min_e) / pat will be the position of that number in the sequence. So, we can go through our subarray again, and 
check that all positions are filled. We can use a boolean array to do so; if we try to fill a position that has been already filled, we can terminate - the subarray does not form 
the sequence.
 */
class Solution {
public:
    // The function that takes three vectors of integers as input and returns a vector of boolean values that indicate whether each subarray of nums from l[i] to r[i] is arithmetic or not
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        // A vector that stores the result, initialized to empty
        vector<bool> res;
        // A loop that iterates over the size of the l vector
        for (auto i = 0, j = 0; i < l.size(); ++i) {
            // A pair of pointers that point to the minimum and maximum elements in the subarray of nums from l[i] to r[i]
            auto [p_min, p_max] = minmax_element(begin(nums) + l[i], begin(nums) + r[i] + 1);
            // The length of the subarray
            int len = r[i] - l[i] + 1;
            // The common difference of the subarray if it is arithmetic, calculated by dividing the difference between the maximum and minimum elements by the length minus one
            int d = (*p_max - *p_min) / (len - 1);
            // If the maximum and minimum elements are equal, the subarray is arithmetic with zero difference
            if (*p_max == *p_min)
                // Pushing true to the result vector
                res.push_back(true);
            // Else if the difference between the maximum and minimum elements is not divisible by the length minus one, the subarray is not arithmetic
            else if ((*p_max - *p_min) % (len - 1))
                // Pushing false to the result vector
                res.push_back(false);
            // Else the subarray might be arithmetic
            else {
                // A vector of boolean values that indicate whether an element in the subarray is visited or not, initialized to false
                vector<bool> n(len);
                // A loop that iterates over the subarray elements
                for (j = l[i]; j <= r[i]; ++j) {
                    // If the difference between the current element and the minimum element is not divisible by the common difference, or the element is already visited, the subarray is not arithmetic
                    if ((nums[j] - *p_min) % d || n[(nums[j] - *p_min) / d])
                        // Breaking the loop
                        break;
                    // Marking the element as visited
                    n[(nums[j] - *p_min) / d] = true;
                }
                // Pushing the boolean value of whether the loop reached the end of the subarray or not to the result vector
                res.push_back(j > r[i]);
            }
        }
        // Returning the result vector
        return res;
    }
};
