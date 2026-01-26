class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> result;

        int mad = INT_MAX;

        // find minimum absolute difference
        for (int i = 0; i < arr.size() - 1; i++) {
            mad = min(arr[i + 1] - arr[i], mad);
        }

        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i + 1] - arr[i] == mad) {
                result.push_back({arr[i], arr[i + 1]});
            }
        }

        return result;
    }
};
