// The class definition for the solution
class Solution {
public:
    // The function that takes an array of integers as input and returns the number of operations to make them equal
    int reductionOperations(vector<int>& nums) {
        // The size of the input array
        int n = nums.size();
        
        // A map that stores the frequency of each element in the array
        map<int, int> mp;
        // A loop that iterates over the array elements
        for(int i = 0; i < n; i ++) {
            // Incrementing the frequency of the current element by one
            mp[nums[i]] ++;             
        }
        
        // A variable that stores the answer, initialized to zero
        int ans = 0;
        // A variable that stores the previous frequency count, initialized to zero
        int pre = 0;
        // A loop that iterates over the map elements in reverse order (from largest to smallest key)
        for (auto i = mp.end(); i != mp.begin(); i--) {
            // Adding the current frequency plus the previous frequency to the answer
            ans += i -> second + pre;   
            // Updating the previous frequency to the current frequency
            pre += i -> second;         
        }
        // Returning the answer
        return ans;
    }
};

/* Reduction Operations to Make the Array Elements Equal

Approach:

The approach is based on the observation that the number of operations to reduce an element to the next largest element is equal to the frequency of that element plus the frequency of all the larger elements. For example, in the array [1,1,2,2,3], the number of operations to reduce 3 to 2 is 1 (the frequency of 3) plus 2 (the frequency of 2) which is 3. Similarly, the number of operations to reduce 2 to 1 is 2 (the frequency of 2) plus 2 (the frequency of 1) which is 4. Therefore, the total number of operations is 3 + 4 = 7.

Complexity:

The time complexity of this solution is O(n log n), where n is the size of the input array. This is because we need to sort the array elements by using a map, which takes O(n log n) time. The space complexity is O(n), where n is the size of the input array. This is because we need to store the frequency of each element in a map, which takes O(n) space. */

