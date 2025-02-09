class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
            long long badPairs = 0; // Count of bad pairs
    
            // Map to store the count of differences between position and value
            unordered_map<int, int> diffCount;
    
            for (int pos = 0; pos < nums.size(); pos++) {
                // Calculate the difference between position and value
                int diff = pos - nums[pos];
    
                // Get the count of good pairs for this difference
                int goodPairsCount = diffCount[diff];
    
                // Update the count of bad pairs
                badPairs += pos - goodPairsCount;
    
                // Increment the count for this difference
                diffCount[diff] = goodPairsCount + 1;
            }
    
            return badPairs;
        }
    }
    
    /*
    Approach Summary:
    This solution calculates the number of bad pairs by maintaining a count of differences between each element's position and its value. It iterates through the array, updating the count of bad pairs based on the number of good pairs for each difference.
    
    Complexity Analysis:
    - Time Complexity: O(N), where N is the number of elements in the array, because each element is visited once.
    - Space Complexity: O(N), for storing the counts of differences.
    */
    