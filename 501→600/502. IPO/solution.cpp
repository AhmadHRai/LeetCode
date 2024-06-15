#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();

        // Pair capital with profits
        vector<pair<int, int>> projects;
        for (int i = 0; i < n; ++i) {
            projects.push_back({capital[i], profits[i]});
        }

        // Sort projects by capital ascending (and by profit descending for ties)
        sort(projects.begin(), projects.end());

        // Use a max-heap (priority queue) to store profits of available projects
        priority_queue<int> maxProfitHeap;

        int idx = 0;
        for (int i = 0; i < k; ++i) {
            // Add all projects we can afford to the maxProfitHeap
            while (idx < n && projects[idx].first <= w) {
                maxProfitHeap.push(projects[idx].second);
                ++idx;
            }

            // If there are profitable projects, select the one with maximum profit
            if (!maxProfitHeap.empty()) {
                w += maxProfitHeap.top();
                maxProfitHeap.pop();
            } else {
                break; // No more projects we can afford
            }
        }

        return w;
    }
};

/* 
Explanation:

    Pairing and Sorting:
        We pair each project's capital requirement with its profit and sort based on capital (ascending order). Sorting ensures that we can greedily select projects in a straightforward manner.

    Max-Heap (Priority Queue):
        We maintain a max-heap (maxProfitHeap) to efficiently retrieve the maximum profit project that we can afford at each step.

    Selection Process:
        Iterate k times to select up to k projects.
        Add projects to maxProfitHeap as long as their capital requirement is within our budget (w).
        Select the project with the maximum profit from maxProfitHeap and update w.
        Continue until k projects are selected or no more projects can be undertaken.

Complexity:

    Time Complexity:
        Sorting takes O(n log n) time.
        Each of the k iterations involves operations on the heap, each of which takes O(log n) time.
        Overall time complexity is dominated by the sorting operation, O(n log n).

    Space Complexity:
        O(n) for storing the pairs of (capital, profit) and the max-heap.
 */