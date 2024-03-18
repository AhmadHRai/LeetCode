class Solution {
public:
    int findMinArrowShots(std::vector<std::vector<int>>& points) {
        // Sort the balloons by their end coordinates
        std::sort(points.begin(), points.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[1] < b[1];
        });

        int arrowCount = 0; // Initialize the count of arrows to zero
        long long lastBurstPosition = -(1LL << 60); // Use a very small value to initialize the position of the last burst

        // Iterate over all balloons
        for (const auto& point : points) {
            int start = point[0], end = point[1]; // Extract start and end points of the balloon

            // If the start point of the current balloon is greater than the last burst position
            // it means a new arrow is needed
            if (start > lastBurstPosition) {
                ++arrowCount; // Increment the arrow count
                lastBurstPosition = end; // Update the last burst position with the end of the current balloon
            }
        }

        return arrowCount; // Return the total number of arrows needed
    }
};

/* 
Approach:

    Sort the balloons by their end coordinates: This step is crucial because it allows you to process the balloons in order of their end positions. This ensures that you can burst as 
    many balloons as possible with a single arrow.

    Initialize variables: You need to keep track of the number of arrows shot (arrowCount) and the position of the last arrow shot (lastBurstPosition). Initially, arrowCount is set to 
    0, and lastBurstPosition is set to a very small value (e.g., negative infinity) to ensure that the first balloon is always shot.

    Iterate through the sorted balloons: For each balloon, check if its start position is greater than the lastBurstPosition. If it is, this means that the current balloon does not 
    overlap with the previous ones, and you need to shoot a new arrow. Increment arrowCount and update lastBurstPosition to the end position of the current balloon.

    Return the total number of arrows: After iterating through all balloons, return the arrowCount, which represents the minimum number of arrows needed to burst all balloons.

Time Complexity

    Sorting: The primary operation in this solution is sorting the balloons by their end coordinates. The time complexity of sorting depends on the sorting algorithm used. If we use a comparison-based sorting algorithm like quicksort, mergesort, or heapsort, the time complexity is O(N log N), where N is the number of balloons.
    Iteration: After sorting, the algorithm iterates through the sorted balloons once to determine the minimum number of arrows needed. This operation has a time complexity of O(N).

Combining these operations, the overall time complexity of the solution is dominated by the sorting operation, making it O(N log N).
Space Complexity

    Sorting: The sorting operation requires additional space to store the sorted array. In the worst case, this space is proportional to the size of the input array, making the space complexity O(N).
    Additional Variables: The algorithm uses a few additional variables (arrowCount, lastBurstPosition) to keep track of the number of arrows and the last burst position. These variables do not depend on the size of the input and thus have a constant space complexity.

Therefore, the overall space complexity of the solution is O(N) due to the space required for sorting.

 */