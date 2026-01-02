class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        /*
        You are given an integer array nums with the following properties:

        nums.length == 2 * n.
        nums contains n + 1 unique elements.
        Exactly one element of nums is repeated n times.

        Return the element that is repeated n times.
        */
        int n = nums.size() / 2;
        set<int> seen;
        for (auto& num : nums) {
            if (seen.find(num) != seen.end()) {
                return num;
            }
            seen.insert(num);
        }

        return -1; // this should never be hit
    }
};
