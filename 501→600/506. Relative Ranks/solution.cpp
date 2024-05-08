class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        unordered_map<int,int> mp;

        vector<string> ans(n);

        // Populate the map with scores as keys and their indices as values
        for(int i=0; i<n; i++) {
            mp[score[i]] = i;
        }

        // Sort the scores in descending order
        sort(score.begin(), score.end(), greater<int>());

        // Assign ranks to each score based on their sorted order
        for(int i=0; i<n; i++) {
            if(i==0) ans[mp[score[i]]]="Gold Medal";
            else if(i==1) ans[mp[score[i]]]="Silver Medal";
            else if(i==2) ans[mp[score[i]]]="Bronze Medal";
            else ans[mp[score[i]]]=to_string(i+1);
        }

        return ans;
    }
};

/* 
Approach:

    This solution first creates a map where each score is associated with its index in the original array. It then sorts the scores in descending order. After sorting, it 
    iterates through the sorted scores and assigns ranks to each score based on their position in the sorted array. The rank is stored in the `ans` vector at the index 
    corresponding to the original position of the score in the input array.

Complexity:

    Time Complexity: O(n log n) due to the sorting operation, where n is the number of scores.
    Space Complexity: O(n) for storing the scores and their indices in the map, and for the `ans` vector.
*/