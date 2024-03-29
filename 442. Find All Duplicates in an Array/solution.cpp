class Solution {  
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        // Initialize an empty vector to store the duplicate numbers
        vector<int> ans;
        int n = nums.size();
        
        // Iterate through each number in the input array
        for(int i = 0; i < n; i++) {
            // Convert the current number to its absolute value to use it as an index
            int temp = (nums[i] < 0) ? -1 * nums[i] : nums[i];
            
            // Check if the number at the index (temp-1) is negative
            // If it is, it means the number has already been marked as a duplicate
            if(nums[temp-1] < 0) {
                // If the number is already marked as a duplicate, add it to the result vector
                ans.push_back(temp);
            } else {
                // If the number is not marked as a duplicate, mark it by negating its value
                nums[temp-1] *= -1;
            }
        }
        
        // Return the vector containing all the duplicate numbers
        return ans;
    }
};

/* 
Approach Summary:
    This solution uses the sign of the numbers in the array to mark duplicates. It iterates through the array, converting each number to its absolute value and using it as an index 
    to mark duplicates. If a number is already marked as a duplicate (its value is negative), it is added to the result vector. Otherwise, the number is marked as a duplicate by 
    negating its value.

Complexity Analysis:
    Time Complexity: O(n), where n is the number of elements in the array. This is because each element is visited once.
    Space Complexity: O(n), as the solution uses an additional vector to store the duplicate numbers.
 */
