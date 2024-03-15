class Solution {
public:
    // Function to count subarrays with sum less than or equal to the goal
    int atMost(vector<int>& nums, int goal) {
        int window_start=0, window_end=0, ans=0, count=0; // Initialize variables
        if (goal < 0) return 0; // If goal is negative, return 0 as no subarray can have a negative sum
        for(window_end=0; window_end<nums.size(); window_end++) { // Iterate through the array
            count += nums[window_end]; // Add current element to the sum
            while(count > goal) { // If sum exceeds the goal
                count -= nums[window_start]; // Subtract the first element of the window from the sum
                window_start++; // Move the window start to the right
            }
            ans += window_end - window_start + 1; // Add the number of subarrays ending at the current window end
        }
        return ans; // Return the total count of subarrays
    }

    // Function to count subarrays with sum equal to the goal
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1); // Subtract the count of subarrays with sum less than the goal from the count of subarrays with sum less than or equal to the goal
    }
};

/* 
Approach
    atMost Function: This function calculates the number of subarrays with a sum less than or equal to the given goal. It uses a sliding window approach where the window expands by 
    adding elements to the right and contracts by removing elements from the left when the sum exceeds the goal.
    
    numSubarraysWithSum Function: This function calculates the number of subarrays with a sum equal to the goal by subtracting the number of subarrays with a sum less than the goal 
    from the number of subarrays with a sum less than or equal to the goal.

 Complexity Analysis
    Time Complexity: The time complexity of this solution is O(n), where n is the size of the input array. This is because each element in the array is processed once by the sliding 
    window mechanism.
    
    Space Complexity: The space complexity is O(1), as the solution uses a constant amount of space to store variables and does not depend on the size of the input array.
 */