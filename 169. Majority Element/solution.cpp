class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Create an unordered map to store the count of each element in the vector
        unordered_map<int, int> counter;
        // Loop over the vector of integers
        for (int num : nums) {
            // Increment the count of the current element in the map
            // If the count becomes more than half of the size of the vector, return the element
            if (++counter[num] > nums.size() / 2) {
                return num;
            }
        }
        // If no majority element exists, return 0
        return 0;
    }
};

/* 
    The time complexity of the code is O(n), where n is the size of the vector. This is because we need to loop over the vector once, and each operation on the unordered map is 
    constant time. 
    
    The space complexity of the code is O(m), where m is the number of distinct elements in the vector. This is because we need to store the count of each element in the 
    unordered map, which takes O(m) space.
 */