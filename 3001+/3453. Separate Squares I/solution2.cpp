#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    struct Event {
        long long y;
        long long width_delta;

        bool operator<(const Event& other) const {
            return y < other.y;
        }
    };

public:
    double separateSquares(const vector<vector<int>>& squares) {
        const int n = squares.size();
        vector<Event> events;
        events.reserve(2 * n); // Single contiguous allocation

        double total_area = 0;

        for (const auto& sq : squares) {
            long long y = sq[1];
            long long l = sq[2];

            total_area += (double)l * l;
            events.push_back({y, +l});     // Square starts: active width increases by l
            events.push_back({y + l, -l}); // Square ends: active width decreases by l
        }

        sort(events.begin(), events.end());

        double target_area = total_area / 2.0;
        double area_below = 0;
        long long active_width = 0;
        long long prev_y = events[0].y;

        for (const auto& event : events) {
            long long dy = event.y - prev_y;
            double slice_area = (double)active_width * dy;

            // If the target half-area falls inside this horizontal strip, interpolate exact y
            if (area_below + slice_area >= target_area) {
                double needed_area = target_area - area_below;
                return prev_y + (needed_area / active_width);
            }

            area_below += slice_area;
            active_width += event.width_delta;
            prev_y = event.y;
        }

        return prev_y;
    }
};
