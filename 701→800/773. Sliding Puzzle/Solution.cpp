#include <vector>
#include <queue>
#include <bitset>
#include <utility>

using namespace std;

class Solution {
public:
    static int slidingPuzzle(vector<vector<int>>& board) {
        // The target configuration (goal state) in octal
        int target = 0123450;

        // Initial state
        int start = 0;
        int zeroPos = -1;

        // Shift array to represent positions of board tiles
        int shift[6] = {15, 12, 9, 6, 3, 0};
        
        // Adjacency list: possible moves for each tile position
        vector<vector<char>> adj = {
            {1, 3},       // Position 0 can move to 1 or 3
            {0, 2, 4},    // Position 1 can move to 0, 2, or 4
            {1, 5},       // Position 2 can move to 1 or 5
            {0, 4},       // Position 3 can move to 0 or 4
            {1, 3, 5},    // Position 4 can move to 1, 3, or 5
            {2, 4}        // Position 5 can move to 2 or 4
        };

        // Convert the board to the initial state value
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                int index = i * 3 + j;
                start += (board[i][j] << shift[index]);
                if (board[i][j] == 0) {
                    zeroPos = index;
                }
            }
        }

        // If the board is already in the target state, return 0
        if (start == target) {
            return 0;
        }

        // Maximum possible states (the number of distinct configurations of the board)
        const int MAX_STATES = 0543211; // octal value for all possible configurations

        // A bitset to mark visited states
        bitset<MAX_STATES> visited;

        // Queue to perform BFS, stores pairs of the current state and the position of 0
        queue<pair<int, char>> q;
        q.emplace(start, zeroPos);

        // BFS to find the shortest path to the target state
        for (int moves = 0; !q.empty(); moves++) {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                auto [state, zeroPos] = q.front();
                q.pop();

                // If the current state matches the target state, return the number of moves
                if (state == target) {
                    return moves;
                }

                // Try all possible moves from the current position of 0
                for (char nextPos : adj[zeroPos]) {
                    int newState = state;
                    int shiftAmount = shift[nextPos];
                    int x = ((newState >> shiftAmount) & 7);

                    // Swap the 0 position with the tile at the next position
                    newState += -(x << shiftAmount) + (x << shift[zeroPos]);

                    // If this new state has already been visited, skip it
                    if (visited[newState]) {
                        continue;
                    }

                    // Mark the new state as visited and add it to the queue
                    q.emplace(newState, nextPos);
                    visited[newState] = 1;
                }
            }
        }

        // If no solution is found, return -1
        return -1;
    }
};

/*
Approach:

    This solution uses **Breadth-First Search (BFS)** to find the shortest path from the initial configuration of the sliding puzzle to the target state `012345`, where `0` 
    represents the empty space. 

    We represent the puzzle's state as a single integer, encoding the 2x3 grid into a 6-digit number, with each digit representing a tile. The empty space (0) is tracked 
    separately. The possible moves of the empty space are stored in an adjacency list, which describes the neighboring positions it can swap with.

    The BFS explores all possible board configurations by pushing states into a queue and trying all valid moves for the empty space. A **bitset** is used to mark visited 
    states and avoid revisiting them. The process continues until the target configuration is found, returning the number of moves. If no solution is found, `-1` is returned.

    Step by step:
        1. This solution uses the **Breadth-First Search (BFS)** algorithm to find the shortest path from the initial configuration of the sliding puzzle to the target configuration.
        2. The sliding puzzle is a 2x3 board with numbered tiles (0 represents the empty space) and the goal is to move the tiles until the board matches the target configuration `012345` (where 0 is the empty space).
        3. We represent the board state as an integer, where each 3x2 board configuration is encoded into a single 6-digit number. Each digit corresponds to the value of a tile at that position, and the empty space is denoted by `0`.
        4. The positions on the board are mapped to a linear array of 6 positions (0 to 5). The `shift` array helps to extract the value at any given position in the board state.
        5. An **adjacency list** `adj` is created to represent possible moves for the empty space (0). The empty space can swap with neighboring tiles in the board according to the puzzle rules.
        6. The algorithm starts by converting the 2D board into a single integer (`start`) that represents the initial state of the board. The position of the empty space (`0`) is also noted.
        7. **BFS** is used to explore all possible board configurations. Each state is pushed into a queue along with the current position of the empty space. For each state, we try all valid moves of the empty space and push the resulting new states into the queue.
        8. We keep track of visited states using a **bitset** to avoid processing the same state multiple times.
        9. The BFS continues until either the target configuration is reached, in which case the number of moves taken is returned, or all possible configurations are explored without finding a solution (return `-1` if no solution is found).

Complexity:
    Time Complexity:
    - The maximum number of possible board configurations is 3! (for tile positions), resulting in 720 distinct states.
    - Each state has at most 4 neighbors (as the empty space can move to at most 4 adjacent positions), and BFS explores each state once.
    - The BFS will thus run in O(V + E), where V is the number of distinct states (720) and E is the number of possible transitions (up to 4 transitions per state).
    - Overall time complexity: O(720), which is constant since the number of distinct states is fixed.

    Space Complexity:
    - We use a bitset to track visited states, which requires O(720) space.
    - The BFS queue stores up to 720 states in the worst case.
    - The space complexity is O(720) for storing states, visited states, and the queue.
*/
