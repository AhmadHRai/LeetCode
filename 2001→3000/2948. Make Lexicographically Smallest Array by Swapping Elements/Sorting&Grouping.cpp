class Solution {
    public:
        // Returns the lexicographically smallest array by replacing each element with the smallest in its group
        vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
            // Create a sorted copy of the input array
            vector<int> numsSorted(nums);
            sort(numsSorted.begin(), numsSorted.end());
    
            // Initialize variables for grouping
            int currGroup = 0;
            unordered_map<int, int> numToGroup; // Maps numbers to their group IDs
            numToGroup.insert(pair<int, int>(numsSorted[0], currGroup));
    
            unordered_map<int, list<int>> groupToList; // Maps group IDs to sorted lists of numbers
            groupToList.insert(
                pair<int, list<int>>(currGroup, list<int>(1, numsSorted[0])));
    
            // Group numbers based on the difference limit
            for (int i = 1; i < nums.size(); i++) {
                // If the difference between consecutive numbers exceeds the limit, start a new group
                if (abs(numsSorted[i] - numsSorted[i - 1]) > limit) {
                    currGroup++;
                }
    
                // Assign the current number to its group
                numToGroup.insert(pair<int, int>(numsSorted[i], currGroup));
    
                // Add the number to its group's sorted list
                if (groupToList.find(currGroup) == groupToList.end()) {
                    groupToList[currGroup] = list<int>();
                }
                groupToList[currGroup].push_back(numsSorted[i]);
            }
    
            // Replace each number in the original array with the smallest in its group
            for (int i = 0; i < nums.size(); i++) {
                int num = nums[i];
                int group = numToGroup[num];
                // Replace the current number with the smallest in its group
                nums[i] = *groupToList[group].begin();
                // Remove the used smallest number from the group list
                groupToList[group].pop_front();
            }
    
            return nums;
        }
    }
    /*
    Approach Summary:
    This solution involves sorting the input array and grouping numbers based on a difference limit. It then replaces each number in the original array with the smallest number 
    in its group, ensuring the resulting array is lexicographically smallest.
    
    Complexity Analysis:
    - Time Complexity: O(N log N), primarily due to sorting the array.
    - Space Complexity: O(N), for storing the sorted array and group mappings.
    */
    