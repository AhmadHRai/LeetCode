class Solution {
public:
    // Function to check if it's possible to run all computers for 'time' duration
    bool check(long long time, long long n, vector<int>& batteries) {
        long long availableTime = 0;

        // Calculate total available processing time from all batteries
        for (int battery : batteries) {
            // For each battery, we can use it for 'time' duration
            // But we can't use more than the battery's actual capacity
            // So we take the minimum of 'time' and the battery's capacity
            availableTime += min((long long)battery, time);
        }

        // Check if the total available time is enough for all 'n' computers
        // Each computer needs 'time' duration
        return availableTime >= n * time;
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        long long low = 1; // Minimum possible time is 1
        // Upper bound for time:
        // In the best case, all batteries sum up to a large number
        // The maximum time can't exceed the total sum of all batteries
        // divided by the number of computers
        long long high = 0;
        for (int battery : batteries) {
            high += battery;
        }

        long long ans = 0;

        // Binary search for the maximum possible time
        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (check(mid, n, batteries)) {
                // If 'mid' time is possible, it's a potential answer
                // Try for a larger time
                ans = mid;
                low = mid + 1;
            } else {
                // If 'mid' time is not possible, try for a smaller time
                high = mid - 1;
            }
        }

        return ans;
    }
};
