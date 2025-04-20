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

// one loop, no performance difference
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> map;
        int res = 0;

        for(int i : answers) {
            if ( i == 0) res++;
            else {
                if(map[i] == 0) res += i + 1;
                map[i]++;
                if(map[i] == i + 1) map[i] = 0;
            }
        }

        return res;
    }
};