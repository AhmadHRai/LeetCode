// This class defines a solution to the problem of finding the minimum number of buses
// required to reach a destination from a source stop
class Solution {
public:
    // This function takes a vector of vectors of integers representing the routes of buses,
    // an integer S representing the source stop, and an integer T representing the destination stop
    // It returns the minimum number of buses needed to reach T from S, or -1 if it is impossible
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        // This unordered map stores the mapping from each stop to the routes that pass through it
        unordered_map<int, vector<int>> to_routes;
        // This loop iterates over the routes vector and fills the to_routes map
        for (int i = 0; i < routes.size(); ++i)
            for (int j : routes[i])
                to_routes[j].push_back(i);
        // This queue stores the pairs of stops and the number of buses taken so far
        // It is used for performing a breadth-first search from the source stop
        queue<pair<int, int>> bfs;
        // This pair represents the source stop and zero buses taken
        bfs.push({S, 0});
        // This unordered set stores the stops that have been visited so far
        unordered_set<int> seen = {S};
        // This loop continues until the queue is empty or the destination is found
        while (!bfs.empty()) {
            // This pair represents the current stop and the number of buses taken so far
            int stop = bfs.front().first, bus = bfs.front().second;
            // This removes the front element from the queue
            bfs.pop();
            // This checks if the current stop is the destination
            if (stop == T)
                // If yes, then return the number of buses taken
                return bus;
            // This loop iterates over the routes that pass through the current stop
            for (int i : to_routes[stop]) {
                // This loop iterates over the stops in the current route
                for (int j : routes[i]) {
                    // This checks if the stop has not been visited before
                    if (seen.find(j) == seen.end()) {
                        // If yes, then mark it as visited and add it to the queue with one more bus taken
                        seen.insert(j);
                        bfs.push({j, bus + 1});
                    }
                }
                // This clears the current route to avoid revisiting it
                routes[i].clear();
            }
        }
        // If the loop ends without finding the destination, then return -1
        return -1;
    }
};

/* 
The time complexity of this function is O(n + m), where n is the number of stops and m is the number of routes. This is because the function loops through all the stops and routes 
once and performs constant time operations in each iteration.

The space complexity of this function is O(n + m), where n is the number of stops and m is the number of routes. This is because the function uses an unordered map, an unordered 
set, and a queue that can store at most n + m elements in total.
 */