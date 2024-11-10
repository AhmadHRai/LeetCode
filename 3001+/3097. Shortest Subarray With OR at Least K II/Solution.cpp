class Solution {
private:
    void update(vector<int>& bits, int x, int change) {
        // insert or remove element from window, time: O(32)
        for (int i = 0; i < 32; i++) {
            if ((x >> i) & 1) {
                bits[i] += change;
            }
        }
    }
    
    int bitsToNum(vector<int>& bits) {
        // convert 32-size bits array to integer, time: O(32)
        int result = 0;
        for (int i = 0; i < 32; i++) {
            if (bits[i]) {
                result |= 1 << i;
            }
        }
        return result;
    }
    
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(), result = n + 1;
        vector<int> bits(32);
        for (int start = 0, end = 0; end < n; end++) {
            update(bits, nums[end], 1); // insert nums[end] into window
            while (start <= end && bitsToNum(bits) >= k) {
                result = min(result, end - start + 1);
                update(bits, nums[start++], -1); // remove nums[start] from window
            }
        }
        return result != n + 1 ? result : -1;
    }
};

/*
Approach: Sliding Window

    Using the strategy of removing element from window, can we use two pointers to keep track of current window?

    Suppose we want to find the minimum length special subarray ending at index end. We have our current window [0, end] (both inclusive) and it's bitwise OR array (of size 32) and bitwise OR value num.

    If num < k then we expand the window by [0, end + 1] by adding nums[end + 1] to the window. We keep doing it and once we reach a special subarray for which num >= k, then we have found one possible answer for some [0, end']. Now, in order to achieve minimum length, we can try to shrink the window from left side until the special condition num >= k is satisfied.

    Let's say, we shrunk the window as much as we could and reached a position [start' + 1, end'] where num < k (special condition became false). We know that the condition was true for window [start', end'] and hence we had found a possible answer end' - start' + 1 (size of window [start', end']).

    Therefore, when we will go to find the special subarray ending at index end' + 1, we will add nums[end' + 1] to the window, and we can safely start from start' + 1 itself instead of starting from complete 0. Because we have already found a possible answer end' - start' + 1, we will only check for sizes smaller than it.

    This gives the idea of using two pointers for sliding window.

Complexity

    Time complexity: O(n)
    Space complexity: O(32)≈O(1)

*/