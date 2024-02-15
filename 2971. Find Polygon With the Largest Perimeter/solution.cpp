class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long sum = 0;
        long long ans = -1;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]<sum)ans = nums[i] + sum;
            sum+=nums[i];
        }
        
        return ans;
    }
};

/* 
Approach 2 ( With Forward Iteration ) 
// From https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/solutions/4729097/beats-100-c-java-python-javascript-2-approaches-explained

    Sort the array: Start by sorting the array of numbers in ascending order.

    Initialize variables: Set up variables to track the running sum (sum) and the largest perimeter found so far (ans).

    Iterate through the sorted array: Loop through each number in the sorted array.

    Check polygon condition: For each number, check if it's smaller than the sum of all previous numbers encountered.

    Update largest perimeter: If the condition is met, update ans with the sum of the current number and the running sum. Finally, return the largest perimeter found (ans).

Complexity

    Time complexity:
    O(nlogn)

    Space complexity:
    O(1)
 */