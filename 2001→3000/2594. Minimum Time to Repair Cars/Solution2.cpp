class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        // The minimum possible time is 1,
        // and the maximum possible time is when the slowest mechanic (highest
        // rank) repairs all cars.
        long long low = 1, high = 1LL * cars * cars * ranks[0];

        // Perform binary search to find the minimum time required.
        while (low < high) {
            long long mid = low + (high - low) / 2, carsRepaired = 0;

            // Calculate the number of cars that can be repaired in 'mid' time
            // by all mechanics.
            for (auto rank : ranks) carsRepaired += sqrt(1.0 * mid / rank);

            // If the total cars repaired is less than required, increase the
            // time.
            if (carsRepaired < cars)
                low = mid + 1;
            else
                high = mid;  // Otherwise, try a smaller time.
        }

        return low;
    }
};