// #include <vector>

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i = 0;

        // Insert intervals ending before newInterval starts
        while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i++]);
        }

        // Merge all overlapping intervals with newInterval
        while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }

        // Insert the merged newInterval
        result.push_back(newInterval);

        // Insert the remaining intervals
        while (i < intervals.size()) {
            result.push_back(intervals[i++]);
        }

        return result;
    }
};

/* 
Approach:

    Initialization: Create a new vector result to store the final intervals. Initialize an index i to 0 to iterate through the intervals.

    Insert Non-Overlapping Intervals: Iterate through intervals and insert intervals that end before newInterval starts into result. This is done by comparing the end of the current 
    interval with the start of newInterval.

    Merge Overlapping Intervals: After inserting all non-overlapping intervals, merge newInterval with any intervals that overlap with it. This is done by updating newInterval to cover 
    the minimum start and maximum end of overlapping intervals.

    Insert Merged Interval: Once all overlapping intervals are merged into newInterval, insert newInterval into result.

    Insert Remaining Intervals: Finally, insert any remaining intervals from intervals that come after newInterval into result.

Complexity Analysis

    Time Complexity: O(n), where n is the number of intervals. This is because the algorithm iterates through the intervals once.
    Space Complexity: O(n), as in the worst case, all intervals might need to be stored in the result vector.
 */