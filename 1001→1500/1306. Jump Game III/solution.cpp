class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(start < 0 || start >= size(arr) || arr[start] < 0) return false;                  // out of bounds OR already visited ? return false
        arr[start] *= -1;       // mark as visited by making -ve
        return !arr[start] || canReach(arr, start + arr[start]) || canReach(arr, start - arr[start]);  // return true if arr[start] == 0 or recurse for both possible jumps
    }
};
