class Solution {
public:
    // Using Two Pointers
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int low=0, high=nums.size()-1;

        while(low < high){
            if ((nums[low] + nums[high]) == 0) {
                return nums[high];
            }
            else if ((nums[low] + nums[high]) < 0) {
                low++;
            }
            else {
                high--;
            }
        }
        return -1;
    }

    /* 
    Approach:

        This solution sorts the array and then uses two pointers (low and high) to find a pair of numbers that sum up to 0.
        It iteratively adjusts the pointers based on the sum of the numbers at the current pointers' positions.

    Complexity:

        Time Complexity: O(n log n) due to the sorting operation, where n is the number of elements in nums.
        Space Complexity: O(1) as it does not use any additional space that scales with the input size.

    Efficiency:

        This approach is efficient for finding a pair that sums up to 0, especially when the array is large.
        However, it assumes that the maximum value k is the sum of two numbers in the array, which might not always be the case.
     */

    int findMaxK2(vector<int>& nums) {
        map<int,int,greater<int>> mp;
        for(auto i : nums)
            mp[i]++;
        for(auto i : mp) 
            if(mp.count(0-i.first)) 
                return i.first;
        return -1;
    }

    /* 
    Approach:

        This solution uses a hashmap to count the occurrences of each number in the array.
        It then iterates through the hashmap to find a pair of numbers that sum up to 0.

    Complexity:

        Time Complexity: O(n log n) due to the sorting of the hashmap (implicitly done by the map data structure), where n is the number of elements in nums.
        Space Complexity: O(n) as it uses a hashmap to store the occurrences of each number in the array.
    
    Efficiency:

        This approach is straightforward and easy to understand.
        However, it might be less efficient than the two-pointer approach, especially for large arrays, due to the overhead of sorting the hashmap and the potential for hash collisions.
    
    Comparison:
    
        Time Complexity: Both solutions have a time complexity of O(n log n), but the two-pointer approach is generally more efficient due to its direct application without the need for sorting the hashmap.
        Space Complexity: The two-pointer approach is more space-efficient, using O(1) space, while the hashmap approach uses O(n) space.
        Efficiency: The two-pointer approach is generally more efficient and is preferred for this problem, especially when the array is large. The hashmap approach, while simpler, might be less efficient due to the overhead of sorting the hashmap and potential hash collisions.
     */

};