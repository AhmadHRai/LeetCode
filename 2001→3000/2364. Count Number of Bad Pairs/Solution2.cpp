class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
            long long int b = nums.size(); // Total number of elements
            long long int g = 0; // Count of good pairs
            long long int k = 0; // Count of consecutive equal differences
    
            // Transform the array to store differences between position and value
            for (int i = 0; i < b; i++) {
                nums[i] = i - nums[i];
            }
    
            // Sort the transformed array
            sort(nums.begin(), nums.end());
    
            // Count good pairs by grouping equal differences
            for (int i = 0; i < b - 1; i++) {
                if (nums[i] == nums[i + 1]) {
                    // Increment count of consecutive equal differences
                    k++;
                } else {
                    // Update count of good pairs using the formula for combinations
                    g += (k * (k + 1)) / 2;
                    k = 0;
                }
            }
            // Update count of good pairs for the last group of equal differences
            g += (k * (k + 1)) / 2;
    
            // Calculate the total number of bad pairs
            return (b * (b - 1)) / 2 - g;
        }
    }
    /*
    Approach Summary:
        This solution transforms the input array to store differences between each element's position and its value, sorts these differences, and then counts good pairs 
        by grouping equal differences. The total number of bad pairs is calculated by subtracting the count of good pairs from the total possible pairs.
    
    Complexity Analysis:
        Time Complexity: O(N log N), where N is the number of elements in the array, due to sorting.
        Space Complexity: O(1), as the input array is modified in-place.
    */
    