class Solution {
public:
    // Backtracking function to find the itinerary
    void solve(unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& mp, string node, vector<string>& ans) {
        while (!mp[node].empty()) {
            string curr = mp[node].top();
            mp[node].pop();
            solve(mp, curr, ans);
        }

        ans.push_back(node); // Add the airport to the itinerary
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> mp;

        // Create a map of departure airport to a priority queue of arrival airports
        int n = tickets.size();
        for (int i = 0; i < n; i++) {
            mp[tickets[i][0]].push(tickets[i][1]);
        }

        vector<string> ans;
        solve(mp, "JFK", ans); // Start the backtracking from JFK
        reverse(ans.begin(), ans.end()); // Reverse the result to get the correct itinerary
        return ans;
    }
};

/* 
?Time Complexity:

    Constructing the map: O(N)
    Backtracking (solve function) is called at most once for each ticket, which means O(N) calls.
    In each call of the solve function, we potentially pop all the destinations for a given airport, which can be at most N destinations.
    Reversing the result: O(N)

Therefore, the overall time complexity is O(N + N + N) = O(N).

?Space Complexity:

    The map stores all the destinations for each airport. In the worst case, if every airport has a unique destination, this would be O(N).
    The recursive stack depth during backtracking can be at most N.
    The output vector stores the itinerary, which is also O(N).

Therefore, the overall space complexity is O(N + N + N) = O(N).

So, both time and space complexities are O(N).
 */