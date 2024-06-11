/**
 * Solution class for sorting an array `arr1` relative to the order defined by `arr2`.
 */
class Solution {
public:
    /**
     * Sorts the array `arr1` relative to the order defined by `arr2`.
     *
     * @param arr1 A vector of integers to be sorted relative to `arr2`.
     * @param arr2 A vector of integers defining the relative order for sorting `arr1`.
     * @return A sorted vector `arr1` relative to `arr2`.
     */
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // Step 1: Count frequencies of each element in arr1
        vector<int> count(1001);  // Since constraints specify arr1[i] <= 1000
        for (int num : arr1) {
            count[num]++;
        }
        
        // Step 2: Create sorted array relative to arr2
        vector<int> ans;
        for (int num : arr2) {
            while (count[num]-- > 0) {
                ans.push_back(num);
            }
        }
        
        // Step 3: Handle elements not present in arr2 (sorting remaining elements)
        for (int i = 0; i < count.size(); i++) {
            while (count[i]-- > 0) {
                ans.push_back(i);
            }
        }
        
        return ans;  // Return the sorted array relative to arr2
    }
};

/*
Approach:
    1. Counting Frequencies:
        - Initialize a vector `count` of size 1001 to count occurrences of each element in `arr1`.
        - Iterate through `arr1` and increment the count for each element.
    2. Sorting Relative to arr2:
        - Initialize an empty vector `ans` to store the sorted array.
        - Iterate through each element in `arr2`. For each element, append it to `ans` as many times as it appears in `arr1` (using `count`).
    3. Sorting Remaining Elements:
        - Iterate through `count` to handle elements not present in `arr2`. Append each element to `ans` based on its count.
    4. Return Result:
        - Return the sorted vector `ans`, which represents `arr1` sorted relative to the order defined by `arr2`.

Complexity Analysis:
    - Time Complexity: O(n + m)
      where n is the number of elements in `arr1` and m is the number of elements in `arr2`. Counting frequencies takes O(n), and sorting relative to `arr2` and sorting remaining elements each take O(1001), which is constant time.
    - Space Complexity: O(1)
      Additional space is used for the `count` vector of fixed size 1001, and `ans` vector, which is dependent on input size.

*/

