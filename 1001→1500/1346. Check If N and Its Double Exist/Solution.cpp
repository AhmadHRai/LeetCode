class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        // Create an unordered set to store unique integers from the array
        unordered_set<int> intSet;

        for (int i = 0; i < arr.size(); i++) {
            // Check if double the current element exists in the set, N -> N*2
            // or if the current element is even, check if half of it exists in the set N -> N/2
            if (intSet.find(arr[i] * 2) != intSet.end() || 
                (arr[i] % 2 == 0 && intSet.find(arr[i] / 2) != intSet.end())) {
                // If either condition is true, return true
                return true;
            }
            // Insert the current element into the set for future lookups
            intSet.insert(arr[i]);
        }
        // If no valid pairs are found, return false
        return false;
    }
};

/*
Approach:
1. Use an unordered set to keep track of elements encountered in the array.
2. Iterate through each element of the input vector `arr`.
3. For each element, check if either double or half of that element exists in the set.
4. If a valid pair is found, return true immediately.
5. If no pairs are found after checking all elements, return false.

Complexity Analysis:
- Time Complexity: O(n), where n is the number of elements in `arr`. Each insertion and lookup operation in an unordered set takes average O(1) time.
- Space Complexity: O(n) in the worst case, as we may need to store all n elements in the unordered set if no valid pairs are found.
*/
