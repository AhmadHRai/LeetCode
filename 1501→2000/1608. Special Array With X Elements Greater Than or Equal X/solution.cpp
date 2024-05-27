class Solution {
public:
    /**
     * @brief Finds the special array in the given vector of integers.
     * 
     * A special array is defined as an array where the number of elements greater than or equal to a certain integer
     * is equal to that integer.
     * 
     * @param nums The input vector of integers.
     * @return int The size of the special array, or -1 if no such array exists.
     */
    int specialArray(vector<int>& nums) {
        int count[102] = { 0 }; // Initialize an array to store the count of numbers
        int N = nums.size(); // Get the size of the input vector
        // Count the occurrences of each number and store in the count array
        for (int n : nums) 
            count[min(n, N)]++;
        // Iterate from the maximum possible size of the special array to 0
        for (int i = N; i >= 0; i--) {
            count[i] = count[i + 1] + count[i]; // Update count[i] to store cumulative count
            // If the count of elements equal to i equals i, return i
            if (count[i] == i) return i;
        }
        // If no special array is found, return -1
        return -1;
    }
};

/*
Approach:

The solution counts the occurrences of each number in the input vector and stores them in an array. It then iterates from the maximum possible size of the special array down 
to 0. For each size, it calculates the cumulative count of elements greater than or equal to that size. If the count equals the size, it returns that size as it represents a 
special array. If no special array is found, it returns -1.

Complexity Analysis:

    Time Complexity: O(n), where n is the size of the input vector. The solution iterates through the input vector once to count the occurrences of each number and then 
        iterates again to find the special array.
    Space Complexity: O(1). The solution uses a constant amount of extra space for the count array, which has a fixed size of 102 elements.
*/