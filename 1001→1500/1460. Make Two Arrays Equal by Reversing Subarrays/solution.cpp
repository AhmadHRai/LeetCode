class Solution {
public:
    // Function to determine if two arrays can be made equal by rearranging
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> cnt1(1001); // Array to count occurrences of each value in the target array
        vector<int> cnt2(1001); // Array to count occurrences of each value in the arr array
        
        // Count occurrences of each value in the target array
        for (int& v : target) {
            ++cnt1[v]; // Increment the count for the value v
        }
        
        // Count occurrences of each value in the arr array
        for (int& v : arr) {
            ++cnt2[v]; // Increment the count for the value v
        }
        
        // Check if the two count arrays are equal
        return cnt1 == cnt2;
    }
};

/*
Approach:
- Use two arrays, `cnt1` and `cnt2`, to count the occurrences of each integer in `target` and `arr`, respectively.
- Traverse through each array and update the counts based on the value of each element.
- After populating the count arrays, compare them to check if they are equal.

Complexity Analysis:
- Time Complexity: O(n), where n is the length of the arrays. We iterate through each array once to count occurrences.
- Space Complexity: O(1), as the space used for `cnt1` and `cnt2` is fixed and independent of the input size (constant space for counting within a known range of values).
*/
