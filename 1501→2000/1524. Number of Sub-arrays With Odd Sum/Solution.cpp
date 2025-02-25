class Solution {
    public:
        int numOfSubarrays(vector<int>& arr) {
            const int MOD = 1e9 + 7; // Modulus to handle large results
            int count = 0;
            int prefixSum = 0;
            int oddCount = 0; // Count of prefix sums that are odd
            int evenCount = 1; // Count of prefix sums that are even (initially 1 for sum 0)
    
            // Iterate through the array
            for (int num : arr) {
                // Update the prefix sum
                prefixSum += num;
    
                // If the current prefix sum is even
                if (prefixSum % 2 == 0) {
                    // Add the number of odd subarrays to the count
                    count += oddCount;
                    evenCount++; // Increment the count of even prefix sums
                } else {
                    // If the current prefix sum is odd
                    // Add the number of even subarrays to the count
                    count += evenCount;
                    oddCount++; // Increment the count of odd prefix sums
                }
    
                // Apply modulus to handle large results
                count %= MOD;
            }
    
            return count;
        }
    }
    /*
    Approach Summary:
    This solution uses a prefix sum approach to efficiently count the number of subarrays with an odd sum. It maintains counts of prefix sums that are odd and even, leveraging the fact that a subarray has an odd sum if the prefix sums at its start and end have different parities.
    
    Complexity Analysis:
    - Time Complexity: O(N), where N is the number of elements in the array, because each element is processed once.
    - Space Complexity: O(1), excluding the input array, because only a constant amount of space is used.
    */
    