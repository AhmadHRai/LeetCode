class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> altitudes;
        int sum = 0;
        for (int i = 0; i < gain.size(); i++) {
            altitudes.push_back(sum);
            sum = sum + gain[i];
        }
        altitudes.push_back(sum);
        return *max_element(altitudes.begin(), altitudes.end());
    }
};
