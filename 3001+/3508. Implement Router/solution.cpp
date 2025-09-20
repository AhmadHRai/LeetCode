using int3 = tuple<int, int, int>; //(timestamp, source, destination)
const int N = 100000;
int3 q[N];
int front = 0, back = 0;

class Router {
public:
    unordered_map<int, pair<int, vector<int>>> byDest;
    unordered_set<long long> seen; // pack(source,dest)
    size_t memoryLimit;

    Router(size_t memoryLimit) : memoryLimit(memoryLimit) { front = back = 0; }

    long long pack(int x, int y) { return ((long long)x << 32) | y; }

    bool addPacket(int source, int destination, int timestamp) {
        if (front < back && timestamp == get<0>(q[back - 1])) {
            long long key = pack(source, destination);
            if (seen.count(key))
                return 0; // duplicate
        } else
            seen.clear(); // new timestamp batch, reset seen

        // If memory limit reached, remove oldest packet
        if (back - front == memoryLimit) {
            auto [t, s, d] = q[front++];

            auto& [head, qq] = byDest[d];
            if (head + 1 <= qq.size())
                head++;

            if (t == timestamp) // same timestamp with oldest packet
                seen.erase(pack(s, d));
        }

        // Add new packet
        q[back++] = {timestamp, source, destination};
        if (!byDest.count(destination))
            byDest[destination].first = 0;
        byDest[destination].second.push_back(timestamp);
        seen.insert(pack(source, destination));
        return 1;
    }

    vector<int> forwardPacket() {
        if (front == back)
            return {};
        auto [t, s, d] = q[front++];

        auto& [head, qq] = byDest[d];
        if (head + 1 <= qq.size())
            head++;

        if (get<0>(q[back - 1]) == t) // front & back have the same timestamp
            seen.erase(pack(s, d));

        return {s, d, t};
    }

    int getCount(int destination, int startTime, int endTime) {
        auto& [head, qq] = byDest[destination];
        // timestamps are sorted, use binary search
        auto itL = lower_bound(qq.begin() + head, qq.end(), startTime);
        auto itR = upper_bound(qq.begin() + head, qq.end(), endTime);
        return itR - itL;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */