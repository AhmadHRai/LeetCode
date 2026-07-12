class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return {};

        vector<pair<int, int>> nums;
        nums.reserve(n);

        for (int i = 0; i < n; ++i)
            nums.emplace_back(arr[i], i);

        sort(nums.begin(), nums.end());

        vector<int> ranks(n);
        int rank = 1;
        ranks[nums[0].second] = rank;

        for (int i = 1; i < n; ++i) {
            if (nums[i].first != nums[i - 1].first)
                ++rank;

            ranks[nums[i].second] = rank;
        }

        return ranks;
    }
};
