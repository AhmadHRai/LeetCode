class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int tally[100001]={0};
        long long smallest=asteroids[0], largest=asteroids[0], planet=mass;
        for(int i=0; i<asteroids.size(); i++){
            tally[asteroids[i]]++;
            smallest=min(smallest, static_cast<long long>(asteroids[i]));
            largest=max(largest, static_cast<long long>(asteroids[i]));
        }
        while(smallest<=largest){
            if(smallest>planet){
                return false;
            }
            planet+=smallest*tally[smallest];
            smallest++;
        }
        return true;
    }
};
