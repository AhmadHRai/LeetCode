class Solution {
public:
    using int2 = array<int, 2>;  // Define a type alias for an array of two integers.

    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        int freq[201] = {0};  // Array to store frequency of numbers ranging from -100 to 100.

        // Count the frequency of each number.
        for (int x : nums) {
            freq[x + 100]++;
        }

        // Sort the numbers based on frequency and value.
        sort(nums.begin(), nums.end(), [&](int x, int y) {
            // Compare by frequency; if frequencies are the same, compare by value.
            return (freq[x + 100] == freq[y + 100]) ? x > y : freq[x + 100] < freq[y + 100];
        });

        return nums;
    }
};

/*
Approach

    1. **Frequency Counting**: Use an array `freq` to count the occurrences of each integer. The array size is 201 to accommodate indices for numbers from -100 to 100.
    2. **Sorting**: Sort the `nums` vector using a custom comparator:
       - Primary key: Frequency (ascending order).
       - Secondary key: Value (descending order) if frequencies are the same.
    3. **Return**: Return the sorted vector.

Complexity

    Time complexity: O(n log n), where n is the number of elements in the `nums` vector. The sorting operation is the most time-consuming part.

    Space complexity: O(n), due to the extra space used for storing frequencies and the result vector.

This approach efficiently sorts the vector based on frequency and value by leveraging sorting with a custom comparator.
*/
