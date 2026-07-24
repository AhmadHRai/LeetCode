class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int max_xor = 2048;

        vector<bool> pair_xor(max_xor, false);
        vector<bool> triplet_xor(max_xor, false);

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                pair_xor[nums[i] ^ nums[j]] = true;
            }
        }

        for (int x = 0; x < max_xor; x++) {
            if (!pair_xor[x]) continue;
            for (int v : nums) {
                triplet_xor[x ^ v] = true;
            }
        }

        int count = 0;
        for(int i = 0; i < max_xor; i++){
            if(triplet_xor[i]) count++;
        }

        return count;
    }
};
