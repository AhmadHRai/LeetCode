class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // Result array initialized to -1, as the default value
        vector<int> result(nums1.size(), -1);
        
        // Stack to help track elements for which we need to find the next greater element
        stack<int> stack;
        
        // HashMap to store the next greater element for each number in nums2
        unordered_map<int, int> nextGreaterMap;
        
        // Traverse nums2 to fill the nextGreaterMap with the next greater elements
        for (int num : nums2) {
            // Pop elements from the stack until we find a greater element
            while (!stack.empty() && stack.top() < num) {
                nextGreaterMap[stack.top()] = num;  // Store next greater element in map
                stack.pop();  // Pop from stack
            }
            stack.push(num);  // Push the current element onto the stack
        }
        
        // For each element in nums1, find the next greater element using the map
        for (int i = 0; i < nums1.size(); ++i) {
            if (nextGreaterMap.find(nums1[i]) != nextGreaterMap.end()) {
                result[i] = nextGreaterMap[nums1[i]];  // Set the next greater element
            }
        }
        
        return result;  // Return the result array
    }
};

/*
Approach:
    1) We will traverse the nums2 array to build a map of the next greater element for each element in nums2.
    
    2) We use a stack to keep track of elements from nums2 that we haven't found the next greater element for.
    
    3) While traversing nums2:
       - If the stack is not empty and the current element is greater than the element on top of the stack, 
         it means we found the next greater element for the top of the stack.
       - We pop elements from the stack and store the next greater element in a map.
    
    4) Once the nextGreaterMap is built, we loop through each element of nums1 and use the map to find its 
       next greater element.
    
    5) If an element in nums1 exists in the map, we return the corresponding next greater element; otherwise, 
       we keep the default value -1.

Complexity:
    Time complexity: O(n + m), where:
        - n is the size of nums2, as we traverse nums2 once to build the nextGreaterMap.
        - m is the size of nums1, as we loop through nums1 to build the result array.
        
    Space complexity: O(n), where n is the size of nums2:
        - We use a stack to keep track of elements from nums2, and the nextGreaterMap can store up to n elements.
*/
