class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        // Create a vector of pairs to store jobs with their difficulty and profit.
        vector<pair<int, int>> jobs;
        // Initialize variables: N is the number of jobs, res will store the total profit, i is an index for jobs, best is the best profit found so far.
        int N = profit.size(), res = 0, i = 0, best = 0;
        
        // Populate the jobs vector with pairs of (difficulty, profit).
        for (int j = 0; j < N; ++j)
            jobs.push_back(make_pair(difficulty[j], profit[j]));
        
        // Sort jobs based on difficulty (first element of the pair).
        sort(jobs.begin(), jobs.end());
        
        // Sort the worker abilities in ascending order.
        sort(worker.begin(), worker.end());
        
        // Iterate through each worker's ability.
        for (int & ability : worker) {
            // While there are jobs left and the worker's ability is sufficient for the current job,
            // update the best profit that can be achieved with the current ability.
            while (i < N && ability >= jobs[i].first)
                best = max(jobs[i++].second, best);
            
            // Add the best profit found for the current worker's ability to the total profit.
            res += best;
        }
        
        // Return the total profit achievable by all workers.
        return res;
    }
};

/*

Explanation

The `maxProfitAssignment` function calculates the maximum profit that can be achieved by assigning workers to jobs, given the difficulty and profit associated with each job.

Approach:
- Store jobs in a vector of pairs (difficulty, profit).
- Sort jobs by difficulty to ensure we process them in increasing order of difficulty.
- Sort worker abilities to process them in increasing order.
- Iterate through each worker's ability:
  - Use a while loop to find the best possible profit for the current worker's ability.
  - Update the best profit whenever a job's difficulty is within the worker's ability.
- Accumulate the best profit found for each worker.

Example:
If difficulty = [2, 4, 6, 8] and profit = [10, 20, 30, 40], and worker = [4, 5, 6, 7]:
- Sort jobs to [(2, 10), (4, 20), (6, 30), (8, 40)].
- Sort workers to [4, 5, 6, 7].
- For each worker:
  - For worker with ability 4: best profit = 20.
  - For worker with ability 5: best profit = 20.
  - For worker with ability 6: best profit = 30.
  - For worker with ability 7: best profit = 40.
- Total profit = 20 + 20 + 30 + 40 = 110.

Complexity:

Time Complexity:
- Sorting jobs and workers takes O(N log N), where N is the number of jobs or workers.
- Iterating through workers and jobs is O(N + K), where K is the total number of jobs.
- Overall, the time complexity is dominated by sorting, O(N log N).

Space Complexity:
- O(N) for storing jobs.
- O(1) extra space for variables.
- Overall, the space complexity is O(N).

*/

