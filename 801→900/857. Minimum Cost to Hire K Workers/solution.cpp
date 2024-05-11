class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        // flexing:
        ios_base::sync_with_stdio(false); // Disable synchronization with C++ standard streams for performance
        cin.tie(nullptr); // Disable buffering of input
        cout.tie(nullptr); // Disable buffering of output

        vector<pair<double, int>> ratio; // Vector to store wage-to-quality ratio and worker index
        int n = quality.size(); // Number of workers

        // Calculate wage-to-quality ratio for each worker and store it along with the worker index
        for (int i = 0; i < n; ++i) {
            ratio.emplace_back(static_cast<double>(wage[i]) / quality[i], i);
        }
        
        // Sort workers based on wage-to-quality ratio
        sort(begin(ratio), end(ratio));
        priority_queue<int> maxHeap; // Priority queue (max heap) to keep track of highest quality workers
        int qualitySum = 0; // Sum of qualities of workers hired
        double maxRate = 0.0; // Maximum wage-to-quality ratio of workers hired

        // Hire the first k workers
        for (int i = 0; i < k; ++i) {
            qualitySum += quality[ratio[i].second]; // Add worker's quality to sum
            maxRate = max(maxRate, ratio[i].first); // Update maximum wage-to-quality ratio
            maxHeap.push(quality[ratio[i].second]); // Add worker's quality to max heap
        }

        // Calculate initial cost
        double res = maxRate * qualitySum;

        // Iterate through remaining workers to potentially replace lowest quality worker
        for (int i = k; i < n; ++i) {
            maxRate = max(maxRate, ratio[i].first); // Update maximum wage-to-quality ratio
            qualitySum -= maxHeap.top(); // Remove lowest quality worker from sum
            maxHeap.pop(); // Remove lowest quality worker from max heap

            qualitySum += quality[ratio[i].second]; // Add new worker's quality to sum
            maxHeap.push(quality[ratio[i].second]); // Add new worker's quality to max heap
            res = min(res, maxRate * qualitySum); // Update minimum cost
        }

        return res; // Return minimum cost to hire k workers
    }
};

/* 
Approach Summary:
    The solution employs a combination of sorting and a priority queue (max heap) to minimize the cost of hiring k workers. The workers are first sorted based on their 
    wage-to-quality ratio, ensuring that the cheapest workers who meet the desired quality are considered first. A priority queue is used to keep track of the highest 
    quality workers hired up to that point. The algorithm starts by hiring the first k workers based on the sorted wage-to-quality ratio, then iterates through the remaining 
    workers to see if any can replace the lowest quality worker already hired with a better one, effectively reducing the cost. The minimum cost is calculated after each 
    replacement using the updated quality sum and the highest wage-to-quality ratio of all employees hired so far.

Time and Space Complexity Analysis:
    Time Complexity: O(n log n) due to sorting the workers based on their wage-to-quality ratio.
    Space Complexity: O(n) for storing the workers' information in a vector and the priority queue.

 */