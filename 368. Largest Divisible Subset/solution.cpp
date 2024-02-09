class Solution {
public:
    // This function takes a vector of integers and returns the largest subset of these integers such that each pair of numbers in the subset is divisible by the other
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // If the vector is empty, return the vector as the base case
        if(nums.size()==0){
            return nums;
        }
        // Sort the vector in ascending order
        sort(nums.begin(),nums.end());
        // Declare a variable to indicate whether 1 is in the vector or not
        int flag=1;
        // If the first element of the vector is 1, set the flag to 0
        if(nums[0]==1){
            flag=0;
        }
        // Otherwise, add 1 to the end of the vector and set the flag to 1
        else{
            nums.push_back(1);
            flag=1;
        }
        // Sort the vector again to make sure 1 is at the beginning
        sort(nums.begin(),nums.end());
        // Declare two variables to loop through the vector
        int i,j;
        // Declare a 2D array to store the size and the next index of the largest divisible subset ending with nums[i]
        int dp[nums.size()][2];
        // Loop through the vector from the end to the beginning
        for(i=nums.size()-1;i>=0;i--){
            // Initialize the size and the next index of the subset as 0 and i
            dp[i][0]=0;
            dp[i][1]=i;
            // Loop through the vector from i+1 to the end
            for(j=i+1;j<nums.size();j++){
                // If nums[j] is divisible by nums[i]
                if((nums[j]%nums[i])==0){
                    // If the size of the subset ending with nums[j] is larger than the size of the subset ending with nums[i]
                    if(dp[j][0]>dp[i][0]){
                        // Update the size and the next index of the subset ending with nums[i] as the same as the subset ending with nums[j]
                        dp[i][0]=dp[j][0];
                        dp[i][1]=j;
                    }  
                }
            }
            // Increment the size of the subset ending with nums[i] by 1
            dp[i][0]++;
        }
        // Set i to 0 as the starting index of the largest subset
        i=0;
        // Declare a vector to store the result
        vector<int> t;
        // Add nums[i] to the result
        t.push_back(nums[i]);
        // While the next index of the subset is not i
        while(dp[i][1]!=i){
            // Update i as the next index of the subset
            i=dp[i][1];
            // Add nums[i] to the result
            t.push_back(nums[i]);
            
        }
        // If the flag is 1, meaning 1 was added to the vector
        if(flag==1){
            // Remove 1 from the result
            t.erase(t.begin());
        }
        // Return the result
        return t;
        
    }
};

/* 
Approach:
    The code uses a dynamic programming approach to solve the problem of finding the largest divisible subset in a vector of integers. Dynamic programming is a technique that breaks 
    down a complex problem into smaller subproblems and stores the results of the subproblems to avoid recomputation. The code uses a 2D array to store the size and the next index of 
    the largest divisible subset ending with each element of the 
    vector. The code loops through the vector from the end to the beginning, and for each element, it finds the next element that is divisible by it and has the largest subset size. 
    The code then constructs the result by following the next indices of the subset from the beginning to the end. The code also handles the special case of 1 by adding it to the 
    vector if it is not present, and removing it from the result if it is not needed.

Complexity:
    The time complexity is O(n^2), where n is the size of the vector. This is because the code uses two nested loops to iterate over the vector, and performs constant-time operations 
    in each iteration.
    The space complexity is O(n), because the code uses a 2D array of size n to store the results of the subproblems, and a vector of size n to store the result.
 */