#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    int smallestChair(std::vector<std::vector<int>>& times, int targetFriend) {
        int n = times.size(); // Number of friends

        // Create an order vector to store friend indices
        std::vector<int> order(n);
        for (int i = 0; i < n; ++i) order[i] = i;

        // Sort friends by arrival times using the order vector
        std::sort(order.begin(), order.end(), [&times](int a, int b) {
            return times[a][0] < times[b][0];
        });

        // Min-heap to track available chairs in ascending order
        std::priority_queue<int, std::vector<int>, std::greater<int>> emptySeats;
        // Min-heap to track occupied chairs and their leave times
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> takenSeats;

        // Initially, mark all chairs as available
        for (int i = 0; i < n; ++i) emptySeats.push(i);

        // Process each friend in the order of arrival
        for (int i : order) {
            int arrival = times[i][0]; // Arrival time of the current friend
            int leave = times[i][1];   // Leave time of the current friend

            // Free up chairs that have become available by the current friend's arrival time
            while (!takenSeats.empty() && takenSeats.top().first <= arrival) {
                emptySeats.push(takenSeats.top().second); // Make chair available
                takenSeats.pop();
            }

            // Assign the smallest available chair to the current friend
            int seat = emptySeats.top();
            emptySeats.pop();

            // If the current friend is the target, return the assigned chair
            if (i == targetFriend) return seat;

            // Mark the chair as taken with the friend's leave time
            takenSeats.push({leave, seat});
        }

        return -1;  // Return -1 if the target friend is not found (edge case)
    }
};

/*
Approach:
1. **Sorting Friends by Arrival Times**:
   - We first create an `order` vector to store indices of friends, which we sort based on arrival times (`times[i][0]`). This way, we can handle friends in the sequence they arrive.

2. **Tracking Available and Occupied Chairs**:
   - We use two priority queues:
     - `emptySeats`: a min-heap to track available chairs in ascending order. Each chair has an index from `0` to `n-1`.
     - `takenSeats`: a min-heap to track occupied chairs with pairs of leave times and chair indices. It helps free up chairs when a friend leaves.

3. **Assigning Chairs**:
   - For each friend:
     - Free up chairs for any friends who have left by the current friend's arrival time (based on `takenSeats`).
     - Assign the smallest available chair (from `emptySeats`) to the current friend.
     - If the current friend is the `targetFriend`, return the chair index immediately.
     - Otherwise, push the friend’s leave time and chair index into `takenSeats` to mark the chair as occupied until they leave.

4. **Edge Case**:
   - If the `targetFriend` is not found, return `-1`, though this is unlikely under normal conditions.

Complexity Analysis:
- **Time Complexity**: O(n log n), where `n` is the number of friends. Sorting takes `O(n log n)`, and each heap operation for `emptySeats` and `takenSeats` takes `O(log n)`, resulting in an overall complexity of `O(n log n)`.
- **Space Complexity**: O(n), as we store `n` indices in the `order` vector and use two priority queues with a maximum of `n` elements.
*/
