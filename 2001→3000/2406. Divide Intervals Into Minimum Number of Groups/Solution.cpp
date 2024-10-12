#include <vector>
#include <algorithm>

class Solution {
public:
    int minGroups(std::vector<std::vector<int>>& intervals) {
        // Vectors to store start and end times separately
        std::vector<int> start_times, end_times;

        // Extract start and end times from each interval
        for (const auto& interval : intervals) {
            start_times.push_back(interval[0]); // Add start time of current interval
            end_times.push_back(interval[1]);   // Add end time of current interval
        }

        // Sort start and end times independently
        std::sort(start_times.begin(), start_times.end());
        std::sort(end_times.begin(), end_times.end());

        int end_ptr = 0;      // Pointer to track the end times
        int group_count = 0;  // Counter for the minimum number of groups

        // Traverse through each start time
        for (int start : start_times) {
            // If current start time is greater than the smallest end time
            if (start > end_times[end_ptr]) {
                end_ptr++; // Move end pointer to next end time (interval ends)
            } else {
                // Increment group count if intervals overlap
                group_count++;
            }
        }

        return group_count; // Return the minimum number of groups required
    }
};

/*
Approach:
1. Extract and Sort Start and End Times:
   - We separate the start and end times from each interval into two separate vectors (`start_times` and `end_times`) and sort them independently. This allows us to handle the intervals by focusing on when they begin and end.

2. Two-Pointer Technique:
   - We use two pointers: `end_ptr` for `end_times` and another implicit pointer in the `start_times` traversal loop.
   - As we traverse each start time:
     - If the current start time is greater than the end time pointed to by `end_ptr`, it indicates that an interval has ended, allowing us to "reuse" a group. We then increment `end_ptr` to the next end time.
     - Otherwise, if the current start time is less than or equal to the end time at `end_ptr`, it implies an overlap. We need an additional group, so we increment `group_count`.

3. Return the Group Count:
   - By the end of the traversal, `group_count` will hold the minimum number of groups needed to accommodate all intervals without overlap.

Complexity Analysis:
- Time Complexity: O(n log n), where `n` is the number of intervals. Sorting the start and end times takes O(n log n), and the traversal of `start_times` is O(n).
- Space Complexity: O(n), for storing the start and end times separately.
*/
