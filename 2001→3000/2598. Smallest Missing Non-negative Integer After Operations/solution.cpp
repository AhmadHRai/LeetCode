class Solution {
public:
	int findSmallestInteger(vector<int>& nums, int value) {
		long long n = nums.size(), x, res = 0;
		vector<int> rem(value, 0);
		for (int i = 0; i < n; i++) {
			x = ((nums[i] % value) + value) % value;
			rem[x]++;
		}

		while (rem[res % value]--) res++;
		return res;
	}
};