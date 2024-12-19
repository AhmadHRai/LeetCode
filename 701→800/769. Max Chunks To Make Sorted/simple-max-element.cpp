// Maximum Element
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maximum = 0;
        int result = 0;

        for (int i = 0; i < arr.size(); i++) {
            maximum = max(maximum,arr[i]);
            // All values in range [0, i] belong to the prefix arr[0:i];
            // a new partition can be formed
            if (maximum == i) result+=1;
        }

        return result;
    }
};

/*
Approach:
    - The approach is based on the observation that, at any point in the array, the maximum element seen so far must be equal to the current index in order for the subarray [0, i] to be sortable independently.
    - By tracking the maximum element encountered up to each index and comparing it to the current index, we can determine if the current subarray can be sorted as a chunk.
    - This simple "max element" approach is the fastest as it only requires a single pass through the array and uses a few variables to track the result.
    
    Complexity Analysis:
    - Time complexity: O(n)
      We iterate over the array arr once and perform constant-time operations on each iteration.

    - Space complexity: O(1)
      We are only using a fixed number of variables which does not depend on the input size.
*/
