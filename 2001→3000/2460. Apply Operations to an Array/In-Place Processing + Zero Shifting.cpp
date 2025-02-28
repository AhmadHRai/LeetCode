class Solution {
    public:
        vector<int> applyOperations(vector<int>& nums) {
            int n = nums.size(); // Size of the input vector
            vector<int> newNums(n, 0); // Result vector
            int count = 0; // Index for the result vector
    
            // Iterate through the input vector
            for (int i = 0; i < n - 1; i++) {
                if (nums[i] != 0) {
                    if (nums[i] == nums[i + 1]) {
                        // If adjacent elements are equal, double the value and set the next element to 0
                        newNums[count] = nums[i] * 2;
                        nums[i + 1] = 0;
                        i++; // Skip the next iteration to avoid processing the zeroed element
                    } else {
                        // If adjacent elements are not equal, simply copy the current element
                        newNums[count] = nums[i];
                    }
                    count++; // Increment the index for the result vector
                }
            }
    
            // Handle the last element if it is not zero
            if (nums[n - 1] != 0) {
                newNums[count++] = nums[n - 1];
            }
    
            return newNums;
        }
    }
    /*
    Approach Summary:
        This solution applies operations to the input vector by iterating through it and checking for adjacent equal elements. If two adjacent elements are equal, it 
        doubles the value and sets the next element to zero. It then constructs a new vector with the modified elements.
    
    Complexity Analysis:
    - Time Complexity: O(N), where N is the size of the input vector, because each element is processed once.
    - Space Complexity: O(N), for storing the result vector.
    */
    