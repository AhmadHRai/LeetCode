class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // Initialize an unordered set with all the deadends for quick lookup
        unordered_set<string> deadSet(deadends.begin(), deadends.end());
        // If the initial state "0000" is a deadend, return -1 as it's impossible to open the lock
        if (deadSet.count("0000")) return -1;
        // Use a queue to perform the BFS, starting with the initial state "0000"
        queue<string> q({"0000"});
        for (int steps = 0; !q.empty(); ++steps) {
            for (int i = q.size(); i > 0; --i) {
                auto curr = q.front(); q.pop();
                // If the current state is the target, return the number of turns taken to reach it
                if (curr == target) return steps;
                // Generate all possible neighboring states by incrementing or decrementing each digit by 1
                for (auto nei : neighbors(curr)) {
                    // If a neighboring state is not a deadend and has not been visited before, mark it as visited and enqueue it
                    if (deadSet.count(nei)) continue;
                    deadSet.insert(nei); // Marked as visited
                    q.push(nei);
                }
            }
        }
        // If the BFS completes without finding the target, return -1 as it's impossible to open the lock
        return -1;
    }
    vector<string> neighbors(const string& code) {
        vector<string> result;
        // Generate all possible neighboring states by incrementing or decrementing each digit by 1
        for (int i = 0; i < 4; i++) {
            for (int diff = -1; diff <= 1; diff += 2) {
                string nei = code;
                nei[i] = (nei[i] - '0' + diff + 10) % 10 + '0';
                result.push_back(nei);
            }
        }
        return result;
    }
};

/* 
Approach:

    We a breadth-first search (BFS) algorithm to find the minimum number of turns required to open the lock from the initial state "0000" to the target state. 

Time Complexity:

    The time complexity is primarily determined by the number of states that can be reached from the initial state and the number of deadends. In the worst case, this 
    could be O(10^4) for the number of states and O(D) for the number of deadends, where D is the number of deadends. The actual complexity depends on the distribution 
    of deadends and the target state.

Space Complexity:

    The space complexity is determined by the size of the queue and the unordered set used to store deadends. In the worst case, the queue could contain all possible 
    states, leading to a space complexity of O(10^4). The unordered set storing deadends has a space complexity of O(D).

This approach is efficient for solving the problem within the given constraints, as it systematically explores all possible states with a maximum number of turns and keeps track of visited states to avoid cycles.
*/