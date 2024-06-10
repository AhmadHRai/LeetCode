/**
 * Solution class for counting the number of students who need to move to
 * match their heights with the sorted order.
 */
class Solution {
public:
    /**
     * Counts the number of students whose heights are not in the correct order
     * relative to a sorted version of the heights array.
     *
     * @param heights A vector of integers representing the heights of students.
     * @return The number of students who need to move to match the sorted heights.
     */
    int heightChecker(vector<int>& heights) {
        vector<int> expected = heights;  // Create a copy of heights to store sorted heights
        sort(expected.begin(), expected.end());  // Sort the expected heights
        
        int cnt = 0;  // Initialize count of mismatches
        
        // Compare heights with sorted expected heights
        for(int i = 0; i < heights.size(); i++) {
            if (heights[i] != expected[i]) {
                cnt++;  // Increment count if height doesn't match the expected order
            }
        }
        
        return cnt;  // Return the count of mismatches
    }
};

/*
Approach:
    1. Create a Copy and Sort:
        - Create a copy of the input vector `heights` named `expected`.
        - Sort the `expected` vector to get the heights in ascending order.
    2. Count Mismatches:
        - Initialize a counter `cnt` to keep track of mismatches.
        - Iterate through the `heights` vector and compare each height with the corresponding height in `expected`.
        - Increment `cnt` whenever a height doesn't match its expected position.
    3. Return Result:
        - Return the final count `cnt`, which represents the number of students who need to move their positions to match the sorted heights.

Complexity Analysis:
    - Time Complexity: O(n log n)
      where n is the number of elements in the input vector `heights`. Sorting the `expected` vector takes O(n log n) time, and iterating through `heights` takes O(n) time.
    - Space Complexity: O(n)
      Additional space is used to store the sorted `expected` vector of size n.

*/

