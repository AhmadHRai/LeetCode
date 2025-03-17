class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_set<int> unpaired;

        for (int num: nums) {
            if(unpaired.count(num)) unpaired.erase(num);
            else unpaired.insert(num);
        }

        return unpaired.empty();
    }
};