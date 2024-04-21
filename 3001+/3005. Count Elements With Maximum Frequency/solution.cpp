class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        // Initialize an array to keep track of the frequency of each number in the range 0 to 100
        int freq[101]={0}, maxF=0;
        
        // Iterate over each number in the input array
        for (int x: nums){
            // Increment the frequency of the current number
            freq[x]++;
            // Update the maximum frequency found so far
            maxF=max(maxF, freq[x]);
        }
        
        // Initialize the result variable to 0
        int ans=0;
        
        // Iterate over the frequency array to find the sum of all elements with the maximum frequency
        for (int f: freq){
            // If the current frequency is equal to the maximum frequency, add it to the result
            if (f==maxF)
                ans+=f;
        }
        
        // Return the sum of all elements with the maximum frequency
        return ans;
    }
};

// This lambda function is used to initialize the I/O streams for faster input/output operations
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();



/* 
Approach Summary

    The code first initializes an array freq of size 101 (to accommodate numbers from 0 to 100) with all elements set to 0. This array will be used to count the frequency of each 
        number in the input array nums.
    It then iterates over nums, incrementing the count of each number in the freq array and updating maxF with the maximum frequency found so far.
    After finding the maximum frequency, it iterates over the freq array again to sum up the frequencies of all numbers that have the maximum frequency. This sum is stored in ans.
    Finally, it returns ans, which is the sum of all elements with the maximum frequency.

Time and Space Complexity Analysis

    Time Complexity: The time complexity is O(n + m), where n is the size of the input array nums and m is the size of the frequency array (101 in this case). This is because the code 
        iterates over nums once to count the frequencies and then iterates over the frequency array once to find the sum of all elements with the maximum frequency.
        
    Space Complexity: The space complexity is O(1), as the size of the frequency array is constant and does not depend on the size of the input array nums.

 */