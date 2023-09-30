class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> s; // create a stack to store the second element of the pattern
        int third = INT_MIN; // initialize the third element of the pattern to the minimum integer

        for (int i = nums.size() - 1; i >= 0; i--) { // iterate from the end of the array
            if (nums[i] < third) return true; // if the current element is less than the third element, we have found the pattern
            while (!s.empty() && s.top() < nums[i]) { // while the stack is not empty and the top element is less than the current element
                third = s.top(); // update the third element to be the top element of the stack
                s.pop(); // pop the top element from the stack
            }
            s.push(nums[i]); // push the current element to the stack
        }
        return false; // if we reach here, we have not found the pattern
    }
};

/* The time complexity of this solution is O(n), where n is the length of the array, because we iterate through 
the array once and perform constant time operations in each iteration. 
The space complexity is O(n), because we use a stack that can potentially store all the elements of the array.
 */