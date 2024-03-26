class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Initialize slow and fast pointers to the first element
        int slow = nums[0];
        int fast = nums[0];
        
        // Move slow and fast pointers until they meet
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);
        
        // Reset fast pointer to the start and move both pointers one step at a time
        fast = nums[0];
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        // Return the duplicate number
        return slow;
    }
};

/* 
Approach Summary:
    This solution employs Floyd's Tortoise and Hare algorithm to detect the duplicate number. It uses two pointers moving at different speeds to find the meeting point, which indicates a cycle. After finding the cycle, it resets the fast pointer and moves both pointers at the same speed to find the duplicate number.

Complexity Analysis:
    Time Complexity: O(n), where n is the number of elements in the array. This is because each element is visited at most twice.
    Space Complexity: O(1), as the solution uses a constant amount of space to store the pointers and does not depend on the size of the input array.
 */
