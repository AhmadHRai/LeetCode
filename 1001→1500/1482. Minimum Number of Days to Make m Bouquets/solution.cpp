class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size(); // Size of the bloomDay array
        
        // Check if it's possible to make m bouquets of k flowers
        if ((long long)m * k > n) {
            return -1; // If not possible, return -1
        }

        // Find the maximum and minimum bloom day in the array
        int mini = INT_MAX, maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            mini = min(mini, bloomDay[i]); // Update minimum bloom day
            maxi = max(maxi, bloomDay[i]); // Update maximum bloom day
        }

        // Perform binary search on the bloom days
        int low = mini, high = maxi;
        while (low <= high) {
            int mid = (low + high) / 2; // Calculate middle bloom day
            // Check if it's possible to make m bouquets with k flowers within mid days
            if (possible(bloomDay, mid, m, k)) {
                high = mid - 1; // If possible, try for earlier days
            } else {
                low = mid + 1; // If not possible, try for later days
            }
        }
        return low; // Return the minimum days found
    }

private:
    // Function to check if it's possible to make m bouquets of k flowers within 'day' days
    bool possible(vector<int> &arr, int day, int m, int k) {
        int n = arr.size(); // Size of the array
        int cnt = 0; // Counter for flowers bloomed within 'day' days
        int noOfB = 0; // Counter for number of bouquets formed
        
        // Count the number of bouquets that can be formed
        for (int i = 0; i < n; i++) {
            if (arr[i] <= day) {
                cnt++; // Increment the count of flowers bloomed within 'day' days
            } else {
                noOfB += (cnt / k); // Calculate number of bouquets that can be formed
                cnt = 0; // Reset flower count for the next section
            }
        }
        noOfB += (cnt / k); // Calculate bouquets from remaining flowers
        return noOfB >= m; // Return true if enough bouquets can be formed
    }
};

/*

Approach Summary:

To determine the minimum number of days required to bloom flowers such that m bouquets of k flowers each can be made, the solution employs binary search on the possible bloom days. Here’s how it works:

1. **Initial Check**: Ensures feasibility by checking if `(m * k)` is less than or equal to the total number of flowers (`n`). If not, it's impossible to form the required bouquets, hence returns `-1`.

2. **Binary Search**: Searches between the minimum and maximum bloom days (`mini` and `maxi`). For each middle day (`mid`), it checks if it's possible to form `m` bouquets of `k` flowers using the `possible` function.

3. **Feasibility Check (`possible` function)**: Counts how many flowers can be included within `day` days. It calculates the number of bouquets that can be formed from these flowers and checks if it meets or exceeds `m`.

4. **Adjustment**: Adjusts the search range (`low` and `high`) based on whether forming `m` bouquets of `k` flowers was possible with `mid` days.

5. **Result**: Returns the minimum number of days (`low`) found where it's possible to form the required bouquets.

Time Complexity:
- `minDays` function: O(n log(maxi - mini)), where `n` is the size of `bloomDay`.
- `possible` function: O(n).

Space Complexity: O(1) additional space.

*/
