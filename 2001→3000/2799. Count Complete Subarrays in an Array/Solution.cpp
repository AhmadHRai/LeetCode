class Solution {
public:
    int countCompleteSubarrays(vector<int>& A) {
        int count=0,n=A.size();
        int total_distinct = 0;
        for (int i = 0; i < n; i++) {
            bool found = false;
            for (int j = 0; j < i; j++) {
                if (A[i] == A[j]) {
                    found = true;
                    break;
                }
            }
            if(!found){
                total_distinct++;
            }
        }
        for (int i = 0; i < n; i++) {
            int distinct_in_subarray = 0;
            for (int j = i; j < n; j++) {
                bool found = false;
                for (int k = i; k < j; k++) {
                    if (A[j] == A[k]) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    distinct_in_subarray++;
                }
                 if (distinct_in_subarray == total_distinct) {
                    count++;
                }
            }
        }
        return count;
    }
};