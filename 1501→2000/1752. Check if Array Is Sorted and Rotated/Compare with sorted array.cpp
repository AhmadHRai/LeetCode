class Solution {
    public:
        bool check(vector<int>& nums) {
            int size = nums.size();
    
            // Create a sorted copy of the array
            vector<int> sortedNums = nums;
            sort(sortedNums.begin(), sortedNums.end());
    
            // Compare the original array with the sorted array, considering all
            // possible rotations
            for (int rotationOffset = 0; rotationOffset < size; ++rotationOffset) {
                bool isMatch = true;
                for (int index = 0; index < size; ++index) {
                    if (nums[(rotationOffset + index) % size] !=
                        sortedNums[index]) {
                        isMatch = false;
                        break;
                    }
                }
                if (isMatch) {
                    return true;
                }
            }
    
            return false;
        }
    };

/* 
Algorithm

    Iterate through all possible rotation offsets (rotationOffset) from 0 to n-1:
        rotationOffset represents the number of positions the array is rotated.

    For each rotationOffset, compare the original array with a sorted version of itself:
        Create a sorted copy of the original array sortedNums.
        Iterate through the elements of nums starting from rotationOffset and wrapping around cyclically using modulo operation:
            Compare each element with the corresponding element in sortedNums.
        Check if all elements at each rotationOffset match the sorted array.
        If the constructed array matches the sorted array at a specific rotationOffset, return true.

    If no rotation offset results in a sorted array after checking all possible offsets, return false.

Complexity Analysis

Let n be the size of the nums array.

    Time Complexity: O(n^2)

        The algorithm creates a sorted version of the array, which takes O(nlogn) time. After sorting, it checks all possible rotations by iterating through the 
        array and comparing elements for each rotation, which takes O(n) for each rotation. Hence, the overall time complexity is O(nlogn)+O(n^2)=O(n^2).

    Space Complexity: O(n)

        The algorithm uses an additional array sortedNums to store the sorted version of the input array, which requires O(n) space. No other significant data 
        structures are used, so the overall space complexity is O(n).
*/