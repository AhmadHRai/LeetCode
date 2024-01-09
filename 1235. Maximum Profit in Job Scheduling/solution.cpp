class Solution {
public:
    
    // Declare a vector to store the maximum profit for each job index
    vector<int> cache;
    // Declare a variable to store the global maximum profit
    int res = 0;
    
    // This function takes three vectors of start time, end time, and profit of n jobs, and returns the maximum profit that can be obtained by scheduling the jobs without overlapping
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        // Get the number of jobs
        int n = startTime.size();
        // Create a 2D vector to store the jobs as {start time, end time, profit}
        vector<vector<int>> jobs(n);
        
        // Loop over the jobs and fill the 2D vector
        for (int i = 0; i < n; i++) {
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        }
        
        // Sort the jobs by their start time in ascending order
        sort(jobs.begin(), jobs.end());
        
        // Initialize the cache vector with -1 for each job index
        cache = vector<int>(n, -1);
        
        // Call the helper function with the first job index and update the global maximum profit
        helper(jobs, 0);
        // Return the global maximum profit
        return res;
    }
    
    // This helper function takes the 2D vector of jobs and a job index, and returns the maximum profit that can be obtained by scheduling the jobs from that index onwards
    int helper(vector<vector<int>>& jobs, int idx) {
        // If the job index is equal to the number of jobs, return 0 as the base case
        if (idx == jobs.size()) {
            return 0;
        }
        
        // If the cache vector has a non-negative value for the current job index, return that value as the memoized result
        if (cache[idx] != -1) {
            return cache[idx];
        }
        
        // If the current job is scheduled, then find the next job index that has a start time greater than or equal to the current job's end time using binary search
        int next_idx = find_next(jobs, jobs[idx][1]);
        // Add the current job's profit to the maximum profit obtained by scheduling the jobs from the next job index onwards
        int select = helper(jobs, next_idx) + jobs[idx][2];
        // If the current job is not scheduled, then move to the next job index and get the maximum profit obtained by scheduling the jobs from there onwards
        int not_select = helper(jobs, idx+1);
        
        // Store the maximum of the two options (select or not select) in the cache vector for the current job index
        cache[idx] = max(select, not_select);
        
        // Update the global maximum profit with the cache value for the current job index
        res = max(res, cache[idx]);
        
        // Return the cache value for the current job index
        return cache[idx];
    }
    
    // This function takes the 2D vector of jobs and a target time, and returns the next job index that has a start time greater than or equal to the target time using binary search
    int find_next(vector<vector<int>>& jobs, int t) {
        // Initialize the left and right pointers for binary search
        int l = 0, r = jobs.size();
        // Loop until the left pointer is equal to the right pointer
        while (l < r) {
            // Calculate the middle pointer
            int m = l + (r-l)/2;
            // If the middle job's start time is greater than or equal to the target time, move the right pointer to the middle
            if (jobs[m][0] >= t) {
                r = m;
            } 
            // Else, move the left pointer to the middle plus one
            else {
                l = m+1;
            }
        }
        
        // Return the left pointer as the next job index
        return l;
    }
    
};

/* 
Complexity Analysis:
    The time complexity is O(n log n), where n is the number of jobs. This is because the code uses sorting and binary search, which both have a time complexity of O (n log n) 
    in the worst case. The helper function also uses recursion, but it is memoized by the cache vector, so it only visits each job index once, which is O (n) in total.
    The space complexity is O(n), because the code uses a 2D vector and a cache vector, which both have a size of O (n) in the worst case. The helper function also uses 
    recursion, but the depth of the recursion is bounded by the number of jobs, which is O (n) in the worst case.
 */