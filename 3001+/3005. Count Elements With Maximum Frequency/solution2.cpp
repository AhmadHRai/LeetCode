class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int, int> F;
        for(int i: nums)
            F[i]++;
        
        vector<int> holder;
        for(auto i: F)
            holder.push_back(i.second);

        int mx = *max_element(holder.begin(), holder.end());
        int cnt=0;
        for(int i: holder)
            if(mx == i)
                cnt += mx;
        return cnt;
    }
};