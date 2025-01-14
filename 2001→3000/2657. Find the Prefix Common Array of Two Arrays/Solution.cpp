class Solution {
public:
    // Function to find the prefix common array between two arrays A and B
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size(); // Get the size of the input arrays
        vector<int> prefixCommonArray(n); // Array to store counts of common elements for each prefix
        vector<int> frequency(n + 1, 0); // Frequency array to count occurrences of elements (1-indexed)
        int commonCount = 0; // Counter for common elements in the current prefix

        // Iterate through the elements of both arrays
        for (int currentIndex = 0; currentIndex < n; ++currentIndex) {
            // Increment frequency of the current element in A
            // Check if the element in A has appeared before (common in prefix)
            if (++frequency[A[currentIndex]] == 2) ++commonCount;

            // Increment frequency of the current element in B
            // Check if the element in B has appeared before (common in prefix)
            if (++frequency[B[currentIndex]] == 2) ++commonCount;

            // Store the count of common elements for the current prefix
            prefixCommonArray[currentIndex] = commonCount;
        }

        // Return the final array with counts of common elements in each prefix
        return prefixCommonArray; 
    }
};

/*
Approach Summary:
The function calculates an array that represents the number of common elements in the prefixes of two input arrays, A and B. It uses a frequency array to keep track of how many times each element has been seen. For each index, it checks if an element from either array has been seen twice (indicating it is common in both prefixes) and updates a counter. The result is stored in `prefixCommonArray`, which is returned at the end.

Complexity Analysis:
- Time Complexity: O(n), where n is the length of the input arrays. The function iterates through both arrays once.
- Space Complexity: O(n), where n is used for the frequency array, which has a size based on the maximum possible value of elements in A and B.
*/
