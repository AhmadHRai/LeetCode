class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int last[128] = {}, res = 0;
        for (int i = 0; i < garbage.size(); ++i) {
            res += garbage[i].size();
            for (char c : garbage[i])
                last[c] = i;
        }
        for (int j = 1; j < travel.size(); ++j)
            travel[j] += travel[j - 1];
        for (int c : "PGM")
            if (last[c])
                res += travel[last[c] - 1];
        return res;
    }
};

/* 
Explanation

    Firstly sum up the amount of gabages in total.
    Second find up the last position for each type.
    Calculate the prefix sum array of the travel distance.
    Sum up the distance for each type of garbage.

Complexity

Time O((garbage * length of each garbage[i]) + travel)
Space O(1)
*/