class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();

        // Stack to store the maximum elements of each chunk
        stack<int> monotonicStack;

        for (int i = 0; i < n; i++) {
            // Case 1: Current element is larger, starts a new chunk
            if (monotonicStack.empty() || arr[i] > monotonicStack.top()) {
                monotonicStack.push(arr[i]);
            } else {
            // Case 2: Merge chunks
                int maxElement = monotonicStack.top();
                while (!monotonicStack.empty() &&
                       arr[i] < monotonicStack.top()) {
                    monotonicStack.pop();
                }
                monotonicStack.push(maxElement);
            }
        }
        return monotonicStack.size();
    }
};

/*
Approach:
    - This approach utilizes a monotonic stack to track the maximum elements of each chunk in the array.
    - As we iterate over the array, we push elements onto the stack when they are larger than the current top element (this indicates the start of a new chunk).
    - If the current element is smaller than the top of the stack, it means that we need to merge chunks. In this case, we pop elements from the stack until we find the correct position for the current element.
    - We then push the maximum element of the current chunk back onto the stack, ensuring that the stack holds the maximum elements of each chunk.
    - The number of chunks is equal to the number of elements in the stack at the end of the iteration.

    Complexity Analysis:
    - Time complexity: O(n)
      We iterate through the array once. Each element is either pushed onto the stack or popped from it. The total number of pops is bounded by the total number of elements, making the time complexity O(n).

    - Space complexity: O(n)
      In the worst case (when the array is in increasing order), the stack will contain all n elements, resulting in a space complexity of O(n).
*/
