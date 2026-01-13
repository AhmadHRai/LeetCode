#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    struct Square {
        double y;
        double l;
    };

public:
    double separateSquares(const vector<vector<int>>& squares) {
        const int n = squares.size();
        vector<Square> flat_squares(n);

        double low = 2e9;
        double high = 0;
        double total_area = 0;

        // 1. Flatten input once for L1/L2 CPU cache locality
        for (int i = 0; i < n; ++i) {
            double y = squares[i][1];
            double l = squares[i][2];

            flat_squares[i] = {y, l};
            total_area += l * l;
            low = min(low, y);
            high = max(high, y + l);
        }

        double half_area = total_area / 2.0;

        // 2. Helper lambda: calculates area below `line_y`
        auto area_below = [&](double line_y) {
            double area = 0;
            for (const auto& sq : flat_squares) {
                double submerged_height = clamp(line_y - sq.y, 0.0, sq.l);
                area += submerged_height * sq.l;
            }
            return area;
        };

        // 3. Fixed 55 iterations shrinks range by 2^55 (~3.6e16), well past 1e-5 precision
        for (int iter = 0; iter < 55; ++iter) {
            double mid = low + (high - low) * 0.5;
            if (area_below(mid) >= half_area) {
                high = mid;
            } else {
                low = mid;
            }
        }

        return low;
    }
};
