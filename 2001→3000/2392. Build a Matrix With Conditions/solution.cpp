class Solution {
public:
    // Topological sort using BFS (Kahn's algorithm)
    static vector<int> topo_sort(int k, vector<vector<int>>& conditions) {
        vector<int> deg(k + 1, 0); // Initialize in-degrees
        vector<vector<int>> adj(k + 1); // Adjacency list for the graph

        // Build the graph
        for (auto& edge : conditions) {
            int v = edge[0], w = edge[1];
            adj[v].push_back(w);
            deg[w]++;
        }

        queue<int> q;
        // Enqueue nodes with zero in-degree
        for (int i = 1; i <= k; i++) {
            if (deg[i] == 0) 
                q.push(i);
        }

        int count = 0;
        vector<int> ans;
        ans.reserve(k);
        while (!q.empty()) {
            int j = q.front();
            q.pop();
            ans.push_back(j);
            count++;
            // Process all adjacent nodes
            for (int k : adj[j]) {
                deg[k]--;
                if (deg[k] == 0) {
                    q.push(k);
                }
            }
        }

        if (count != k) return {}; // Graph has a cycle
        else return ans;
    }

    // Utility function to print a vector
    static void print(auto& c) {
        cout << "[";
        for (int x : c) {
            cout << x;
            if (x != c.back()) cout << ", ";
        }
        cout << "]\n";
    }

    static vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        // Get topological orders for rows and columns
        auto order_row = topo_sort(k, rowConditions);
        auto order_col = topo_sort(k, colConditions);

        // Uncomment for debugging
        // print(order_row);
        // print(order_col);

        if (order_row.empty() || order_col.empty())
            return {}; // Conflict in constraints

        vector<vector<int>> arr(k, vector<int>(k));
        // Find positions for each number 1 through k
        vector<int> pos_i(k + 1, -1), pos_j(k + 1, -1);
        for (int i = 0; i < k; i++) {
            pos_i[order_row[i]] = i;
            pos_j[order_col[i]] = i;
        }

        // Fill the matrix based on positions
        for (int x = 1; x <= k; x++)
            arr[pos_i[x]][pos_j[x]] = x;
        
        return arr;
    }
};

/*
Approach

    - **Topological Sorting**: Use BFS (Kahn's algorithm) to get the topological order of elements based on row and column constraints.
    - **Matrix Construction**: 
      - Determine the positions of each element in the matrix using the topological order.
      - Fill the matrix with the elements in their determined positions.
    - **Conflict Detection**: If either row or column topological sort fails (i.e., results in an empty vector), there is a conflict in constraints.

Complexity

    Time complexity: O(V + E), where V is the number of nodes (k) and E is the number of edges in the graph (number of constraints). This is due to the BFS traversal in the topological sort.

    Space complexity: O(V + E), for storing the adjacency list, in-degrees, and topological order.

The `init` block is used to optimize I/O operations but does not affect the core logic. It is set up to speed up input/output when used in competitive programming contexts.
*/
