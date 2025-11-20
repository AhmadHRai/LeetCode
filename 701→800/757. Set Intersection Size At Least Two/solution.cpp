class Solution {
public:
    int intersectionSizeTwo(std::vector<std::vector<int>>& intervals) {
        // 1. Sort the intervals:
        // Primary key: End point (ascending)
        // Secondary key: Start point (descending)
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& X, const std::vector<int>& Y) {
            // Compare by end point (X[1] < Y[1])
            if (X[1] != Y[1]) {
                return X[1] < Y[1];
            }
            // Compare by start point (X[0] > Y[0]) for ties
            return X[0] > Y[0];
        });

        int count = 0;
        
        // a and b are the two largest points currently in the intersection set 'S' 
        // that satisfy all processed intervals. We maintain a < b.
        // Initialize to impossible values to trigger Case 3 for the first interval.
        int a = -1; 
        int b = -1;

        for (const auto& interval : intervals) {
            int L = interval[0];
            int R = interval[1];

            // Case 1: Fully Covered (L <= a < b)
            if (L <= a) {
                // Interval [L, R] already contains {a, b}. Intersection size >= 2.
                // Do nothing.
                continue;
            }

            // Case 2: One Point Covered (a < L <= b)
            if (L <= b) {
                // Interval [L, R] contains only {b}. Intersection size is 1.
                // We need 1 more point: R.
                count += 1;
                // Old 'b' becomes the new 'a'. New point R becomes the new 'b'.
                a = b;
                b = R; 
                // Note: The new 'a' is guaranteed to be < new 'b' since a < b <= R.
                continue;
            }

            // Case 3: Zero Points Covered (L > b > a)
            // Interval [L, R] contains neither {a} nor {b}. Intersection size is 0.
            // We need 2 new points: R-1 and R.
            count += 2;
            // R-1 becomes the new 'a'. R becomes the new 'b'.
            a = R - 1;
            b = R;
        }

        return count;
    }
};

/* 
    Time Complexity: O(N log N). The dominant part is the sorting, which takes O(NlogN), where N is the number of intervals. The subsequent greedy iteration is O(N).

    Space Complexity: 
        Auxiliary Space (Extra Space Used): O(1)
        Total Space (Including Input): O(N)
*/