class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(nums[0]);
        int l = 1; // len = 1 as we pushed nums[0]

        // LOGIC : Create a temp array that adds elements if greater than the last element, and if not, overwrites smallest greater element.
        // NOTE : temp does not store the longest increasing subsequence, we are just utilizing the length of temp to get our answer.

        for(int i=1;i<nums.size();i++){
             // If nums[i] is greater, just add it at the back
            if(temp.back() < nums[i]){
                temp.push_back(nums[i]);
                l++;
            }

            // If not, just replace the smallest element greater than nums[i] with nums[i]
            else{ 
                int ind = lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin();
                // inbuilt c++ function to perform binary search O(log N) to search for the third parameter in the array or element just 
                // greater than it. Do - temp.begin() to get an integer index value
                temp[ind] = nums[i];
            }
        }
        return l;
    }
};

/* 
Complexity:
    Time : O(N * log N) - N binary searches of O(log N) each
    Space: O(N)
 */