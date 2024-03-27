class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size() - 1, cnt;
        
        // Perform binary search
        while(low <= high) {
            int mid = low + (high - low) / 2;
            cnt = 0;
            // Count elements less than or equal to mid
            for(int n : nums) {
                if(n <= mid) ++cnt;
            }
            // Adjust search range based on count
            if(cnt <= mid) low = mid + 1;
            else high = mid - 1;
        }
        // Return the duplicate number
        return low;
    }
};

/* 
Approach Summary:
    This solution uses a binary search approach to find the duplicate number. It counts the number of elements in the array that are less than or equal to the midpoint of the current search range. Based on this count, it adjusts the search range to narrow down the location of the duplicate number.

Complexity Analysis:
    Time Complexity: O(n log n), where n is the number of elements in the array. This is because the binary search is performed log n times, and for each iteration, it counts the elements in the array, which takes O(n) time.
    Space Complexity: O(1), as the solution uses a constant amount of space to store the pointers and does not depend on the size of the input array.
 */
