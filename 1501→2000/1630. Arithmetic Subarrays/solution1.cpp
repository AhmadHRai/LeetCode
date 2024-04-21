// Solution 1: Sort
// The approach of this solution is to copy numbers into an aux array, sort that array, and then check if it forms a sequence.
// The class definition for the solution
class Solution {
public:
    // The function that takes three vectors of integers as input and returns a vector of boolean values that indicate whether each subarray of nums from l[i] to r[i] is arithmetic or not
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        // A vector that stores the result, initialized to empty
        vector<bool> res;
        // A loop that iterates over the size of the l vector
        for (auto i = 0, j = 0; i < l.size(); ++i) {
            // A vector that stores the subarray of nums from l[i] to r[i]
            vector<int> n(begin(nums) + l[i], begin(nums) + r[i] + 1);
            // Sorting the subarray in ascending order
            sort(begin(n), end(n));
            // A loop that iterates over the subarray elements from the third one
            for (j = 2; j < n.size(); ++j)
                // Checking if the difference between the current element and the previous one is equal to the difference between the second and the first element
                if (n[j] - n[j - 1] != n[1] - n[0])
                    // If not, breaking the loop
                    break;
            // Pushing the boolean value of whether the loop reached the end of the subarray or not to the result vector
            res.push_back(j == n.size());
        }
        // Returning the result vector
        return res;
    }
};

/* 
Complexity Analysis
    Time: O(m * n * log n), O(m * n log n), where m is the size of the l vector and n is the maximum length of any subarray. This is because we need to sort each subarray, which 
    takes O(n log n) time, and iterate over each subarray element, which takes O(n) time.
    Space: O(m + n), where m is the size of the l vector and n is the maximum length of any subarray. This is because we need to store the result vector, which takes O(m) space, 
    and the subarray vector, which takes O(n) space.
*/