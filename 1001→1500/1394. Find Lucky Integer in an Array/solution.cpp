class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;

        for (int num: arr) freq[num]++;

        int res = -1; // fallback value

        for (auto& [key, value] : freq) {
            if(key == value) {
                res = max(res, key);
            }
        }

        return res;
    }
};