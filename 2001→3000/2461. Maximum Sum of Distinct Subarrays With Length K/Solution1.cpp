class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0, sum = 0;  // Initialize answer and sum variables
        unordered_map<int, int> map;  // Create a map to store element counts
        int i = 0;  // Initialize index i to 0

        while (i < k && i < nums.size()) {  // Loop to process the first k elements (or the size of nums if smaller than k)
            map[nums[i]]++;  // Increment the count of the current element in the map
            sum += nums[i];  // Add the current element to the sum
            i++;  // Move to the next element
        }

        if (map.size() == k)  // If the map contains exactly k distinct elements
            ans = sum;  // Store the sum as the result if all are distinct

        while (i < nums.size()) {  // Loop through the remaining elements of the array
            map[nums[i]]++;  // Add the current element to the map
            map[nums[i-k]]--;  // Decrease the count of the element that is sliding out of the window

            if(map[nums[i-k]] == 0)  // If the count of the sliding-out element reaches 0
                map.erase(nums[i-k]);  // Remove the element from the map

            sum += nums[i];  // Add the current element to the sum
            sum -= nums[i-k];  // Subtract the element that is sliding out of the window

            if (map.size() == k)  // If the map still contains exactly k distinct elements
                ans = max(ans, sum);  // Update the result with the maximum sum

            i++;  // Move to the next element
        }

        return ans;  // Return the maximum sum found
    }
};

/*
Approach Summary:
- The problem asks to find the maximum sum of a subarray of length k with all distinct elements.
- We use a sliding window technique to keep track of the sum of the current window of size k.
- The unordered_map is used to count the frequency of each element in the window.
- Initially, we process the first k elements and check if all elements are distinct. If they are, we store the sum.
- Then, we slide the window to the right, adding a new element to the sum, removing the oldest element from the sum, and updating the map.
- If the map size is exactly k (indicating all elements in the window are distinct), we update the answer with the maximum sum found.

Complexity Analysis:
- Time Complexity: O(n), where n is the number of elements in the input array. Each element is added and removed from the unordered map at most once.
- Space Complexity: O(k), where k is the window size, as the unordered map stores at most k distinct elements at any point in time.
*/
