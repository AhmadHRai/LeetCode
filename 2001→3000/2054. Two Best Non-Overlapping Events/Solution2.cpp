class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int size = events.size(), ans = 0, maxi = 0;

        // Sort the events by their start times
        sort(events.begin(), events.end());

        // Create a map to store the maximum profit achievable up to each event start time
        map<int, int> mp;

        // Iterate over the events in reverse order
        while (size--) {
            // Find the first event that ends before the current event starts
            auto it = mp.upper_bound(events[size][1]);

            // Update the maximum profit achievable up to this event's start time
            maxi = max(maxi, events[size][2]);

            // Store the maximum profit at the event's start time in the map
            mp[events[size][0]] = maxi;

            // If no earlier event ends before this one, just take the current event's profit
            if (it == mp.end())
                ans = max(ans, maxi);
            else
                // Otherwise, calculate the sum of this event's profit and the maximum profit
                // of non-overlapping events before it
                ans = max(ans, events[size][2] + it->second);
        }

        return ans;  // Return the maximum achievable profit
    }
};

/*
Approach:
1. First, sort the events based on their start time to make it easier to process them in order.
2. Use a `map` to store the maximum profit achievable at each event’s start time.
3. Iterate through the events from the end to the beginning (reverse order). For each event:
   - Find the first earlier event that ends before the current event starts using `map.upper_bound()`.
   - Track the maximum profit up to the current event’s start time.
   - For each event, check if there are no earlier non-overlapping events, in which case the maximum profit so far is just the current event’s profit.
   - If there are earlier events, calculate the profit from this event plus the best achievable profit from earlier events that don’t overlap with the current one.
4. Return the maximum achievable profit from either one or two events.

This solution uses dynamic programming with a greedy approach. The `map` stores the maximum profit that can be achieved up to each event’s start time, and the `upper_bound` function is used to find non-overlapping events efficiently.

Complexity Analysis:
- Time Complexity: O(n log n), where `n` is the number of events. Sorting the events takes O(n log n), and for each event, operations involving the `map` (like `upper_bound` and insertions) take O(log n) time.
- Space Complexity: O(n), due to the storage of events and the `map` data structure.
*/
