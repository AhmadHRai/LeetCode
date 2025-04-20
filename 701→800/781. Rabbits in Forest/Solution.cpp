class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> map;
        for(int i : answers) {
            map[i]++;
        }

        int res = 0;
        for (auto i : map) {
            res += (i.second + i.first) / (i.first + 1) * (i.first + 1);
        }

        return res;
    }
};