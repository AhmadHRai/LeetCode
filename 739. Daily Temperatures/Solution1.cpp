class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        // support variables
        int len = t.size();
        stack<int> s;
        s.push(len - 1);
        vector<int> res(len);
        // looping from right to left, starting from the penultimate element
        for (int i = len - 2, n; i >=0; --i) {
            n = t[i];
            // removing all the indexes stacked before if they are smaller
            while (s.size() && n >= t[s.top()]) s.pop();
            // if we still have something in the stack, we update res
            if (s.size()) res[i] = s.top() - i;
            // updating the stack
            s.push(i);
        }
        return res;
    }
};

/* 
Approach

    This solution uses a stack to store the indexes of the elements in the array t, and a vector res to store the result.
    we loop through the array t from right to left, starting from the penultimate element.
    For each element, we pop the stack until we find an index that corresponds to a larger element than the current one, or the stack becomes empty.
    If the stack is not empty, we update the res vector with the difference between the top of the stack and the current index, which is the number of days until a warmer temperature.
    we push the current index to the stack and continue the loop.
    we return the res vector as the final answer.

Complexity
    Time complexity:
        The time complexity of this solution is O(n), where n is the size of the array t.
        This is because we loop through the array once, and for each element, we perform constant time operations on the stack and the res vector.
        The worst case scenario is when the array is sorted in ascending order, which means we have to pop the entire stack for each element. However, this does not affect the overall time complexity, as each element is pushed and popped at most once. Therefore, the total number of stack operations is O(n).
    Space complexity:
        The space complexity of this solution is O(n), where n is the size of the array t.
        This is because we use a stack and a vector of the same size as the array, which take O(n) space each.
        The stack can grow up to n elements in the worst case, when the array is sorted in descending order, which means we never pop the stack until the end.



 */