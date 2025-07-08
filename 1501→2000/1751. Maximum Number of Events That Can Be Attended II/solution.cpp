class Solution {
public:
    static uint32_t maxValue(const std::span<const std::vector<int>> in_events,
                             const uint32_t k) {

        const uint32_t num_events = in_events.size();

        struct Event {
            uint32_t start_time;
            uint32_t end_time;
            uint32_t value;
        };

        Event events[num_events];

        for (uint32_t i = 0; i < num_events; ++i) {
            const auto& event = in_events[i];
            events[i] = Event{uint32_t(event[0]) - 1u, uint32_t(event[1]),
                              uint32_t(event[2])};
        }

        std::sort(events, events + num_events,
                  [](const Event& l, const Event& r) {
                      return l.start_time < r.start_time;
                  });

        const uint32_t height = num_events + 1;
        const uint32_t width = k + 1;
        uint32_t table[width * height];

        {
            const uint32_t y = height - 1;
            for (uint32_t x = 0; x < width; ++x)
                table[x + y * width] = 0;
        }

        for (uint32_t y = height - 2;;) {

            const Event& event = events[y];
            const uint32_t other_y =
                std::lower_bound(events + y + 1, events + num_events,
                                 event.end_time,
                                 [](const Event& l, const uint32_t r) {
                                     return l.start_time < r;
                                 }) -
                events;

            table[0 + y * width] = 0;

            for (uint32_t x = 1; x < width; ++x) {

                uint32_t max_value =
                    std::max(event.value, table[x + (y + 1) * width]);

                if (other_y < num_events) {
                    const uint32_t value =
                        event.value + table[x - 1 + other_y * width];
                    if (value > max_value)
                        max_value = value;
                }

                table[x + y * width] = max_value;
            }

            if (y == 0)
                break;
            --y;
        }

        return table[k + 0 * width];
    }
};