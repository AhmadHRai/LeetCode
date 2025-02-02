class Solution {
    public:
        bool check(vector<int>& nums) {
            int n = nums.size();
    
            // Construct the rotated array
            vector<int> checkSorted(n);
    
            // Iterate through all possible rotation offsets
            for (int rotationOffset = 0; rotationOffset < n; ++rotationOffset) {
                int currIndex = 0;
                for (int index = rotationOffset; index < n; ++index) {
                    checkSorted[currIndex++] = (nums[index]);
                }
                for (int index = 0; index < rotationOffset; ++index) {
                    checkSorted[currIndex++] = (nums[index]);
                }
    
                // Check if the constructed array is sorted
                bool isSorted = true;
                for (int index = 0; index < n - 1; ++index) {
                    if (checkSorted[index] > checkSorted[index + 1]) {
                        isSorted = false;
                        break;
                    }
                }
    
                // If sorted, return true
                if (isSorted) {
                    return true;
                }
            }
    
            // If no rotation makes the array sorted, return false
            return false;
        }
    };

/* 
Algorithm

    Iterate through all possible rotation offsets (rotationOffset) from 0 to n - 1:
        rotationOffset represents the number of positions the array is rotated.

    For each rotationOffset, construct a new array checkSorted:
        Append elements from index rotationOffset to n - 1 of the original array nums to checkSorted.
        Append elements from index 0 to rotationOffset - 1 of nums to checkSorted.
        Check if the constructed checkSorted array is sorted:
            Iterate through checkSorted from index 0 to n - 2:
                If any element is greater than the next element, mark the array as not sorted and break the loop.
            If the checkSorted array is sorted, return true.

    If no rotation offset results in a sorted array after checking all possible offsets, return false.

Complexity Analysis
    Let n be the size of the nums array.

    Time Complexity: O(n^2)

    The algorithm iterates through all possible rotation offsets from 0 to n−1. For each offset, it constructs the checkSorted array by iterating through the 
    entire array, which takes O(n). Additionally, it checks if the checkSorted array is sorted, which also takes O(n). As these steps are repeated for n offsets, 
    the total time complexity is O(n⋅n)=O(n^2).

    Space Complexity: O(n)

    The algorithm uses an additional array checkSorted to store the elements of the rotated array for each offset. The size of checkSorted is equal to the size of 
    the input array nums, requiring O(n) space. No other significant data structures are used, so the overall space complexity is O(n).
*/